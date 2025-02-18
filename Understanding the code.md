# Big Number Arithmetic Calculator

## Input Handling
- The code reads two large numbers from the user input and stores each digit in arrays `inp1` and `inp2`.
- The user can then choose an operation: Addition, Subtraction, Multiplication, or Division*.  
###### *The code has a case for division, but it prints "Access denied" and does not perform any division operation (Not implemented yet).

## Arithmetic Operations *(Fully Manual)*
- **Addition (`Add` function)**: This function handles the addition of two large integers, performing a carry-over between digits if needed.
- **Subtraction (`Subtract` function)**: This function handles the subtraction of one large integer from another, borrowing if necessary.
- **Multiplication (`Multiplication` function)**: This function handles the multiplication of two large integers using a nested loop approach, similar to how you would multiply numbers manually.

## Utility Functions
- **`printer`**: Prints the resulting array either in normal or reversed order.
- **`isTwoDigit`**: Checks if a given number is a two-digit number.
- **`borrowFunc`**: Borrows from higher-order digits in subtraction if necessary.
- **`checkFunc`**: Ensures that the current digit is greater than or equal to the digit being subtracted; otherwise, it calls `borrowFunc`.
- **`initialization`**: Initializes an array to zero.

## Flow
- Based on the operation selected by the user, the corresponding function (`Add`, `Subtract`, or `Multiplication`) is called to perform the calculation.
- The result is printed using the `printer` function.
