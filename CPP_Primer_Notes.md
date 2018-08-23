<!-- TOC -->

- [Chapter 1 Gettting Started](#chapter-1-gettting-started)
    - [1.1 Writing a Simple C++ Program](#11-writing-a-simple-c-program)
        - [1.1.1 Compiling and Executing Our Program](#111-compiling-and-executing-our-program)
    - [1.2 A First Look at Input/Output](#12-a-first-look-at-inputoutput)
    - [1.3 A Word about Comments](#13-a-word-about-comments)
    - [1.4 Flow of Control](#14-flow-of-control)
            - [1.4.1 The `while` Statement](#141-the-while-statement)
        - [1.4.2 The for Statement](#142-the-for-statement)
        - [1.4.3 Reading an Unknown Number of Inputs](#143-reading-an-unknown-number-of-inputs)
        - [1.4.4 The if Statement](#144-the-if-statement)
    - [1.5 Introducing Classes](#15-introducing-classes)
        - [1.5.1 The Sales_item Class](#151-the-salesitem-class)
        - [1.5.2 A First Look at Member Functions](#152-a-first-look-at-member-functions)
    - [1.6 The Bookstore Program](#16-the-bookstore-program)
- [Chapter 2 Variables and Basic Types](#chapter-2-variables-and-basic-types)
    - [2.1 Primitive Built-in Types](#21-primitive-built-in-types)
        - [2.1.1 Arithmetic Types](#211-arithmetic-types)
        - [2.1.2 Type Conversions](#212-type-conversions)
        - [2.1.3 Literals](#213-literals)
    - [2.2 Variables](#22-variables)
        - [2.2.1 Variable Definitions](#221-variable-definitions)

<!-- /TOC -->

## Chapter 1 Gettting Started

### 1.1 Writing a Simple C++ Program

1. A function definition has four elements: a return type, a function name, a (possibly empty) parameter list enclosed in parentheses, and a function body.
2. The main function is required to have a return type of int, which is a type that represents integers. The int type is a **built-in** type, which means that it is one of the types the language defines.**
3. On most systems, the value returned from main is a status indicator. A return value of 0 indicates success. A nonzero return has a meaning that is defined by the system. Ordinarily a nonzero return indicates what kind of error occurred.
   
#### 1.1.1 Compiling and Executing Our Program
> Most compilers, including those that come with an IDE, provide a command-line interface. Unless you already know the IDE, you may find it easier to start with the command-line interface. Doing so will let you concentrate on learning C++ first. Moreover, once you understand the language, the IDE is likely to be easier to learn.

**Exercise 1.1:** Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

**Program Source File Naming Convention**

`.cpp`

**Running the Compiler from the Command Line**

`$ ./a.out` `$ echo $?`

**Exercise 1.2:** Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

1. `clang++ -Wall CPP_Primer_Notes.cpp -o check.out`
2. The output of `echo $?` command is 255 and the prompt turns red after running the `./check.out` command.

### 1.2 A First Look at Input/Output

> Most of the examples in this book use the iostream library. Fundamental to the iostream library are two types named istream and ostream, which repre- sent input and output streams, respectively. A stream is a sequence of characters read from or written to an IO device. The term stream is intended to suggest that the characters are generated, or consumed, sequentially over time.

**Standard Input and Output Objects**

**A Program That Uses the IO Library**

**Writing to a Steam**

**Using Names from the Standard Library**

**Reading from a Stream**

**Completing the Program**

> The library defines versions of the input and output operators that handle operands of each of these differing types.

**Exercise 1.3:** Write a program to print *Hello, World* on the standard output.

Note: When we read a stream statement, it is just like a foldering of the line of the code.

```c++
#include <iostream>
int main()
{
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

**Exercise 1.4:** Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

```c++
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2
              << " is " << v1 * v2 << std::endl;
    return 0;
}
```

**Exercise 1.5:** We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

```c++
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:";
    std::cout << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1;
    std::cin >> v2;
    std::cout << "The sum of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 + v2;
    std::cout << std::endl;
    return 0;
}
```

**Exercise 1.6: Explain whether the following program fragment is legal.**

```c++
std::cout << "The sum of " << v1; << " and " << v2;
             << " is " << v1 + v2 << std::endl;
```

**If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?**

The program is not legal, the error message is:
> CPP_Primer_Notes.cpp:7:39: error: expected expression
```c++
    std::cout << "The sum of " << v1; << " and " << v2;
                                      ^
```
> CPP_Primer_Notes.cpp:8:14: error: expected expression
```c++
             << " is " << v1 + v2 << std::endl;
             ^                                  ^
``` 

The output operator expect here an *ostream* object as left-hand operand.

### 1.3 A Word about Comments

Although the compiler ignores comments, readers of our code do not. Pro- grammers tend to believe comments even when other parts of the system docu- mentation are out of date. An incorrect comment is worse than no comment at all because it may mislead the reader. When you change your code, be sure to update the comments, too!

**Kinds of Comments in C++**
**Comment Pairs Do Not Nest**

**Exercise 1.7: Compile a program that has incorrectly nested comments.**

**Exercise 1.8: Indicate which, if any, of the following output statements are legal:**

```c++
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```

Line 3 does not work, the error message:

`clang++ -Wall CPP_Primer_Notes.cpp -o check.out`

```
CPP_Primer_Notes.cpp:4:23: warning: missing terminating '"' character
      [-Winvalid-pp-token]
   std::cout << /* "*/" */;
                      ^
CPP_Primer_Notes.cpp:4:23: error: expected expression
1 warning and 1 error generated.
```

### 1.4 Flow of Control

##### 1.4.1 The `while` Statement

A block is a sequence of zero or more statements enclosed by curly braces. 

**Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to 100.**

```c++
#include <iostream>
int main()
{
    int sum = 0, val = 50;
    // keep executing the while as long as 
    // val is less than or equal to 10
    while (val <= 100)
    {
        sum += val; // assigns sum + val to sum
        ++val; // add 1 to val
    }
    std::cout << "Sum of 50 to 100 inclusive is "
                << sum << std::endl;
    return 0;
}
```

**Exercise 1.10: In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.**

```c++
#include <iostream>
int main()
{
    int val = 10;

    while (val >= 0)
    {
        std::cout << val << " ";
        --val;
    }

    std::cout << std::endl;
    return 0;
}
```

**Exercise 1.11: Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.**

```c++
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;

    int first = 0, second = 0;

    std::cin >> first >> second;

    if(first > second)
    {
        int temp = first;
        first = second;
        second = temp;
    }

    while (first <= second)
    {
        std::cout << first << " ";
        ++first;
    }

    std::cout << std::endl;
    return 0;
}
```

#### 1.4.2 The for Statement

**Exercise 1.12: What does the following for loop do? What is the final value of sum?**

```c++
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```

```c++
#include <iostream>
int main()
{
    int sum = 0;
    for (int i = -100; i <= 100; ++i)
        sum += i;
    std::cout << sum << std::endl;
    return 0;
}
```

The for loop calculate the sum of the numbers from -100 to 100 inclusive. The final value of sum is obviously 0.

**Exercise 1.13: Rewrite the first two exercises from § 1.4.1 (p. 13) using for loops.**

```c++
#include <iostream>
int main()
{
    int sum = 0;
    for(int i = 50; i < 101; i++)
    {
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}
```

```c++
#include <iostream>
int main()
{
    for(int i = 10; i > -1; i--)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

**Exercise 1.14: Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?**

`for` has a scope where you can define temporary variables and used inside loop.

`while` is simple and appropriate for situations where the loop time is unknown before the loop.

**Exercise 1.15: Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.**

#### 1.4.3 Reading an Unknown Number of Inputs

```c++
#include <iostream>
int main()
{
    int sum = 0, value =0;
    // read until end-of-file, 
    // calculating a running total of all values read 
    while (std::cin >> value)
        sum += value; // equivalent to sum = sum + value
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}
```

> That expression reads the next number from the standard input and stores that number in value. The input operator (§ 1.2, p. 8) returns its left operand, which in this case is `std::cin`. This condition, therefore, tests `std::cin`.

> When we use an istream as a condition, the effect is to test the state of the stream. If the stream is valid —- that is, if the stream hasn’t encountered an error —- then the test succeeds. An istream becomes invalid when we hit end-of-file or encounter an invalid input, such as reading a value that is not an integer. An istream that is in an invalid state will cause the condition to yield false.

There are three points here should be mentioned:

1. We say istream here refers to an object of the type istream.
2. The reason why reading a value that is not an integer can make the state of the istream become invalid is that, `std::cin >> value` and variable value has the type int, so we suppose to provide only integer values to it.
3. Hit end-of-file here means that the user has hit ^D on the command line to send a EOF signal to the istream.

**Entering an end-of-file from the keyboard**
**Compilation revisited**
1. Syntax errors
2. Type errors
3. Declaration errors

#### 1.4.4 The if Statement

Like most languages, C++ provides an **if statement** that supports conditional execution.

```c++
#include <iostream>

int main()
{
    // currVal is the number we're counting;
    // we'll read new values into val
    int currVal = 0, val = 0;

    // read first number 
    // and ensure that we have data to process
    if (std::cin >> currVal)
    {
        // store the count for the current value
        // we're processing
        int cnt = 1;

        // read the remaining numbers
        while (std::cin >> val)
        {
            // if the values are the same
            // add 1 to cnt
            if (val == currVal)
                ++cnt;
            // otherwise, print the count
            // for the previous value
            else
            {
                std::cout << currVal << " occurs "
                            << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }   // while loop ends here
        // remember to print the count for the last value
        // in the file
        std::cout << currVal << " occurs "
                    << cnt << " times" << std::endl;
    }   // outermost if statement ends here
    return 0;
}
```

**Exercise 1.17: What happens in the program presented in this section if the input val- ues are all equal? What if there are no duplicated values?**

**Exercise 1.18: Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.**

**Exercise 1.19: Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.**

### 1.5 Introducing Classes

To use a class we need to know three things:
* What is its name?
* Where is it defined?
* What operations does it support?

#### 1.5.1 The Sales_item Class

To use a class, we need not care about how it is
implemented. Instead, what we need to know is what operations objects of that
type can perform.

**Reading and Writing `Sales_item`s**
**Adding `Sales_item`s**

```c++
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    // read a pair of transactions
    std::cout << item1 + item2 << std::endl;
    // print their sum
    return 0;
}
```

> It’s worth noting how similar this program looks to the one on page 6: We read two inputs and write their sum. What makes this similarity noteworthy is that instead of reading and printing the sum of two integers, we’re reading and printing the sum of two Sales_item objects.

What makes this similarity noteworthy is the unsimilarity (difference) between these two programs.

**Exercise 1.20: http://www.informit.com/title/0321714113 contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.**

```c++
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item;

    while(std::cin >> item)
    {
        std::cout << item;
        std::cout << std::endl;
    }

    return 0;
}
```

**Exercise 1.21: Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.**

```c++
#include <iostream>
#include "include/Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
    Sales_item item1, item2;
    cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn())
        cout << item1 + item2 << endl;
    else
        cerr << "Different ISBN." << endl;
}
```

**Exercise 1.22: Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.**

The key point of this exercise is that, we would not need to save all the read transactions in a suitable data structure, instead of that, we continuously update the sum variable like an end-recursion.

```c++
#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main()
{
    Sales_item item;
    string isbn;
    Sales_item sum;

    if (cin >> item)
    {
        sum = item;
        isbn = item.isbn();

        while(cin >> item)
        {
            if(item.isbn() == sum.isbn())
            {
               sum += item;
            }
            else
            {
                cerr << "Different ISBN." << endl;
                return 1;
            }
        }
    }
    else
    {
        cerr << "No Data." << endl;
        return 1;
    }

    cout << sum << endl;
    return 0;
}
```

#### 1.5.2 A First Look at Member Functions

```c++
#include <iostream>
#include "Sales_item.h"

int main()
{
   Sales_item item1, item2;
   std::cin >> item1 >> item2;
   // first check that item1 and item2 represent the same book
   if (item1.isbn() ==  item2.isbn()) 
   {
       std::cout << item1 + item2 << std::endl;
       return 0;    // indicate success
   }
   else
   {
        std::cerr << "Data must refer to same ISBN"
                    << std::endl;
        return -1;  // indicate failure 
   }
}
```

**What Is a Member Function?**

**Exercise 1.23: Write a program that reads several transactions and counts how many transactions occur for each ISBN.**

```c++
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currValItem, valItem;
    if (std::cin >> currValItem)
    {
        int cnt = 1;
        while (std::cin >> valItem)
        {
            if (valItem.isbn() == currValItem.isbn())
            {
                currValItem += valItem;
                ++cnt;
            }
            else
            {
                std::cout << currValItem << " occurs " << cnt << " time(s) " << std::endl;
                currValItem = valItem;
                cnt = 1;
            }
        }
        std::cout << currValItem << " occurs "<< cnt << " time(s) " << std::endl;
    }
    return 0;
}
```

**Exercise 1.24: Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.**

> The records for each ISBN should be grouped together.

This is just an assumption that the sales transaction file should follow.

### 1.6 The Bookstore Program

```c++
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total; // variable to hold data for the next transaction
    // read the first transaction and ensure that there are data to process
    if (std::cin >> total)
    {
        Sales_item trans; // variable to hold the running sum
        //  read and process the remaining transactions
        while (std::cin >> trans)
        {
            //  if we're still processing the same book
            if (total.isbn() == trans.isbn())
                total += trans; //  update the running total
            else
            {
                //  print results for the previous book
                std::cout << total << std::endl;
                total = trans; //  total now refers to the next book
            }
        }
        std::cout << total << std::endl; // print the last transaction
    }
    else
    {
        //  no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1; //  indicate failure
    }
    return 0;
}
```

**Exercise 1.25: Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this section.**

## Chapter 2 Variables and Basic Types
### 2.1 Primitive Built-in Types

#### 2.1.1 Arithmetic Types
Table 2.1: C++: Arithmetic Types

**Machine-Level Representation of the Built-In Types**

**Signed and Unsigned Types**
> Unlike the other integer types, there are three distinct basic character types: char,signed char,and unsigned char. Inparticular,char is not the same type as signed char. **Although there are three character types, there are only two representations: signed and unsigned.** The (plain) char type uses one of these representations. Which of the other two character representations is equivalent to char depends on the compiler.

There are three character types in total, but one of them, the char type may be equivalent to either signed char, or unsigned char, depends on the compiler.

> The standard does not define how signed types are represented, but does spec- ify that the range should be evenly divided between positive and negative values.

e.g. 1'complement or 2'complement number can be used

**Advice: Deciding Which Type to Use**

**EXERCISES SECTION 2.1: What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?**

1. the number of bits are different
   
  Type        | Minimum Size | Minimum Number Range
  ------------|--------------|--------------------------------
  `int`       | 16 bits      | -32767 ~ +32767
  `long`      | 32 bits      | -2,147,483,647 ~ +2,147,483,647
  `long long` | 64 bits      | -9.22 * 10^18 ~ +9.22 * 10^18
  `short`     | 16 bits      | -32767 ~ +32767

2. the interpretations are distinct
   
    A signed type represents negative or positive numbers (including zero).

    An unsigned type represents only values greater than or equal to zero.

3. the number of significant digits are not the same

  Type     | Minimum Size
  ---------|----------------------------------------
  `float`  | 6 significant digits (usually 32 bits)
  `double` | 10 significant digits (usually 32 bits)

**Exercise 2.2: To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.**

rate: `float`, principal: `long long`, payment: `long long`.

The rate is usually a floating-point number with 4 significant digits. The principal and payment are integral usually less than 1 trillion.

#### 2.1.2 Type Conversions

**Advice: avoid undefined and implementation-defined behavior**
> Undefined behavior results from errors that the compiler is not required (and some- times is not able) to detect. Even if the code compiles, a program that executes an undefined expression is in error.

**Expressions Involving Unsigned Types**

**Caution: Don't mix signed and unsigned types**

> It is essential to remember that signed values are automatically converted to unsigned.

**Exercise 2.3: What output will the following code produce?**

```c++
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl; // 32
    std::cout << u - u2 << std::endl; // 4294967264, assume that an integer occupies 32 bits
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl; // 32
    std::cout << i - i2 << std::endl; // -32
    std::cout << i - u << std::endl; // 0
    std::cout << u - i << std::endl; // 0
```

```c++
#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl; // 32
    std::cout << u - u2 << std::endl; // 4294967264, assume that an integer occupies 32 bits
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl; // 32
    std::cout << i - i2 << std::endl; // -32
    std::cout << i - u << std::endl; // 0
    std::cout << u - i << std::endl; // 0
    return 0;
}
```

**Exercise 2.4: Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.**

#### 2.1.3 Literals
> A value, such as 42, is known as a literal because its value self-evident. Every literal has a type. The form and value of a literal determine its type.

**Integer and Floating-Point Literals**

**Character and Character String Literals**

**Escape Sequence**

> As with an escape sequence defined by the language, we use these escape sequences as we would *use* any other character:

**Specifying the Type of a Literal**

For Character and Character String Literals u8's corresponding type is char, which means that every character within the array has this type.

**Boolean and Pointer Literals**

**Exercise 2.5:**
Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:

```c++
int main()
{
  // (a)
  'a';   // character literal, type is `char`
  L'a';  // wide character literal, type is `wchar_t`
  "a";   // character string literal, not a primitive buid-in type
  L"a";  // wide character string literal, not a primitive buid-in type

  // (b)
  10;    // integral literal, type is `int`
  10u;   // unsigned integral literal, type is `unsigned int`
  10L;   // integral literal, type is `long int`
  10uL;  // unsigned integral literal, type is `unsigned long int`
  012;   // octal integral literal, type is `int`
  0xC;   // hexadecimal integral literal, type is `int`

  // (c)
  3.14;   // floating-point literal, type is `double`
  3.14f;  // floating-point literal, type is `float`
  3.14L;  // floating-point literal, type is `long double`

  // (d)
  10;     // integral literal, type is `int`
  10u;    // unsigned integral literal, type is `unsigned int`
  10.;    // floating-point literal, type is `double`
  10e-2;  // floating-point literal, type is `double`

  return 0;
}
```

**Eercise 2.6:**
What, if any, are the differences between the following definitions:

```c++
int main()
{
  int month = 9, day = 7;   // OK
  int month1 = 09, day1 = 07;
  /* Error: the digits of octal integral literal
   * should be within the scope of 0-7
   */

  return 0;
}
```

**Exercise 2.7:**
What values do these literals represent? What type does each have?

```c++
int main() {
    std::cout << "Who goes with F\145rgus?\012";
    /* output: Who goes with Fergus?
     * \012 is the line feed character
     * type: character string literal, containing two octal escape sequences
     * not a primitive buid-in type
     */ 

    3.14e1L;  // floating-point literal, type is `long double`
    1024f;  // floating-point literal, type is `float`
    3.14L;  // floating-point literal, type is `long double`

  return 0;
}
```

**Exercise 2.8:**
Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.

```c++
#include <iostream>
int main()
{
    std::cout << "2\115\12" << std::endl;
    return 0;
}
```

```c++
#include <iostream>
int main()
{
    std::cout << "2\t\115\12" << std::endl;
    return 0;
}
```

### 2.2 Variables

> A variable provides us with named storage that our programs can manipulate.

> The type determines the size and layout of the variable’s memory, the range of values that can be stored within that memory, and the set of operations that can be applied to the variable.

#### 2.2.1 Variable Definitions

**Terminology: What is an object?**
> C++ programmers tend to be cavalier in their use of the term object. Most generally, an object is a region of memory that can contain data and has a type.

**Initializers**