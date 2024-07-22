# EMPLOYEE-XPERT
#Lab Semester Project

# Employee Management System

## Code Breakdown

### 1. Header Files
- **`<iostream>`**: Provides input/output functionalities (`cin`, `cout`)
- **`<fstream>`**: Enables file handling (`ifstream`, `ofstream`)
- **`<string>`**: Used for string manipulation (`getline`)
- **`<sstream>`**: Used for string streams (`istringstream`)
- **`<windows.h>`**: Contains the `Sleep()` function (**Note:** This header is platform-specific for Windows)

### 2. `using namespace std;`
- Avoids writing `std::` before standard library elements.

### 3. `Employee` Struct
- Defines a structure to represent an employee with fields for:
  - `name`
  - `CNIC`
  - `payscale`
  - `attendance`

### 4. `MAX_EMPLOYEES` Constant
- Sets the maximum number of employees the program can store.

### 5. `clearScreen()` Function (**Not Implemented Yet**)
- Declared but not implemented. Likely meant to clear the console screen.

### 6. `addEmployee()` Function
- Parameters: array of `Employee`s, employee count (`employeeCount`)
- Functionality:
  - Checks if the employee count has reached the maximum.
  - Prompts the user to enter employee details.
  - Adds the new employee to the array and increments the count.

### 7. `searchEmployee()` Function
- Parameters: employee array, employee count, CNIC to search for
- Functionality:
  - Iterates through the array to find a matching CNIC.
  - Prints the employee details and calculated monthly income if found.

### 8. `editEmployee()` Function
- Parameters: employee array, employee count, CNIC to edit
- Functionality:
  - Iterates through the array to find a matching CNIC.
  - Prompts the user to enter new employee details and updates them in the array.

### 9. `deleteEmployee()` Function
- Parameters: employee array, employee count reference (`employeeCount`), CNIC to delete
- Functionality:
  - Iterates through the array to find a matching CNIC.
  - Shifts remaining elements to overwrite the deleted employee.
  - Decrements the employee count (adjusted due to the extra increment in the loop).

### 10. `saveDataToFile()` Function
- Functionality:
  - Opens an output file named "employee_data.db" in write mode.
  - Iterates through the employee array and writes each employee's data to the file in CSV format.
  - Closes the file and informs the user.

### 11. `loadDataFromFile()` Function
- Functionality:
  - Opens an input file named "employee_data.db" in read mode.
  - Iterates through each line in the file.
  - Extracts employee data (name, CNIC, payscale, attendance) using `istringstream`.
  - Creates a new employee object and assigns the extracted data.
  - Adds the new employee to the array and increments the count.
  - Closes the file and informs the user.

### 12. `displayemployee()` Function (**Not Complete Yet**)
- Functionality:
  - Opens the employee data file, reads line by line, extracts data, and prints it with labels.
  - Consider using `loadDataFromFile()` to load employees into the array for better organization.

### 13. `main()` Function
- Functionality:
  - Clears the screen (assuming `clearScreen()` is implemented).
  - Prints a welcome message with ASCII art and loading animation (using `Sleep()` for delays).
  - Creates an array of `Employee`s and initializes the employee count to 0.
  - Calls other functions based on user input (not implemented yet).

## Suggestions for Improvement

1. **Implement `clearScreen()` Function**
   - Use system commands like `cls` (Windows) or `clear` (Linux/macOS) for platform-independent screen clearing.

2. **Error Handling**
   - Add checks for file operations (open/close success), invalid user input, etc.

3. **Menu System**
   - Implement a menu-driven interface for user interaction with options for adding, searching, editing, deleting, saving, loading, displaying, and exiting.

4. **Cross-Platform Compatibility**
   - Consider using portable libraries or platform-specific checks for functions like `clearScreen()`.

5. **`displayemployee()` Function**
   - Utilize `loadDataFromFile()` to load employees into the array instead of directly reading the file line by line.

6. **User Input**
   - Implement a loop to continuously prompt the user for actions until they choose to exit.

---
