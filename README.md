# CS253 : Car Rental System
The assignment implements a Car Rental System in C++ using object-oriented programming paradigms. The code is present in [main.cpp](main.cpp). There are 3 kinds of users, each with different functionalities and specifications. They are outlined in the [Problem Statement](Problem_statement.pdf). All functionalities of the statement have been implemented accordingly. There are 4 CSV files which serve as databases:

+ [`user_data.csv`](user_data.csv) stores [name, id, password, user_record, user_type]. User type '1' for Customer, '2' for Employee, and '3' for Manager.
+ [`car_data.csv`](car_data.csv) stores the details of the cars available for rent. This file stores the attributes [Name of the Car, Model, Condition, ID, Rent, is_issued]. The `is_issued` field is 1 if the car is rented by a user and 0 otherwise. One row in the file stores the data of one car.
+ [`rented_car.csv`](rented_car.csv) stores [Car Name, ID of the Car, Condition, User ID (Who rented the Car), Rent, timestamp, Number of Days rented]. The `timestamp` stores the time when the user rented it. The timestamp will help us later in calculating the fine and due date for users.
+ [`rent_record.csv`](rent_record.csv) stores [User ID (Who rented the Car), Rent amount, User type]. User type is used for detecting the type of user (Customer or Employee) so that the rent amount will have a 15% discount for employees.

### Assumptions:
1. A user can rent a maximum number of cars as $(int)(userRecord / 100)$. The `user_record` will be updated as `user_record = user_record + (Condition - 5) * 20 + Fine * 10`.
2. The condition of the car is given on a scale of 10 by the user based on the car's condition. If `Condition > 5`, the `user_record` will increase as per the calculation and decrease if it is less than 5.
3. Calculation of `Fine = 2 * (num)`, where `num` is the number of extra days after the due day.
4. No need to choose your role; it will be detected automatically from the database based on your ID.





To run the system, type the following commands in the console:
``` 
g++ main.cpp -o main
.\main

There will be already data of 5 Customer,5 Employee,5 Cars and 1 Manager in Database. you can add extra data to it.
When adding a Customer its Customer_record will automitaclly will be 380 (which is average of 5 Customer). similary 390 for new Employee.

