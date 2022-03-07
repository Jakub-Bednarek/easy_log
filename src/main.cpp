#include <iostream>
#include "EasyLog.hpp"

int main()
{
    Elog::Logger log;
    Elog::Logger other(std::move(log));
    log = std::move(other);
    return 0;
}