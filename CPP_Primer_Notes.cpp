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