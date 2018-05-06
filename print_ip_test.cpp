#define BOOST_TEST_MODULE test_main
#include <boost/test/included/unit_test.hpp>
#include <sstream>

#include "is_stl_container.h"
#include "print_ip.h"


BOOST_AUTO_TEST_CASE(test_function)
{
    std::stringstream string_buffer;
    print_ip(char(-1), string_buffer);
    print_ip(short(0), string_buffer);
    print_ip(int(2130706433), string_buffer);
    print_ip(long(8875824491850138409), string_buffer);
    print_ip(std::string{"144.23.45.67"}, string_buffer);

    std::string result = "255\n"
                         "0.0\n"
                         "127.0.0.1\n"
                         "123.45.67.89.101.112.131.41\n"
                         "144.23.45.67\n";

    BOOST_CHECK_EQUAL(string_buffer.str(), result);

}

 BOOST_AUTO_TEST_CASE(test_function_with_container)
 {
    std::stringstream string_buffer;
    print_ip(std::vector<int>{117, 28, 235,143}, string_buffer);
    print_ip(std::list<int>{17, 46, 250, 98}, string_buffer);
    std::string result = "117.28.235.143\n"
                         "17.46.250.98\n" ;

    BOOST_CHECK_EQUAL(string_buffer.str(), result);
 }

 BOOST_AUTO_TEST_CASE(test_is_stl_container)
 {
    BOOST_CHECK(is_stl_container_v<std::vector<int>> == true);
    BOOST_CHECK(is_stl_container_v<std::list<int>> == true);
    BOOST_CHECK(is_stl_container_v<double> == false);
    BOOST_CHECK(is_stl_container_v<int> == false);
    BOOST_CHECK(is_stl_container_v<char> == false);
 }


