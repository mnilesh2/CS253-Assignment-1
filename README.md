# CS253 : Car Rental System

The assignment implements a Car Rental System in c++ using object oriented programming paradigms. The Code is present in [main.cpp](main.cpp). There are 3 kinds of users and each of them have different functionalities and specifications. They are outline in the [Problem Statement](Problem_statement.pdf). All functionalities of the statement have been implemented accordingly. There are 3 csv files which serve as databases.
+ [`user_data.csv`](user_data.csv) stores [name,id,password,user_record,user type]. user type '1' for Customer,'2' for Employee and '3' for Manager.
+ [`car_data.csv`](car_data.csv) stores the details of Car that is to be rented. This file stores the attributes [Name of the Car,Model,Condition,ID,Rent,is_issued]. The `is_issued` field is 1 if Car is rented by user and zero otherwise. One row in the file stores the data of one Car.
+ [`rented_car.csv`](rented_car.csv) stores [Car Name,Id of the Car, Condition,user Id (Who rented the Car),Rent,timestamp,No of Days rent for].  `timestamp` stores the time when the user rent it. The timestamp will help us later in calculating the fine and due date for users.
+ [`rent_record.csv`](rent_record.csv) stores [user Id (Who rented the Car),Rent amount,User type]. User type for detecting type of user(Customer or Employee) so that rent ammount will be 15% discount for employee.
+ Assumption : <br>
(1) User Can Rent Max no of Car is $(int)(userRecord/100)$ . And user_record will be updated as user_record = $user_record + (Condition - 5)*20 + Fine*10 $. <br>
(2) Condition is given on the scale of 10 by the user based on the Condition of the Car. if $Condition >5$ User_record will inclease as per as calculation and decrease if less than 5.<br>
(3) Calculation of $Fine = 2*(num)$ where $num$ is No of extra days after Due day.<br>
(4) No need to Choose your role it will detect automatically from Data base used on your ID.





To run the system, type the following commands in the console:
``` 
g++ main.cpp -o main
.\main

There will be already data of 5 Customer,5 Employee,5 Cars and 1 Manager in Database. you can add extra data to it.
When adding a Customer its Customer_record will automitaclly will be 380 (which is average of 5 Customer). similary 390 for new Employee.
