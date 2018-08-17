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