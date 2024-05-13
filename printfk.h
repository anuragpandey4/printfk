// don't mind my sh*t comments and inexprience with c feel free to give me suggestionssssssssss 

#include <unistd.h>
#include <stdarg.h>

// it simply uses system call write to print whatever is passed in it as a character
// write call uses three arguments  (1 is input , 2nd is address of character to be print, size of stuff to be printed on screen in bytes)
void printCharacter(int character)
{
    if (character == '\0')
        return;
    char ch = (char)character;
    write(1, &ch, 1);
}

// it takes long integer as input just to avoid any large data error
//  I haven't used recursion here because I have skill issue with using recursion in c I constantly get error
//  so i have simply used WHILE loop to store all the numbers in a character array then I have used printcharacter to print the stuff
void printInteger(long integer)
{
    if (integer == 0)
    {
        printCharacter('0');
        return;
    }

    if (integer < 0)
    {
        printCharacter('-');
        integer = -integer;
    }

    char intString[21] = {0};
    int i = 0;

    while (integer != 0)
    {
        intString[i] = (integer % 10) + '0';
        integer = integer / 10;
        i++;
    }
    intString[i] = '\0';
    i--;
    while (i >= 0)
    {
        printCharacter(intString[i]);
        i--;
    }
}

// similar to int
void printLong(unsigned long num)
{
    if (num == 0)
    {
        printCharacter('0');
        return;
    }

    if (num < 0)
    {
        printCharacter('-');
        num = -num;
    }

    char intString[150] = {0};
    int i = 0;

    while (num != 0)
    {
        intString[i] = (num % 10) + '0';
        num = num / 10;
        i++;
    }
    intString[i] = '\0';
    i--;
    while (i >= 0)
    {
        printCharacter(intString[i]);
        i--;
    }
}

// it runs until encounter terminator \0 uses printCharater function to print
void printString(char *string)
{
    while (*string != '\0')
    {
        printCharacter(*(string++));
    }
}

void printFloat(float floatNum, int precision)
{
    if (floatNum < 0)
    {
        printCharacter('-');
        floatNum = -floatNum;
    }
    // i sepate the number and decimal part here
    int integerPart = (int)floatNum;
    float decimalPart = floatNum - integerPart;

    printInteger(integerPart);
    printCharacter('.');

    // i multiply by 10 to get value  just after the point into the number part(0.56 * 10 = 5.6) untile precision
    for (int i = 0; i < precision; i++)
    {
        decimalPart = decimalPart * 10;
    }

    printInteger((int)decimalPart);
}

// if user does give any precision befre f like .2f the we just simply print 45.567 to 45.00
void printFloatNoPrecision(float floatNum)
{
    printInteger(floatNum);
    printString(".00");
}

// i did  it somehow , i got an algorithm from internet that converts number to hexadecimal
// i store  that hexademical as chacter array and print using our simple printCharater() function
void printHexaDecimal(unsigned int num)
{
    if (num == 0)
    {
        printCharacter('0');
        return;
    }
    unsigned int sum, remainder;
    int i, j = 0;
    char hexadecimalnum[100] = {0};

    sum = num;

    while (sum != 0)
    {
        remainder = sum % 16;
        if (remainder < 10)
        {
            hexadecimalnum[j] = 48 + remainder;
            j++;
        }
        else
        {
            hexadecimalnum[j] = 55 + remainder;
            j++;
        }
        sum = sum / 16;
    }
    for (i = j - 1; i >= 0; i--)
    {
        printCharacter(hexadecimalnum[i]);
    }
}

// pass address of the variable in it and it used our hexademical function to it to hexadecima from number and print it with prefix 0x
void printPointer(void *ptr)
{
    printString("0x");
    printHexaDecimal((unsigned long)ptr);
}

// a variadic function because we don't know how many arguments will be stored
// first argument string that and then we ellipses (...) which indicated there are going to be n number of arguments.
int printfk(char *format, ...)
{
    // it creates a list of all the arguments passed it function;
    va_list argv;

    // it points to the first argument (i.e. a character array)
    va_start(argv, format);

    // runs until our character array doesn't gives a terminator
    while (*format != '\0')
    {
        // if we encounter with a % in our format character array
        if (*format == '%')
        {
            ++format;
            switch (*format)
            {
                // va_arg() is a built in macro simply a function that when called gives the value of next argument from the va_list
                // va_arg takes two parameters first is the list name i.e. argv we created and second data type
            case 'c':
                // i have used int instead of char because variadic function implicitly converts char and short to integer to avoid data loss
                // this function simply converts the 'c' with the current argument from argv list to which it points it to
                printCharacter(va_arg(argv, int));
                break;
            case 'd':
                printInteger((va_arg(argv, int)));
                break;
            case 'l':
                format++;
                // here format++ skips d from ld
                printLong((va_arg(argv, unsigned long)));
                break;
            case 's':
                printString(va_arg(argv, char *));
                break;
            case '.':
                format++;
                // i have subtracted - '0' with *format which currents stores any value after "." (like 2) because it gives ascii for number 2
                // if i dont subtract 2 then we will have char '2' from ascii
                int precision = *format - '0';
                float floatArgument = va_arg(argv, double);

                printFloat(floatArgument, precision);
                format++;
                break;
            case 'f':
                format++;
                // printInteger(va_arg(argv, double));
                printFloatNoPrecision(va_arg(argv, double));
                break;
            case 'x':
                printHexaDecimal(va_arg(argv, unsigned int));
                break;
            case 'p':
                // i dont know why we use void when passing pointers but it has something to do not getting error while using different datatypes
                printPointer(va_arg(argv, void *));
                break;
            default:
                printCharacter(*format);
                break;
            }
        }

        else
        {
            printCharacter(*format);
        }

        ++format;
    }
}
