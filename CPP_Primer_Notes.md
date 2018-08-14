# Chapter 1 Gettting Started

## 1.1 Writing a Simple C++ Program

1. A function definition has four elements: a return type, a function name, a (possibly empty) parameter list enclosed in parentheses, and a function body.
2. The main function is required to have a return type of int, which is a type that represents integers. The int type is a **built-in** type, which means that it is one of the types the language defines.
3. On most systems, the value returned from main is a status indicator. A return value of 0 indicates success. A nonzero return has a meaning that is defined by the system. Ordinarily a nonzero return indicates what kind of error occurred.
   
### 1.1.1 Compiling and Executing Our Program
1. Most compilers, including those that come with an IDE, provide a command-line interface. Unless you already know the IDE, you may find it easier to start with the command-line interface. Doing so will let you concentrate on learning C++ first. Moreover, once you understand the language, the IDE is likely to be easier to learn.

#### Program Source File Naming Convention
`.cpp`
#### Running the Compiler from the Command Line
`$ ./a.out` `$ echo $?`
#### Exercises Section 1.1.1
1. `clang++ -Wall CPP_Primer_Notes.cpp -o check.out`
2. The output of `echo $?` command is 255 and the prompt turns red after running the `./check.out` command.

## 1.2 A First Look at Input/Output

Most of the examples in this book use the iostream library. Fundamental to the iostream library are two types named istream and ostream, which repre- sent input and output streams, respectively. A stream is a sequence of characters read from or written to an IO device. The term stream is intended to suggest that the characters are generated, or consumed, sequentially over time.

#### Standard Input and Output Objects
#### A Program That Uses the IO Library
#### Writing to a Steam
#### Using Names from the Standard Library
#### Reading from a Stream
#### Completing the Program
The library defines versions of the input and output operators that handle operands of each of these differing types.

#### Exercise 1.3: Write a program to print *Hello, World* on the standard output.

Note: When we read a stream statement, it is just like a foldering of the line of the code.

```c++
#include <iostream>
int main()
{
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

#### Exercise 1.4: Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

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

#### Exercise 1.5: We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

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

#### Exercise 1.6: Explain whether the following program fragment is legal.

```c++
std::cout << "The sum of " << v1; << " and " << v2;
             << " is " << v1 + v2 << std::endl;
```

#### If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?

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

## 1.3 A Word about Comments

Although the compiler ignores comments, readers of our code do not. Pro- grammers tend to believe comments even when other parts of the system docu- mentation are out of date. An incorrect comment is worse than no comment at all because it may mislead the reader. When you change your code, be sure to update the comments, too!