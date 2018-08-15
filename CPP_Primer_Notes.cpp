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