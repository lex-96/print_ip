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
    print_ip(std::string{"144.23.45.67.-123.346"}, string_buffer);

    std::string result = "255\n"
                         "0.0\n"
                         "127.0.0.1\n"
                         "123.45.67.89.101.112.131.41\n"
                         "144.23.45.67.-123.346\n";

    BOOST_CHECK_EQUAL(string_buffer.str(), result);

    std::stringstream string_buffer_int;
    print_ip(static_cast<int64_t>(0x00FF00FF00FF8000), string_buffer_int);
    print_ip(static_cast<int64_t>(-0xFF00FF80), string_buffer_int);
    print_ip(static_cast<int64_t>(0x00FFFFFF00), string_buffer_int);

    print_ip(static_cast<int32_t>(0xFFFF), string_buffer_int);
    print_ip(static_cast<int32_t>(0xFFFF00FF), string_buffer_int);
    print_ip(static_cast<int32_t>(0x00FF00FF), string_buffer_int);

    print_ip(static_cast<int16_t>(0x00FF), string_buffer_int);
    print_ip(static_cast<int16_t>(-0xFF00), string_buffer_int);
    print_ip(static_cast<int16_t>(0xFFFF), string_buffer_int);

    print_ip(static_cast<int8_t>(0x00), string_buffer_int);
    print_ip(static_cast<int8_t>(0xFF), string_buffer_int);
    print_ip(static_cast<int8_t>(0x80), string_buffer_int);
    print_ip(static_cast<int8_t>(-0x01), string_buffer_int);

    std::string result_int = "0.255.0.255.0.255.128.0\n"
                         "0.0.0.0.0.255.0.128\n"
                         "0.0.0.0.255.255.255.0\n"
                         "0.0.255.255\n"
                         "255.255.0.255\n"
                         "0.255.0.255\n"
                         "0.255\n"
                         "1.0\n"
                         "255.255\n"
                         "0\n"
                         "255\n"
                         "128\n"
                         "255\n";

    BOOST_CHECK_EQUAL(string_buffer_int.str(), result_int);
}

 BOOST_AUTO_TEST_CASE(test_function_with_container)
 {
    std::stringstream string_buffer;
    print_ip(std::vector<int>{117, 28, -235,143, 674 }, string_buffer);
    print_ip(std::list<int>{17, 46, 250, 98, 344, -15 }, string_buffer);
    print_ip(std::vector<int16_t>{250, 28, 235,143}, string_buffer);
    print_ip(std::list<int64_t>{17, 46, 250, 98}, string_buffer);
    print_ip(std::vector<std::string>{"250", "15","4"}, string_buffer);
    print_ip(std::list<std::string>{"123", "564", "23123", "234", "52"}, string_buffer);

    std::string result = "117.28.-235.143.674\n"
                         "17.46.250.98.344.-15\n"
                         "250.28.235.143\n"
                         "17.46.250.98\n"
                         "250.15.4\n"
                         "123.564.23123.234.52\n";

    BOOST_CHECK_EQUAL(string_buffer.str(), result);

    std::stringstream buffer_container_in_container;
    print_ip(std::list<std::vector<int>>{{1,3,4}, {2,5,6}, {123,443,543}}, buffer_container_in_container);
    print_ip(std::list<std::vector<int>>{{194}, {65}, {123},{221}}, buffer_container_in_container);
    print_ip(std::vector<std::list<int>>{{546,4324,432, 653 ,524}, {23,-546}, {67,143,244, 192}}, buffer_container_in_container);
    print_ip(std::list<std::vector<std::string>>{{"148","324"}, {"31"}, {"2475"}}, buffer_container_in_container);
    print_ip(std::vector<std::list<std::string>>{{"134", "123"}, {"34", "-78"}}, buffer_container_in_container);

    std::string result_container = "1.3.4.2.5.6.123.443.543\n"
                         "194.65.123.221\n"
                         "546.4324.432.653.524.23.-546.67.143.244.192\n"
                         "148.324.31.2475\n"
                         "134.123.34.-78\n";

    BOOST_CHECK_EQUAL(buffer_container_in_container.str(), result_container);
 }

 BOOST_AUTO_TEST_CASE(test_is_stl_container)
 {
    BOOST_CHECK(is_stl_container_v<std::vector<int>> == true);
    BOOST_CHECK(is_stl_container_v<std::list<int>> == true);
    BOOST_CHECK(is_stl_container_v<std::vector<std::list<int>>> == true);
    BOOST_CHECK(is_stl_container_v<std::list<std::vector<int>>> == true);
    BOOST_CHECK(is_stl_container_v<double> == false);
    BOOST_CHECK(is_stl_container_v<int> == false);
    BOOST_CHECK(is_stl_container_v<char> == false);
 }


