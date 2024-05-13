# Custom Printf Function in C

## Introduction
This README documents a custom `printf` function written in C by a developer with a background in JavaScript. This project represents the developer's first foray into C programming and demonstrates the use of variadic functions to replicate the functionality of the standard `printf`.

## Implementation Details

### Variadic Functions
The core of this custom `printf` implementation is the use of variadic functions, which allow for an indefinite number of arguments. This is crucial for a `printf`-like function that must handle various data types and quantities of inputs.

### Implicit Type Promotion
In variadic functions, there is an implicit promotion of certain data types:
- `char` is promoted to `int`.
- `float` is promoted to `double`.

These promotions ensure that the data is handled consistently and that the function operates correctly across different argument types.

### Functions

#### `void printCharacter(int character)`
Prints a single character to the output. If the character is a null terminator (`'\0'`), the function returns early.

#### `void printInteger(long integer)`
Converts a long integer to a string and prints it. Handles negative numbers and zero.

#### `void printLong(unsigned long num)`
Similar to `printInteger`, but specifically for unsigned long integers.

#### `void printString(char *string)`
Prints a string character by character until the null terminator is reached.

#### `void printFloat(float floatNum, int precision)`
Prints a floating-point number with the specified precision. It separates the integer and decimal parts, handling them individually.

#### `void printFloatNoPrecision(float floatNum)`
Prints a floating-point number without precision, defaulting to two decimal places.

#### `void printHexaDecimal(unsigned int num)`
Converts an unsigned integer to its hexadecimal representation and prints it.

#### `void printPointer(void *ptr)`
Prints the memory address contained in a pointer in hexadecimal format.

#### `int printfk(char *format, ...)`
The main variadic function that processes the format string and the arguments. It handles different format specifiers and calls the appropriate functions to print each argument.

## System Call `write()`
The `write()` system call is used to output characters to the standard output. This low-level system call is utilized instead of standard library functions for direct control over output operations.

### Example of `write()` System Call
```c
void printCharacter(int character)
{
    char ch = (char)character;
    write(1, &ch, 1); // Writes the character to stdout (file descriptor 1)
}
