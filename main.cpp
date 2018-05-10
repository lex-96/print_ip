
/*! \file
    \brief Develop function to print conditional ip address.
    The address can be represented as an arbitrary integer type.
    The representation does not depend on the type sign. Output byte since beginning
    with a symbol . as a separator.
    The address can be represented as a string. It is displayed as is.
    The address can be presented in the form of containers std :: list, std :: vector.
    The contents of the container are displayed element-by-element and are divided . .
*/

#include <iostream>
#include <vector>
#include <list>

#include "print_ip.h"


int main()
{
    try
    {
        print_ip(char(-1), std::cout);
        print_ip(short(0), std::cout);
        print_ip(int(2130706433), std::cout);
        print_ip(long(8875824491850138409), std::cout);
        print_ip(std::string{"144.23.45.67"}, std::cout);
        print_ip(std::vector<int>{117, 28, 235,143}, std::cout);
        print_ip(std::list<int>{17, 46, 250, 98}, std::cout);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

