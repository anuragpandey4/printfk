# Custom Printf Function in C

## Introduction
This README documents a custom `printf` function written in C by a developer with a background in JavaScript. This project represents the developer's first steps into C programming and demonstrates the use of variadic functions to replicate the functionality of the standard `printf`.

## Implementation Details

### Variadic Functions and Their Macros
Variadic functions are used when the number of arguments is not known in advance. They are declared with a fixed argument followed by an ellipsis (`...`). In C, certain data types are automatically promoted when passed as variadic arguments:
- `char` and `short` become `int`.
- `float` becomes `double`.

This ensures consistent behavior across different systems.

#### Macros for Variadic Functions
- **`va_list`**: A type that holds the information needed to retrieve additional arguments.
- **`va_start`**: A macro that initializes a `va_list` to point to the first variable argument.
- **`va_arg`**: Retrieves the next argument in the list with the specified type.
- **`va_end`**: Ends the traversal and cleanup of the `va_list`.

### The `write()` System Call
The `write()` system call sends data directly to a file descriptor, such as the console for output. It's a lower-level alternative to library functions like `printf`.

#### Example of `write()` System Call
```c
void printCharacter(int character)
{
    char ch = (char)character;
    write(1, &ch, 1); // Writes the character to stdout (file descriptor 1)
}
```

## Code Breakdown
Let's go through the key parts of the `printfk` function and its helpers:

### `printCharacter`
#### This function takes an integer (which represents a character), and if it’s not the end of a string ('\0'), it prints it out.
```c
void printCharacter(int character) {
    // Uses 'write' to output a character
}
```
### `printInteger`
#### It changes a long number into its text form and prints each digit. Negative numbers are handled by printing a minus sign first.
```c
void printInteger(long integer) {
    // Turns a long number into text and prints it
}
```
### `printLong`
#### Works like printInteger, but it’s made for even bigger numbers (unsigned long).
```c
void printLong(unsigned long num) {
    // Just like printInteger, but for bigger numbers
}

```

### `printString`
#### This function goes through a string and prints it out, character by character, until it hits the end.


```c
void printString(char *string) {
    // Prints a text string, one character at a time
}
```

### `printFloat`
#### For numbers with decimals, this function prints them with the number of decimal places you specify.


```c
void printFloat(float floatNum, int precision) {
    // Prints a decimal number with a set number of digits after the point
}

```
### `printHexaDecimal`
#### Converts a number into its hexadecimal form and prints that out.


```c
void printHexaDecimal(unsigned int num) {
    // Changes a number into hexadecimal and prints it
}


```

### `printHexaDecimal`
#### Converts a number into its hexadecimal form and prints that out.


```c
void printHexaDecimal(unsigned int num) {
    // Changes a number into hexadecimal and prints it
}


```

### `printPointer`
#### This function is used to print the memory address that a pointer is pointing to.


```c
void printPointer(void *ptr) {
    // Shows where in memory something is stored
}
```

## `printfk`
### The main variadic function that interprets the format string and prints each argument according to its specifier.The star of the show, printfk, decides how to print each argument based on the format you provide, like %d for integers or %s for strings.
```c
int printfk(char *format, ...) {
    // The main function that decides how to print each argument
}
```

## Test Cases
The code has been tested on the following cases to ensure its functionality:

- **Test Case 1**: Basic String Output
  - **Input**: `printfk("Hello, world!\n");`
  - **Expected Output**: "Hello, world!" followed by a newline.

- **Test Case 2**: Integer Formatting
  - **Input**: `printfk("The value of x is %d\n", 42);`
  - **Expected Output**: "The value of x is 42" followed by a newline.

- **Test Case 3**: String Placeholder
  - **Input**: `printfk("My name is %s\n", "Alice");`
  - **Expected Output**: "My name is Alice" followed by a newline.

- **Test Case 4**: Multiple Placeholders
  - **Input**: `printfk("The sum of %d and %d is %d\n", 10, 20, 10 + 20);`
  - **Expected Output**: "The sum of 10 and 20 is 30" followed by a newline.

- **Test Case 5**: Floating-Point Formatting
  - **Input**: `printfk("The value of pi is %.2f\n", 3.14159);`
  - **Expected Output**: "The value of pi is 3.14" followed by a newline (formatted to two decimal places).

- **Test Case 6**: Mixed Formatting
  - **Input**: `printfk("%s bought %d apples for $%.2f each\n", "Bob", 5, 1.25);`
  - **Expected Output**: "Bob bought 5 apples for $1.25 each" followed by a newline.

- **Test Case 7**: Special Characters
  - **Input**: `printfk("Escape sequence: %%\n");`
  - **Expected Output**: "Escape sequence: %" followed by a newline (escaping the % character).

- **Test Case 8**: Empty String
  - **Input**: `printfk("");`
  - **Expected Output**: An empty line (just a newline).

- **Test Case 9**: No Formatting
  - **Input**: `printfk("This is a static message\n");`
  - **Expected Output**: "This is a static message" followed by a newline (no formatting placeholders).

- **Test Case 10**: Large Integer
  - **Input**: `printfk("Large number: %ld\n", 123456789012345);`
  - **Expected Output**: "Large number: 123456789012345" followed by a newline (long integer).
  - ``This last test case give desired output in vim on wsl ubuntu but acts naughty on windows VS Code``
