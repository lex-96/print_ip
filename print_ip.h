/*!
\file ptint_ip.h
\brief Header of definition template print_ip function's
*/

#pragma once

#include <iostream>
#include <string>
#include <type_traits>

#include "is_stl_container.h"


/*!
\brief Template function printing IP address, specified by any integer type
\param[in] out output stream
\param[in] t input IP adress
*/
template <typename T>
typename std::enable_if<is_integral_v<T>>::type print_ip(T t, std::ostream& out)
{
    unsigned char ip[sizeof(T)];
    for (unsigned i = 0; i < sizeof(T); ++i)
    {
        ip[i] = t;
        t >>= 8;
    }
    for (unsigned i = sizeof(T); i != 0; --i)
    {
        out << static_cast<int>(ip[i - 1]);
        if (i != 1)
            out << '.';
    }
    out << std::endl;
}

/*!
\brief Function printing IP address, specified by string type
\param[in] out output stream
\param[in] ip input IP adress
*/
void print_ip(const std::string& ip, std::ostream& out)
{
    out << ip << std::endl;
}


/*!
\brief Template function printing IP address, specified by any stl container
\param[in] out output stream
\param[in] container input IP adress
*/
template <typename T>
typename std::enable_if<(is_stl_container_v<T>) && (is_integral_v<typename T::value_type>)>::type print_ip(const T& container, std::ostream& out)
{
    for(auto it = std::begin(container); it != std::end(container); ++it)
    {
        if(it != std::begin(container))
            out << '.';
        out << *it;
    }
    out << std::endl;
}


