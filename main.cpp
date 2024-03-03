#include <bits/stdc++.h>
#include <chrono>

using namespace std;

vector<vector<string>> content;
vector<string> toupdate;

void readfile(string fname)
{ // reference : https://java2blog.com/read-csv-file-in-cpp/
    vector<string> row;
    string line, word;

    fstream data(fname, ios::in);
    if (data.is_open())
    {
        while (getline(data, line))
        {
            row.clear();
            stringstream str(line);
            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";
}
void writefile(vector<vector<string>> par, string fname)
{
    fstream fout(fname, ios::out);
    for (auto x : par)
    {
        for (auto y : x)
        {
            fout << y;
            if (y != x.back())
                fout << ",";
        }
        fout << "\n";
    }
}

void writefileappend(vector<string> par, string fname)
{
    fstream fout(fname, ios::out | ios::app);
    for (auto x : par)
    {
        fout << x;
        if (x != par.back())
            fout << ",";
    }
    fout << "\n";
}

void printdata(vector<vector<string>> par)
{
    int c = 1;
    for (auto x : par)
    {
        cout << c << ". ";
        for (auto y : x)
        {
            cout << y;
            if (y != x.back())
                cout << " | ";
        }
        c++;
        cout << "\n";
    }
}
void printdata_notpassword(vector<vector<string>> par)
{
    int c = 1;
    cout << "Name | ID | User Record | " << endl;
    for (auto x : par)
    {
        cout << c << ". ";
        cout << x[0] << " | " << x[1] << " | " << x[3] << "\n";
        c++;
    }
}

class User
{
private:
    string pass;

public:
    string name;
    string id;
    void display_menu();
    void login();
    void display_user_menu(string id);
    void display_manager_menu(string id);
    void display_cars(string id);
    void see_rented_cars(string id);
    void rented_cars(string id);
    void check_available(string id, string Name);
    int calculate_fine(string id);
    void return_cars(string id, string Car_id);
    void clear_fine_amount(string id);
    void logout();
    void User_add(string id);
    void User_update(string id);
    void User_delete(string id);
    void User_search(string id);
    int User_record(string id);
    void rent_record(string id, string id_car);
};
class Car
{
public:
    string Name;
    string Model;
    string id;
    int is_rented;
    void Car_request(string id);
    void Show_duedate(string id);
    void Car_add(string id);
    void Car_update(string id);
    void Car_delete(string id);
    void Car_search(string id);
};
class Customer : public User
{
public:
    // void display_customer_menu(string id);
    // void Customer_record();
    friend class Employee;
};

class Employee : public User
{
public:
    // void display_customer_menu(string id);
    // void Employee_record();
};

class Manager : public User
{
public:
    // void display_manager_menu(string id);

    void see_all_users(string id);
    void see_all_cars(string id);
    void add_user(string id);
    void update_user(string id);
    void delete_user(string id);
    void add_Car(string id);
    void update_Car(string id);
    void delete_Car(string id);
    void see_rented_to_user(string id, string Name);
    // void User_add(string id);
    void see_rented_car(string id, string user_id);
};
void User::display_user_menu(string id)
{
    cout << "**************************************************************************\n";
    cout << "\nYou have been logged in \n";
    cout << " 1 See all availables Car\n";
    cout << " 2 View Car rented by you\n";
    cout << " 3 Check if a car is available for rent or not\n";
    cout << " 4 View the fine\n";
    cout << " 5 Rent a Car\n";
    cout << " 6 Return a Car\n";
    cout << " 7 Clear your Dues\n";
    cout << " 8 Exit\n";
    cout << "**************************************************************************\n";
    char choice;
    cin >> choice;
    string Car_name, Car_id, cr_id;

    User user;
    Car car;
    switch (choice)
    {
    case '1':
        user.display_cars(id);
        user.display_user_menu(id);
        break;
    case '2':
        user.see_rented_cars(id);
        user.display_user_menu(id);
        break;
    case '3':
        cout << "Enter the Id of the Car want to check : ";
        cin >> cr_id;
        user.check_available(id, cr_id);
        user.display_user_menu(id);
        break;
    case '4':
        user.calculate_fine(id);
        user.display_user_menu(id);
        break;
    case '5':
        car.Car_request(id);
        user.display_user_menu(id);
        break;
    case '6':
        cout << "Enter the id of the Car you want to return : ";
        cin >> Car_id;
        user.return_cars(id, Car_id);
        user.display_user_menu(id);
        break;
    case '7':

        user.clear_fine_amount(id);
        user.display_user_menu(id);
        break;
    case '8':
        logout();
        break;
    default:
        cout << "Inter Valid Choice" << endl;
        user.display_user_menu(id);
        break;
    }
};

void User::display_manager_menu(string id)
{
    cout << "---------------------------------------------------------------------\n";
    cout << "\nWelcome " << id << "! You are logged in as Manager.\n\n";
    cout << " 1 Add a user\n";
    cout << " 2 Update a user\n";
    cout << " 3 Delete a user\n";
    cout << " 4 Add a Car\n";
    cout << " 5 Update a Car\n";
    cout << " 6 Delete a Car\n";
    cout << " 7 To see the car rented to a particular user\n";
    cout << " 8 See which Car is rented to which user\n";
    cout << " 9 View all users\n";
    cout << " 0 View all Cars\n";
    cout << " D Show due date of a Car\n";
    cout << " E Exit\n";
    cout << "---------------------------------------------------------------------\n";
    char choice;
    cout << "Enter your choice: ";
    cin >> choice;
    Manager manager;
    Car car;
    User u;
    string user_id, car_id;
    switch (choice)
    {
    case '1':
        u.User_add(id);
        manager.display_manager_menu(id);
        break;
    case '2':
        u.User_update(id);
        manager.display_manager_menu(id);
        break;
    case '3':
        u.User_delete(id);
        manager.display_manager_menu(id);
        break;
    case '4':
        car.Car_add(id);
        manager.display_manager_menu(id);
        break;
    case '5':
        car.Car_update(id);
        manager.display_manager_menu(id);
        break;
    case '6':
        car.Car_delete(id);
        manager.display_manager_menu(id);
        break;
    case '7':
        cout << "Enter the id of the user : ";
        cin >> user_id;
        manager.see_rented_to_user(id, user_id);
        manager.display_manager_menu(id);
        break;
    case '8':
        cout << "Enter the id of the Car : ";
        cin >> car_id;
        manager.see_rented_car(id, car_id);
        manager.display_manager_menu(id);
        break;
    case '9':
        manager.see_all_users(id);
        manager.display_manager_menu(id);
        break;
    case '0':
        manager.see_all_cars(id);
        manager.display_manager_menu(id);
        break;
    case 'D':
        cout << "Enter the id of the Car : ";
        cin >> car_id;
        car.Show_duedate(car_id);
        manager.display_manager_menu(id);
        break;
    case 'E':
        logout();
        manager.display_manager_menu(id);
        break;
    }
}
int User ::User_record(string id)
{
    readfile("user_data.csv");

    int record = 0;
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][3] == id)
        {

            record = stoi(content[i][3]);
        }
    }
    content.clear();
    return record;
}
void User::display_menu()
{
    char choice;
    cout << "---------------------------------------------------------------------\n";
    cout << "\n\nWelcome to the Car Rental System\n\n";
    cout << "---------------------------------------------------------------------\n";
    cout << "Choose Your Role: \n";
    cout << " (1) Login\n (2) Exit\n";
    cout << "---------------------------------------------------------------------\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    User u;
    switch (choice)
    {
    case '1':
        login();
        break;
    case '2':
        cout << "Thanks for using the system!" << endl;
        exit(1);
    default:
        cout << "Invalid choice. Please enter a valid option." << endl;
        u.display_menu();
        break;
    }
}

void User::login()
{
    string id, pass;
    cout << "Enter your id : ";
    cin >> id;
    cout << "Enter the password : ";
    cin >> pass;
    vector<string> row_word;
    string line_row, word;
    fstream data("user_data.csv", ios::in);
    int logIn = 0;
    if (data.is_open())
    {
        while (getline(data, line_row))
        {
            row_word.clear();
            stringstream str(line_row);
            while (getline(str, word, ','))
                row_word.push_back(word);
            if (row_word[1] == id)
            {
                logIn++;
                if (row_word[2] == pass)
                {
                    logIn++;
                    break;
                }
                else
                {
                    while (pass != row_word[2])
                    {
                        cout << "You entered the wrong password.  1 to reenter the password and 2 to exit\n";
                        char c;
                        cin >> c;
                        if (c == '1')
                        {
                            cout << "Enter the password : ";
                            cin >> pass;
                            if (pass == row_word[2])
                                logIn++;
                        }
                        else if (c == '2')
                        {
                            cout << "Exiting...";
                            return;
                        }
                        else
                        {
                            cout << "Please enter a valid input.\n";
                        }
                    }
                    if (logIn == 2)
                        break;
                }
            }
        }
        if (logIn == 0)
        {
            cout << "User not found\n";
            User u;
            u.display_menu();
        }
        if (logIn == 2)
        {

            Customer c;
            Employee e;
            Manager m;

            if (row_word[4] == "1")
            {
                c.display_user_menu(row_word[1]);
            }
            else if (row_word[4] == "2")
            {
                e.display_user_menu(row_word[1]);
            }
            else
            {
                m.display_manager_menu(row_word[1]);
            }
        }
    }
}
void User ::display_cars(string id)
{
    content.clear();
    cout << "In the data below, 0 signifies that the Car is not rented and 1 means that the Car rented.\n";
    readfile("car_data.csv");
    printdata(content);
    content.clear();
}
void User ::check_available(string id, string cr_id)
{
    content.clear();

    readfile("car_data.csv");
    int count = 1;

    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][3] == cr_id)

        {

            if (content[i][5] == "0")
            {

                std ::cout << count << ". ";
                count++;
                std ::cout << "Car is available!\n";
                for (auto j : content[i])
                    std ::cout << j << " | ";
                std ::cout << "\n";
                return;
            }
            else
            {
                std::cout << "Car is not available\n";
                return;
            }
        }
    }
    std::cout << "Inter Valid Id\n";

    content.clear();
}
void User ::logout()
{
    cout << "Exiting\n";
    User u;
    u.display_menu();
}
void User ::User_add(string id)
{
    Manager manager;
    manager.add_user(id);
}
void User ::User_delete(string id)
{
    Manager manager;
    manager.delete_user(id);
}
void User ::User_update(string id)
{
    Manager manager;
    manager.update_user(id);
}
void User::rent_record(string id, string id_car)
{
    content.clear();
    readfile("car_data.csv");
    string rent;
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][3] == id_car)
        {

            rent = content[i][4];
            break;
        }
    }
    content.clear();
    readfile("rent_record.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][0] == id)
        {
            if (content[i][2] == "1")
            {
                content[i][1] = to_string(stoi(content[i][1]) + stoi(rent));
                writefile(content, "rent_record.csv");
                break;
            }
            else
            {
                content[i][1] = to_string(0.85 * stoi(content[i][1]) + stoi(rent));
                writefile(content, "rent_record.csv");
                break;
            }
        }
    }
    content.clear();
}
void User ::rented_cars(string id) // request for rentng a car
{
    content.clear();

    int count = 1;
    content.clear();
    readfile("rented_car.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][3] == id)
        {
            count++;
        }
    }
    content.clear();
    int max_car_can_rent;
    readfile("user_data.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][1] == id)
        {
            max_car_can_rent = (stoi(content[i][3])) / 100;
        }
    }
    content.clear();

    if (count > max_car_can_rent)
    {
        cout << "You can't rent,Only You Can Rent: " << max_car_can_rent << " Cars As per as your Customer Record , please contact to manager\n";
    }
    else
    {
        string id_car;
        cout << "Enter Car id you want to rent :";
        cin >> id_car;
        string no_of_days;
        cout << "Enter no of days you want to rent :";
        cin >> no_of_days;
        bool flag = false;

        readfile("car_data.csv");
        for (int i = 0; i < content.size(); i++)
        {
            if (content[i][3] == id_car)

            {
                if (content[i][5] == "0")
                {
                    cout << "Car is available!\n";
                    flag = true;
                    content[i][5] = "1";
                    toupdate.clear();
                    toupdate.push_back(content[i][0]); // 0
                    toupdate.push_back(content[i][3]); // 1 car id
                    toupdate.push_back(content[i][2]); // 2 condition
                    toupdate.push_back(id);            // 3 user id
                    toupdate.push_back(content[i][4]); // 4 rent

                    time_t currentTime = time(0);

                    toupdate.push_back(to_string(currentTime)); // 5
                    toupdate.push_back(no_of_days);             // 6

                    writefileappend(toupdate, "rented_car.csv");
                    cout << "Car Successfully rented\n";
                    writefile(content, "car_data.csv");

                    break;
                }
                else
                {
                    cout << "Car not available\n";

                    content.clear();
                }
            }
        }
        if (flag == true)
        {
            User u;
            rent_record(id, id_car);
        }
    }
}
int User ::calculate_fine(string id)
{
    int fine = 0;

    content.clear();
    readfile("rented_car.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][3] == id)
        {
            int cur_time = time(0);
            int rent_time = stoi(content[i][5]);
            if ((cur_time - rent_time) / 86400 > stoi(content[i][6]))
                fine += 2 * ((cur_time - rent_time) / 86400 - stoi(content[i][6]));
        }
    }
    cout << "Your fine is : " << fine << "\n";

    content.clear();
    return fine;
}
void User ::return_cars(string id, string id_car)
{
    content.clear();
    int fl = 0;

    readfile("rented_car.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][1] == id_car && content[i][3] == id)
        {

            fl = 1;
            content.erase(content.begin() + i, content.begin() + i + 1);
            // cout << "Car Returned..\n";
            writefile(content, "rented_car.csv");
            content.clear();
            readfile("car_data.csv");
            for (int i = 0; i < content.size(); i++)
            {
                if (content[i][3] == id_car)
                    content[i][5] = "0";
            }
            writefile(content, "car_data.csv");

            content.clear();
            cout << "Rate Condition of the Car out of 10 (example: 10 for Excellent): ";
            int condition;
            cin >> condition;
            User u;
            int fine = u.calculate_fine(id);
            content.clear();

            readfile("user_data.csv");

            string str = content[i][3];
            cout << "Current User Record : " << str << endl;
            content[i][3] = to_string((stoi(str) + (condition - 5) * 20 - fine * 20));
            cout << "User Record updated : " << content[i][3] << '\n';
            cout << "Car Renturned\n";

            writefile(content, "user_data.csv");
            content.clear();
        }
    }
    if (fl == 0)
        cout << "Invalid details!\n";

    content.clear();
}
void User ::clear_fine_amount(string id)
{
    int a = calculate_fine(id);
    string total_rent;

    readfile("rent_record.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][0] == id)
        {

            cout << "Your Car rent Due: " << content[i][1] << endl;
            total_rent = content[i][1];
            break;
        }
    }
    if (total_rent == "0" && a == 0)
    {
        cout << "You have no pending dues\n";
        return;
    }
    else
    {
        string choice;
        cout << "Do you want to clear your Dues(Yes/No) : ";
        cin >> choice;
        if (choice == "Yes" || choice == "yes")
        {
            cout << "Your Dues is being cleared.\n";
            total_rent = "0";
            for (int i = 0; i < content.size(); i++)
            {
                if (content[i][0] == id)
                {

                    content[i][1] = total_rent;
                    writefile(content, "rent_record.csv");
                    content.clear();
                    break;
                }
            }
        }
        else
        {

            cout << "You have pending dues\n";
        }
    }
}
void User ::see_rented_cars(string id)
{
    int count = 0;
    content.clear();
    readfile("rented_car.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][3] == id)
        {
            cout << count << ". ";
            count++;
            for (int k = 0; k < content[i].size() - 1; k++)
            {
                if (k == 3 || k == 5)
                {
                    continue;
                }
                cout << content[i][k] << " | ";
            }

            time_t stamp = stoi(content[i][5]);
            tm *dateformat = localtime(&stamp);
            cout << dateformat->tm_mday << "/" << 1 + dateformat->tm_mon << "/" << 1900 + dateformat->tm_year << "\n";
        }
    }
    if (count == 0)
        cout << "You haven't rented any Car\n\n";
    content.clear();
}

void Car ::Show_duedate(string id)
{
    content.clear();
    string cid;
    time_t stamp;
    int days;
    readfile("rented_car.csv");
    int fl = 0;
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][1] == id)
        {
            fl = 1;
            cid = content[i][1];
            stamp = stoi(content[i][5]);
            days = stoi(content[i][6]);
            break;
        }
    }
    content.clear();
    stamp += days * 86400;
    tm *due_time = localtime(&stamp);
    if (fl == 0)
        cout << "Car was not rented!\n";
    else
    {
        cout << "Due date of the  is Car: ";
        cout << due_time->tm_mday << "/" << 1 + due_time->tm_mon << "/" << 1900 + due_time->tm_year << "\n";
    }
}
void Car ::Car_request(string id)
{
    User u;
    u.rented_cars(id);
}
void Car ::Car_add(string id)
{
    Manager manager;
    manager.add_Car(id);
}
void Car ::Car_delete(string id)
{
    Manager manager;
    manager.delete_Car(id);
}
void Car ::Car_update(string id)
{
    Manager manager;
    manager.update_Car(id);
}
void Car ::Car_search(string id)
{
}

void Manager ::see_all_users(string id)
{
    content.clear();
    readfile("user_data.csv");
    cout << "Below are all the users. 1 at the end signifies a Customer, 2 means a Employee and 3 means a Manager \n\n";
    cout << "The data is given in the form of Name,ID,password,User Record,type of user.\n\n";
    printdata_notpassword(content);
    content.clear();
}
void Manager ::see_all_cars(string id)
{
    content.clear();
    readfile("car_data.csv");
    if (content.empty() == true)
    {
        cout << "Car List is Empty. Add Some \n";
    }
    else
    {
        cout << "The data is given in the form of Car name,Model,Condition,Car id,Rent and is_issued(1 if Car is rented).\n\n";
        printdata(content);
        content.clear();
    }
}
void Manager ::add_user(string id)
{
    char i;
    cout << "(1) Add Customer\n(2) Add Employee\n"
         << endl;
    cin >> i;
    if (i == '1')
    {
        cout << "Please enter the details of the new user : \n";
        string _name, _id, _password, customer_record = "380";
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter id : ";
        cin >> _id;
        cout << "Enter password : ";
        cin >> _password;
        fstream fout("user_data.csv", ios::out | ios::app);
        fout << name << "," << _id << "," << _password << "," << customer_record << ","
             << "1" << '\n';
        cout << "New user has been added.\n";
        // ****
        content.clear();
        fstream f_out("rent_record.csv", ios::out | ios::app);
        f_out << _id << ","
              << "0"
              << ","
              << "1" << '\n';
    }
    else if (i == '2')
    {
        cout << "Please enter the details of the new user : \n";
        string _name, _id, _password, employee_record = "390";
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter id : ";
        cin >> _id;
        cout << "Enter password : ";
        cin >> _password;
        fstream fout("employee.csv", ios::out | ios::app);
        fout << name << "," << _id << "," << _password << "," << employee_record << ","
             << "2" << '\n';
        cout << "New user has been added.\n";
        content.clear();
        fstream f_out("rent_record.csv", ios::out | ios::app);
        f_out << _id << ","
              << "0"
              << ","
              << "2" << '\n';
    }
    else
    {
        cout << "Invalid Key" << endl;
        add_user(id);
    }
}
void Manager ::add_Car(string id)
{
    cout << "Please enter the details of the new Car : \n";
    string Name, Model, Condition, id_car, Rent, rented_to = "0";
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Enter Model : ";
    cin >> Model;
    cout << "Enter Condition : ";
    cin >> Condition;
    cout << "Enter Id : ";
    cin >> id_car;
    cout << "Enter Rent : ";
    cin >> Rent;

    fstream fout("car_data.csv", ios::out | ios::app);
    fout << Name << "," << Model << "," << Condition << "," << id_car << "," << Rent << "," << rented_to << '\n';
    cout << "New Car has been added.\n";
}

void Manager ::delete_Car(string id)
{
    string cid;
    cout << "Enter Id of the car : ";
    cin >> cid;
    content.clear();
    int found = 0;
    readfile("car_data.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][3] == cid)
        {
            found = 1;
            content.erase(content.begin() + i, content.begin() + i + 1);
            break;
        }
    }
    writefile(content, "car_data.csv");
    content.clear();
    readfile("rented_car.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][1] == cid)
        {
            content.erase(content.begin() + i, content.begin() + i + 1);
            break;
        }
    }
    writefile(content, "rented_car.csv");
    content.clear();
    if (found == 0)
        cout << "Car not found.\n";
}
void Manager::delete_user(string id)
{
    string uid;
    cout << "Enter the user id of the user : ";
    cin >> uid;
    if (uid == "MAN01")
    {
        cout << "You Can't delete Manager\n";
        return;
    }
    content.clear();
    int found = 0;
    readfile("user_data.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][1] == uid)
        {
            found = 1;
            content.erase(content.begin() + i, content.begin() + i + 1);
            break;
        }
    }
    writefile(content, "user_data.csv");
    content.clear();

    readfile("rent_record.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][0] == uid)
        {

            content.erase(content.begin() + i, content.begin() + i + 1);
            break;
        }
    }
    writefile(content, "rent_record.csv");
    content.clear();

    vector<string> isbns;
    readfile("rented_car.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][3] == uid)
        {
            isbns.push_back(content[i][1]);
            content.erase(content.begin() + i, content.begin() + i + 1);
            break;
        }
    }
    writefile(content, "rented_car.csv");
    content.clear();

    readfile("car_data.csv");
    for (int i = 0; i < content.size(); i++)
    {
        for (int j = 0; j < isbns.size(); j++)
        {
            if (isbns[j] == content[i][3])
            {
                content[i][5] = "0";
            }
        }
    }
    writefile(content, "car_data.csv");
    if (found == 1)
    {
        cout << "User has been deleted.\n";
    }
    if (found == 0)
        cout << "User not found.\n";
}
void Manager::update_user(string id)
{
    string upid;
    cout << "Enter the id of the user you want to update : ";
    cin >> upid;
    cout << "Enter the serial number of the field you want to update : \n";
    cout << "1. Password\n";
    cout << "2. Name of the User\n";
    char c;
    cin >> c;
    content.clear();
    int fl = 0;
    readfile("user_data.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][1] == upid)
        {
            fl = 1;
            string new_field;
            cout << "Enter the new value of the field : ";
            cin.ignore();
            getline(cin, new_field);
            if (c == '1')
            {
                content[i][2] = new_field;
            }
            else if (c == '2')
            {
                content[i][0] = new_field;
            }
            else
            {
                cout << "Invalid input!\n\n";
            }
            break;
        }
    }
    cout << "User updated\n";
    writefile(content, "user_data.csv");
    content.clear();
    if (fl == 0)
        cout << "User was not found.\n\n";
}
void Manager::update_Car(string id)
{
    string id_car;
    cout << "Enter the Id of the car you want to update : ";
    cin >> id_car;
    cout << "Enter the serial number of the field you want to update : \n";
    cout << "1. Name of the Car\n";
    cout << "2. Model of the Car\n";
    cout << "3. Rent\n";
    char c;
    cin >> c;
    content.clear();
    int fl = 0;
    string new_field;
    readfile("car_data.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][3] == id_car)
        {
            fl = 1;
            cout << "Enter the new value of the field : ";
            cin.ignore();
            getline(cin, new_field);
            if (c == '1')
            {
                content[i][0] = new_field;
            }
            else if (c == '2')
            {
                content[i][1] = new_field;
            }
            else if (c == '3')
            {
                content[i][4] = new_field;
            }
            else
            {
                cout << "Invalid input!\n\n";
            }
            break;
        }
    }
    writefile(content, "Car_data.csv");
    content.clear();

    readfile("rented_car.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][3] == id_car)
        {
            fl = 1;
            if (c == '1')
            {
                content[i][0] = new_field;
            }
            break;
        }
    }
    cout << "Car updated\n";
    writefile(content, "rented_book.csv");

    if (fl == 0)
        cout << "Car not found.\n\n";
}
void Manager ::see_rented_car(string id, string id_car)
{
    content.clear();
    int coun = 0;
    readfile("rented_car.csv");
    for (int i = 0; i < content.size(); i++)
    {

        if (content[i][1] == id_car)
        {
            coun = 1;
            cout << "Car with id " << id_car << " and name " << content[i][0] << " is rented to user with id : " << content[i][3] << "\n";
        }
    }
    if (coun == 0)
        cout << "Car is not rent to anyone.\n\n";
}
void Manager::see_rented_to_user(string id, string uid)
{
    vector<string> record;
    content.clear();
    int count = 1;
    readfile("rented_car.csv");
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i][3] == uid)
        {
            record.push_back(content[i][1]);
        }
    }
    content.clear();
    if (record.size() == 0)
        cout << "No Car rented  to this user.\n\n";
    else
    {
        readfile("car_data.csv");
        for (int d = 0; d < record.size(); d++)
        {
            for (int i = 0; i < content.size(); i++)
            {
                if (content[i][3] == record[d])
                {
                    cout << count << ". ";
                    count++;
                    int record = 0;
                    for (auto y : content[i])

                    {
                        record++;
                        if (record == 6)
                        {
                            continue;
                        }
                        if (y != content[i].back())
                            cout << y << " | ";
                    }
                    cout << "\n";
                }
            }
        }
        content.clear();
    }
}

int main()
{
    User user;
    user.display_menu();

    return 0;
}
