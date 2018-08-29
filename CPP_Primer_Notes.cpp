#include <iostream>

int main()
{
    // Note that 'typeid' will lose the 'const' qualifier and reference

    // (a) 'ip' is 'int *', 'i' is 'int', r is a reference
    {
      int* ip, i, &r = i;
      std::cout << "(a)" << std::endl;
      std::cout << "ip\t" << typeid(ip).name() << std::endl;
      std::cout << "i\t" << typeid(i).name() << std::endl;
      std::cout << "r\t" << typeid(r).name() << std::endl;
      
    }
    {
        int i, *ip = 0;  // `i` is `int`, `ip` is `int *`
        std::cout << "(b)" << std::endl;
        std::cout << "i\t" << typeid(i).name() << std::endl;
        std::cout << "ip\t" << typeid(ip).name() << std::endl;
    }
    {
        int* ip, ip2;  // `ip` is `int *`, `ip2` is `int`
        std::cout << "(c)" << std::endl;
        std::cout << "ip\t" << typeid(ip).name() << std::endl;
        std::cout << "ip2\t" << typeid(ip2).name() << std::endl;
    }

    return 0;
}