    /*------------------------------------------------------------------------
 * Application Name: EMPLOYEE XPERT                                       *
 *                                                                        *
 * Purpose: The purpose of this code is the implementation of             *
 *          a command-line interface (CLI) program that simulates         *
 *          a Human Resource DBMS to provide organized management of      *
 *          storing/retrieving/maintaining Employee Data                  *
 *                                                                        *
 *                                                                        *
 * Inputs: CLI-based input, integers and ENTER keystroke as well as       *
 *         strings for user details that are stored in variables. File    *
 *         input format is ".db".                                         *
 *                                                                        *
 * Outputs: Multiple functions return integer values.                     *
 *          The program outputs to console and also to files. Output file *
 *          format is ".db".                                              *
 *                                                                        *
 * Methods: File handling, i/o manipulation, Pointers, Boolean Logic      *
 *          Logical Operators, Conditional Statements.                    *
 *                                                                        *
 ------------------------------------------------------------------------
 * Changelog:                                                             *
 *   DATE   |   RELEASE  |                     CHANGES                    *
 * 23-05-23 |  0.1-Alpha | Code initialized and first test-run            *
 * 24-05-23 |  0.2-Beta  | Added adequtae header files                    *
 * 24-05-23 |  0.21-Beta | Used Struct{} datattype                        *
 * 24-05-23 |  0.22-Beta | Delay added To Output Using Sleep(); function. *
 * 25-05-23 |  0.3-Beta  | Added Menu Driven Output With ASCII Art.       *
 * 26-05-23 |  0.4-Beta  | Added Functions To Perform Respective Actions. *
 *                                                                        *
 -------------------------------------------------------------------------*/



#include <iostream>  // Header file for input/output operations
#include <fstream>   // Header file for file handling operations
#include <string>    // Header file for string operations
#include <sstream>   // Header file for string stream operations
#include <windows.h> // Header file to use Sleep() Function

using namespace std;    //Using To avoid std:: in I/O operations

// Define a struct to represent an employee
struct Employee {
    string name;    //String for storing name of Employee
    string CNIC;    //Sreing for Storing CNIC of Employee
    int payscale;   //Integer for Storing Payscale
    int attendance; //Integer For Storing Attendance
};

    int MAX_EMPLOYEES = 30;


void clearScreen();

// Function to add an employee to the database
void addEmployee(Employee* employees, int& employeeCount)
{
    if (employeeCount >= MAX_EMPLOYEES) //Using If-Statement To check If Number
    {                                   //Of Employees Stored Are More Than The Allowed Limit.
        clearScreen();                  //Clearing The Terminal Window.
        cout<<R"($$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
$$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
$$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
$$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
$$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
$$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
        cout<<"\n\n\n";                 //Moving Cursor TO next lines To add some Space.
        cout << "\t\t\t\t\tEmployee database is full. Cannot add more employees." << endl;
        return;                         //Exits The Function and Gives Control To main() Function.
    }

    // Create a new employee object
    Employee newEmployee;
    clearScreen();      //Clearing The Screen
cout<<R"($$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
$$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
$$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
$$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
$$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
$$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
    cout<<"\n\n\n";
    // Prompt the user to enter employee details
    cout << "\t\t\t\t\tEnter Employee Name: ";
    cin.ignore();   //Clearing Input Buffer
    getline(cin, newEmployee.name);     //Inputting multiple Characters
    cout << "\t\t\t\t\tEnter Employee CNIC: ";
    getline(cin, newEmployee.CNIC);     //Inputting multiple Characters
    cout << "\t\t\t\t\tEnter Employee Pay Scale: ";
    cin >> newEmployee.payscale;
    cout << "\t\t\t\t\tEnter Employee Attendance: ";
    cin >> newEmployee.attendance;

    // Add the new employee to the array
    employees[employeeCount] = newEmployee;
    employeeCount++;

    cout << "\t\t\t\t\tEmployee added successfully." << endl;
}

// Function to search for an employee by CNIC
void searchEmployee(const Employee* employees, int employeeCount, const string& CNIC) {
    bool found = false;

    // Iterate over the employees array to find a match
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].CNIC == CNIC)
        {
            clearScreen();
cout<<R"($$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
$$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
$$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
$$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
$$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
$$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
    cout<<"\n\n\n";
            // Print the employee details
            cout << "\t\t\t\t\tEmployee Name: " << employees[i].name << endl;
            cout << "\t\t\t\t\tEmployee Pay Scale: " << employees[i].payscale << endl;
            cout << "\t\t\t\t\tEmployee Attendance: " << employees[i].attendance << endl;

            // Calculate the monthly income based on the employee's payscale and attendance
            int monthlyIncome = employees[i].payscale * 237 * employees[i].attendance;
            cout << "\t\t\t\t\tMonthly Income: " << monthlyIncome << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        clearScreen();
cout<<R"($$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
$$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
$$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
$$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
$$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
$$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
    cout<<"\n\n\n";
        cout << "\t\t\t\t\tEmployee with CNIC " << CNIC << " not found." << endl;
    }
}

// Function to edit an employee's data by CNIC
void editEmployee(Employee* employees, int employeeCount, const string& CNIC) {
    bool found = false;

    // Iterate over the employees array to find a match
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].CNIC == CNIC)
        {
            clearScreen();
cout<<R"($$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
$$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
$$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
$$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
$$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
$$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
    cout<<"\n\n\n";

            // Prompt the user to enter the updated employee details
            cout << "\t\t\t\t\tEnter new Employee Name: ";
            cin.ignore();
            getline(cin, employees[i].name);        //Inputting multiple Characters
            cout << "\t\t\t\t\tEnter new Employee Pay Scale: ";
            cin >> employees[i].payscale;           //Taking Input
            cout << "\t\t\t\t\tEnter new Employee Attendance: ";
            cin >> employees[i].attendance;         //Taking Input

            cout << "\t\t\t\t\tEmployee data updated successfully." << endl;
            found = true;                           //flag
            break;
        }
    }

    if (!found)                 //If Employee with Entered CNIC iS not found.
    {
        clearScreen();
    cout<<R"($$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
    $$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
    $$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
    $$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
    $$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
    $$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
        cout<<"\n\n\n";
        cout << "\t\t\t\t\tEmployee with CNIC " << CNIC << " not found." << endl;
    }
}

// Function to delete an employee by CNIC
void deleteEmployee(Employee* employees, int& employeeCount, const string& CNIC) {
    bool found = false;

    // Iterate over the employees array to find a match
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].CNIC == CNIC) {
            // Shift the remaining elements in the array to overwrite the deleted employee
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }

            // Update the employee count and inform the user
            employeeCount--;   //Decremented The value Due to Extra Increment From The loop.
            clearScreen();
cout<<R"($$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
$$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
$$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
$$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
$$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
$$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
    cout<<"\n\n\n";
            cout << "\t\t\t\t\tEmployee with CNIC " << CNIC << " deleted successfully." << endl;
            found = true;   //Flag
            break;
        }
    }

    if (!found)
    {
        clearScreen();          //Clearing The Screen
cout<<R"($$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
$$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
$$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
$$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
$$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
$$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
    cout<<"\n\n\n";
        cout << "\t\t\t\t\tEmployee with CNIC " << CNIC << " not found." << endl;
    }
}

// Function to save employee data to a file
void saveDataToFile(const Employee* employees, int employeeCount) {
    // Open the output file in write mode
    ofstream outputFile("employee_data.db");

    // Iterate over the employees array and write each employee's data to the file
    for (int i = 0; i < employeeCount; i++) {
        outputFile << employees[i].name << "," << employees[i].CNIC << ","
                   << employees[i].payscale << "," << employees[i].attendance << endl;
    }

    // Close the file and inform the user
    outputFile.close();
    clearScreen();
cout<<R"($$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
$$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
$$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
$$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
$$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
$$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
    cout<<"\n\n\n";
    cout << "\t\t\t\t\tEmployee data saved to file." << endl;
}

// Function to load employee data from a file
void loadDataFromFile(Employee* employees, int& employeeCount) {
    // Open the input file
    ifstream inputFile("employee_data.db");
    string line;

    // Read each line from the file
    while (getline(inputFile, line))
    {
        // Extract the employee data from the line
        string name, CNIC;
        int payscale, attendance;

        istringstream iss(line);
        getline(iss, name, ',');        //Inputting multiple Characters
        getline(iss, CNIC, ',');        //Inputting multiple Characters
        iss >> payscale;
        iss.ignore();
        iss >> attendance;

        // Create a new employee object and assign the extracted data
        Employee newEmployee;
        newEmployee.name = name;
        newEmployee.CNIC = CNIC;
        newEmployee.payscale = payscale;
        newEmployee.attendance = attendance;

        // Add the new employee to the array
        employees[employeeCount] = newEmployee;
        employeeCount++;
    }

    // Close the file and inform the user
    inputFile.close();

    cout << "\t\t\t\t\tEmployee data loaded from file." << endl;
}

void displayemployee(Employee* employee, int& employeeCount)
{
        ifstream inputFile("employee_data.db");
        string line;
        clearScreen();
cout<<R"($$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
$$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
$$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
$$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
$$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
$$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
    cout<<"\n\n\n";
        cout << "\n\t\t\t\t\t---- List Of Employees ----" << endl;
        int serial=1;
        while(getline(inputFile,line))
        {
            string name,CNIC;
            int payscale, attendance;
            istringstream issline(line);
            getline(issline,name,',');
            getline(issline,CNIC,',');
            issline >> payscale;
            issline.ignore();
            issline >> attendance;
            //Printing Employees And their details Stored In The Text File "employee_data.db"

            cout<<"\t\t\t\t\t"<<serial<<".Employee Name:"<<name<<endl;
            cout<<"\t\t\t\t\t  Employyee CNIC:"<<CNIC<<endl;
            cout<<"\t\t\t\t\t  Employee Payscale:"<<payscale<<endl;
            cout<<"\t\t\t\t\t  Employee Attendance:"<<attendance<<endl<<endl;;
            serial++;


        }



}

int main()
{

    cout<<"\n";
    clearScreen();              //Clearing The Screen

    cout<<R"($$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
$$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
$$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
$$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
$$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
$$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
    cout<<"\n\n\n";

    cout<<"\t\t\t\t\tLoading";
    for (int loading = 0; loading <= 5; loading++)          //Added 3 Different For() loops:
    {
        cout<<"*";
        Sleep(21);                                          //1. For Stars
    }
    cout<<"\t\t\t\t\t"<<endl;
    for(int star=0;star<=10;star++){
    cout<<"\t*_#_*";
    Sleep(10);
    }                                                       //2. For a pattern "*_#_*"
    cout<<"\t\t\t\t\t"<<endl;
    for(int stars=0;stars<=10;stars++)
    {
    cout<<"\t*_#_*";
    Sleep(10);
    }                                                       //3. Doing The same Job as in point 2
    Sleep(400);                                             //But added To avoid Complexity
    clearScreen();                                          //and to seperately have the ability to control
    cout<<"\n";


    // Creating an array of employees and initializing it to 0
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;

    cout<<R"(    $$$$$$$_ $$___$$_ $$$$$$__ $$______ __$$$___ $$____$$_ $$$$$$$_ $$$$$$$_ __$$___$$_ $$$$$$__ $$$$$$$_ $$$$$$__ $$$$$$_
    $$______ $$$_$$$_ $$___$$_ $$______ _$$_$$__ _$$__$$__ $$______ $$______ __$$$_$$$_ $$___$$_ $$______ $$___$$_ __$$___
    $$$$$___ $$$$$$$_ $$___$$_ $$______ $$___$$_ __$$$$___ $$$$$___ $$$$$___ ___$$$$$__ $$___$$_ $$$$$___ $$___$$_ __$$___
    $$______ $$_$_$$_ $$$$$$__ $$______ $$___$$_ ___$$____ $$______ $$______ ___$$$$$__ $$$$$$__ $$______ $$$$$$__ __$$___
    $$______ $$___$$_ $$______ $$____$_ _$$_$$__ ___$$____ $$______ $$______ __$$$_$$$_ $$______ $$______ $$___$$_ __$$___
    $$$$$$$_ $$___$$_ $$______ $$$$$$$_ __$$$___ ___$$____ $$$$$$$_ $$$$$$$_ __$$___$$_ $$______ $$$$$$$_ $$___$$_ __$$___)"<<endl;
    cout << endl;
    // Loading employee data from a file
    loadDataFromFile(employees, employeeCount);

    int choice;
    string searchCNIC;

    // Displaying a prompt menu and processes user's choices until the user chooses to exit voluntarily
    do {
        cout << "\n\t\t\t\t\t--- Employee Management System ---\n";
        Sleep(8);
        cout << "\t\t\t\t\tUse Digits (1-7) to Select The Options Provided Below: \n";
        Sleep(7);
        cout << "\t\t\t\t\t1. Add Employee\n";
        Sleep(6);
        cout << "\t\t\t\t\t2. Search Employee\n";
        Sleep(5);
        cout << "\t\t\t\t\t3. Edit Employee\n";
        Sleep(4);
        cout << "\t\t\t\t\t4. Delete Employee\n";
        Sleep(3);
        cout << "\t\t\t\t\t5. Save Data to File\n";
        Sleep(2);
        cout << "\t\t\t\t\t6. Display All Employees\n";
        Sleep(1);
        cout << "\t\t\t\t\t7. Exit\n";
        cout << "\t\t\t\t\t";
        cin >> choice;    //Taking Input Using choice() Function

        switch (choice)                 //Execution BASED on Condition
        {
            case 1:
                addEmployee(employees, employeeCount);
                break;
            case 2:
                cout << "\t\t\t\t\tEnter CNIC to search: ";
                cin >> searchCNIC;
                searchEmployee(employees, employeeCount, searchCNIC);
                break;
            case 3:
                cout << "\t\t\t\t\tEnter CNIC to edit: ";
                cin >> searchCNIC;
                editEmployee(employees, employeeCount, searchCNIC);
                break;
            case 4:
                cout << "\t\t\t\t\tEnter CNIC to delete: ";
                cin >> searchCNIC;
                deleteEmployee(employees, employeeCount, searchCNIC);
                break;
            case 5:
                saveDataToFile(employees, employeeCount);
                break;
            case 6:
                displayemployee(employees, employeeCount);
                break;
            case 7:
            inputerror: //Specified For Jump Statement
                cout << "\t\t\t\t\tDo you want to save data to a file? (Y/N)\t\t\t\t\t" << endl;
                char saver;   //Declared a Char variable To Use it for Further Conditioning.
                cout << "\n\t\t\t\t\t";
                cin >> saver;       //Taking Input
                if (saver == 'Y' || saver == 'y')
                {
                    saveDataToFile(employees, employeeCount);       //Function Call To save File.
                }
                else if (saver == 'N' || saver == 'n')
                {
                    cout << "\t\t\t\t\tYou Have Selected Not To Save The File.\n" << endl;
                    cout << "\t\t\t\t\tSkipping File Save..." << endl;
                }
                else
                {
                    cout << "\t\t\t\t\tInvalid Choice Selection!\n\t\t\t\t\tTry Again!" << endl;
                    goto inputerror; //Jump Statement
                }

                cout << "\t\t\t\t\tExiting program..." << endl;
                break;
            default:
            {
                cout << "\t\t\t\t\tInvalid choice. Please try again." << endl;
                break;
            }
        }
    }
    while (choice != 7 && cin);     //Ending Statement Of DO-WHILE LOOP.

    return 0;                       //main() function returning 0 On succesful Execution.
}

void clearScreen()      //Function Defined To Clear The Console screen
{                       //Uses The #include<windows.h> Header File.
    system("cls");      //Clear the screen using the system command "cls"
}
