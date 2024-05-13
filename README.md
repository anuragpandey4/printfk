# Custom Printf Function in C

## Introduction

This README explains the custom `printf` function written in C by a JavaScript developer. The function aims to replicate the standard `printf` functionality without using the `stdio.h` library, utilizing variadic functions and system calls.

## Variadic Functions

Variadic functions allow for a variable number of arguments, providing flexibility for functions like `printf`. In C, when passing arguments to a variadic function, certain type promotions occur:

- `char` and `short` are promoted to `int`.
- `float` is promoted to `double`.

These promotions are part of the C language specifications to ensure that the data is handled consistently.

### Implicit Type Promotion

In variadic functions, types smaller than `int` (like `char` and `short`) are promoted to `int`, and `float` is promoted to `double` to ensure consistent data handling across different architectures.

### System Call `write()`

The `write()` system call directly writes data to a file descriptor, such as `stdout`, bypassing the standard library buffering. It takes three arguments: the file descriptor, the address of the data, and the number of bytes to write.

## Code Explanation

- **`printCharacter`**: Outputs a character using `write()`. It handles the null terminator by returning early.
- **`printInteger`**: Converts a `long` integer to a string representation and prints it using `printCharacter`. It avoids recursion for simplicity.
- **`printLong`**: Similar to `printInteger`, but for `unsigned long` integers.
- **`printString`**: Prints a string character by character until the null terminator is reached.
- **`printFloat`**: Separates the integer and decimal parts of a `float` and prints them with the specified precision.
- **`printHexaDecimal`**: Converts an `unsigned int` to hexadecimal and prints it.
- **`printPointer`**: Prints the memory address contained in a pointer in hexadecimal format.
- **`printfk`**: The main variadic function that processes a format string and arguments, printing each according to the specified format.

## Note on Recursion

Recursion was avoided due to its complexity in C and the developer's current skill level. Iterative approaches were used instead to ensure reliability and maintainability.

## Conclusion

This project serves as a practical introduction to C programming, demonstrating the use of variadic functions and system calls to create a custom `printf` function.
