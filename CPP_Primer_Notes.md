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
        - [2.2.2 Variable Declarations and Definitions](#222-variable-declarations-and-definitions)
        - [2.2.3 Identifiers](#223-identifiers)
        - [2.2.4 Scope of a Name](#224-scope-of-a-name)
    - [2.3 Compound Types](#23-compound-types)
        - [2.3.1 References](#231-references)
        - [2.3.2 Pointers](#232-pointers)

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

#### 1.4.1 The `while` Statement

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
> Undefined behavior results from errors that the compiler is not required (and sometimes is not able) to detect. Even if the code compiles, a program that executes an undefined expression is in error.

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

**List Initialization**

Only list initialization checks for the informaiton loss is for the sake of backward compatibility, otherwise old c++ code would not be able to directly compiled anymore.

**Default Initialization**

> Note: Uninitialized objects of built-in type defined inside a function body have undefined value. Objects of class type that we do not explicitly initialize have a value that is defined by the class.

**Exercise 2.9:** Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.

```c++
#include <iostream>

int main () {
  // (a) std::cin >> int input_value;
  // Error: variable must be defined before used for input
  int input_value;
  std::cin >> input_value;

  // (b) int i = { 3.14 };
  // Error: loss information in list initialization
  // warning: implicit conversion from 'double' to 'int'
     changes value from 3.14 to 3 [-Wliteral-conversion]
  // so we only get a warning here

  // (c) double salary = wage = 9999.99;
  // Error: identifier "wage" is undefined
  double salary, wage;
  salary = wage = 9999.99;

  // (d) int i = 3.14;
  // the value of i here is 3

  return 0;
}
```

**Exercise 2.10:** What are the initial values, if any, of each of the following variables?

```c++
#include <string>

std::string global_str; // Empty string object
int global_int; // 0
int main() {
    int local_int; // Undefined value
    std::string local_str; // Empty string object

    return 0;
}
```

#### 2.2.2 Variable Declarations and Definitions

**CAUTION: UNINITIALIZED VARIABLES CAUSE RUN-TIME PROBLEMS**

> It is an error to provide an initializer on an extern inside a function.

This code compiles fine:

```c++
extern int i = 10;

void test()
{
    std::cout << "Hi" << i << std::endl;
}
```

While this one gives an error:

```c++
void test()
{
    extern int i = 10;
    std::cout << "Hi" << i << std::endl;
}
```

> error: 'i' has both 'extern' and initializer

By adding an initialiser to the declaration, it becomes a definition of the global variable. It's equivalent to the same definition without extern, which is what your book means when it says it "overrides the extern".

While global variables can be declared (using extern) inside a function, they cannot be defined there, only at namespace scope. That's why the second snippet is an error.

If you want to know why the designers of C (whence these rules came to C++) chose to allow declarations but not definitions here, then I'm afraid I don't know the language's history in enough detail to answer.

**Note:** Since "Variables must be defined exactly once but can be declared many times.", the compiler can always locate the position where the variable is defined, no matter it is inside a function or outside a function scope.

However the designer seems want to make it more clear here, that only global defined variables can be shared across files. Thereby, if a variable is modified by the keyword extern, then it denote that this varible should be global defined and hence cannot be defined locally in a function body.

**Note:** Global defined variables can also be considered as global variables and on the same token, local defined variables refer to local variables actually.

**Exercise 2.11:** Explain whether each of the following is a declaration or a definition:

```c++
// (a) this is a definition
extern int ix = 1024;
// (b) this is a definition
int iy;
// (c) this is a declaration
extern int iz;
```
**KEY CONCEPT: STATIC TYPING**

#### 2.2.3 Identifiers

> Identifiers in C++ can be composed of letters, digits, and the underscore character. The language imposes no limit on name length. Identifiers must begin with either a letter or an underscore. Identifiers are case-sensitive; upper- and lowercase letters are distinct:

> Why can't variable names start with numbers?

The short answer is: forbid this form of name can ensure the readibility of the code.

> Because then a string of digits would be a valid identifier as well as a valid number.

```c++
int 17 = 497;
int 42 = 6 * 9;
String 1111 = "Totally text";
```

> Well, what if they said variables cannot be only numbers. Then what?

> It'd take me longer to come up with a regular expression for the lexer to pick up identifiers using that rule, if it's even possible, so I can see why no language has ever been implemented that way, in addition to the reasons given in other answers.

> I think the people writing compilers could figure it out...

> If it had to be numbers+alpha, then you could still do String 0x123 = "Hello World". Unless you state that variable names are "numbers+alpha that don't parse to a valid numeric designation".

**Conventions for Variable Names**

> Naming conventions are most useful when followed consistently.

**Exercise 2.12:**
Which, if any, of the following names are invalid?

```c++
int _;  // should be an error according to the book, however not
int main()
{
    // (a) error: double is a reserved keyword
    // for the language's own use
    int double = 3.14;
    // (b) _ is a legal identifier
    int _;
    // (c) - may not be used in the name of an identifier
    int catch-22;
    // (d) error: begin with number
    int 1_or_2 = 1;
    // (e) Double is a legal identifier
    double Double = 3.14;

    return 0;
}
```

#### 2.2.4 Scope of a Name

**ADVICE: DEFINE VARIABLES WHERE YOU FIRST USE THEM**

**Nested Scopes**

**Warning:**  It is almost always a bad idea to define a local variable with the same name as a global variable that the function uses or might use.

**Exercise 2.13:** What is the value of j in the following program?

```c++
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

Answer: The value of j is 100, since i declared in the outer scope is redefined in the inner scope with the value 100.

**Exercise 2.14:** Is the following program legal? If so, what values are printed?

```c++
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;
```

Answer: It is a legal program and the values printed are `100 45`.

### 2.3 Compound Types

> A compound type is a type that is defined in terms of another type. C++ has several compound types, two of which—references and pointers—we’ll cover in this chapter.

> More generally, a declaration is a base type followed by a list of declarators. Each declarator names a variable and gives the variable a type that is related to the base type.

#### 2.3.1 References

**Note:**
The new standard introduced a new kind of reference: an “rvalue reference,” which we’ll cover in § 13.6.1 (p. 532). These references are primarily intended for use inside classes. Technically speaking, when we use the term reference, we mean “lvalue reference.”

**A Reference Is an Alias**

**Note:** A reference is not an object. Instead, a reference is _just another name for an already existing object_.

**The definition of an object**

In this book, we’ll follow the more general usage that an *object* is a region of memory that can contain data and has a type.

> Because references are not objects, we may not define a reference to a reference.

**Reference Definitions**

> With two exceptions that we’ll cover in § 2.4.1 (p. 61) and § 15.2.3 (p. 601), the type of a reference and the object to which the reference refers must match exactly.

> Moreover, for reasons we’ll explore in § 2.4.1, a reference may be bound only to an object, not to a literal or to the result of a more general expression:

```c++
int &refVal4 = 10; // error: initializer must be an object

double dval = 3.14;

int &refVal5 = dval; // error: initializer must be an 'int' object
```

One reason why a reference may not be bound to a literal is that, normally literal does not occupy any memory space to which the reference can refer.

**Exercise 2.15:** Which of the following definitions, if any, are invalid? Why?

```c++
int main()
{
    // (a) this definition is valid
    int ival = 1.01;

    /* (b) this definition is invalid,
     *     because a reference may be bound only to an object,
     *     not to a literal 
     */
    int &rval1 = 1.01; // error: initializer must be an object

    // (c) this definition is valid
    int &rval2 = ival;

    // (d) error: a reference must be initialized when defined
    int &rval3;

  return 0;
}
```

**Exercise 2.16:** Which, if any, of the following assignments are invalid? If they are valid, explain what they do.

```c++
int main()
{
  int i = 0, &r1 = i;
  double d = 0, &r2 = d;

  r2 = 3.14159;  // (a) d = 3.14159
  r2 = r1;  // (b) d = i
  i = r2;  // (c) i = d
  r1 = d;  // (d) i = d

  return 0;
}
```

```c++
#include <iostream>
int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;

    std::cout << "the values of i, r1, d, r2 are: "
                << i << " " << r1 << " " << d << " " << r2 << " " << std::endl;
    r2 = 3.14159;  // (a) d = 3.14159
    std::cout << "(a) the values of i, r1, d, r2 are: "
                << i << " " << r1 << " " << d << " " << r2 << " " << std::endl;
    r2 = r1;  // (b) d = i
    std::cout << "(b) the values of i, r1, d, r2 are: "
                << i << " " << r1 << " " << d << " " << r2 << " " << std::endl;
    i = r2;  // (c) i = d
    std::cout << "(c) the values of i, r1, d, r2 are: "
                << i << " " << r1 << " " << d << " " << r2 << " " << std::endl;
    r1 = d;  // (d) i = d
    std::cout << "(d) the values of i, r1, d, r2 are: "
                << i << " " << r1 << " " << d << " " << r2 << " " << std::endl;

    return 0;
}
```

> the values of i, r1, d, r2 are: 0 0 0 0\
(a) the values of i, r1, d, r2 are: 0 0 3.14159 3.14159\
(b) the values of i, r1, d, r2 are: 0 0 0 0\
(c) the values of i, r1, d, r2 are: 0 0 0 0\
(d) the values of i, r1, d, r2 are: 0 0 0 0


**Exercise 2.17:** What does the following code print?
```c++
    int i, &ri = i;
    i = 5; ri = 10;
    std::cout << i << " " << ri << std::endl;
```

Answer: `10 10`.

3. 允许对指针赋值和拷贝
pointer correspond to assember address label and can be compared with java ref
pi2 points to ival so its value is not zero the condition is true

#### 2.3.2 Pointers

**Exercise 2.18:** Write code to change the value of a pointer. Write code to change the value to which the pointer points.

```c++
#include <iostream>

int main()
{
    int i, j = 0;
    int *ip = &i;

    *ip = 10;
    std::cout << i << " " << *ip << std::endl; // 10 10
    i = 5;
    std::cout << i << " " << *ip << std::endl; // 5 5

    ip = &j;
    std::cout << j << " " << *ip << std::endl; // 0 0

    return 0;
}
```
**Exercise 2.19:** Explain the key differences between pointers and references.

**Answer:**

A pointer is an object whose value is the adress of another object.

A reference is not an object. It is an alias of another object.

**Exercise 2.20:** What does the following program do?

```c++
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```

```c++
#include <iostream>

int main()
{
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1; // i = i * i
    std::cout << i << std::endl; // 1764

    return 0;
}
```


**Exercise 2.21:** Explain each of the following definitions. Indicate whether any are illegal and, if so, why.

```c++
int i = 0;
// (a) error: 'dp' can only hold pointer that points to 'double' type variable
double* dp = &i;
// (b) error: cannot initialize a variable of type 'int *' with an lvalue of type 'int'
//     a pointer can only hold an address of object
int *ip = i;
// (c) this is a legal definition
int *p = &i;
```

**Exercise 2.22:** Assuming p is a pointer to int, explain the following code:

```c++
if (p) // ...
if (*p) // ...
```

**Answer:**

`if (p)` means if the pointer p is not a nullpointer

`if (*p)` means if the value, to which the pointer points, is not false or will not be considered as false

**Exercise 2.23:** Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

**Answer:**
> No, you can't. Why? Because it would be expensive to maintain meta data about what constitutes a valid pointer and what doesn't, and in C++ you don't pay for what you don't want.

> And you don't want to check whether a pointer is valid, because you know where a pointer comes from, either because it's a private part of your code that you control, or because you specified it in your external-facing contracts.

See answer [here](https://stackoverflow.com/a/17202622).

However, a _smart_ pointer can be used to tell if it points to a valid value.

**Exercise 2.24:** Why is the initialization of p legal but that of lp illegal?

```c++
int i = 42;
// the initialization of p is legal
// because that a 'void *' pointer can point to any type 
void *p = &i;
// the initialization of lp is illegal
// since that a 'long *' pointer can not point to 'int'
long *lp = &i;
```
