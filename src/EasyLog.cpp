#include "EasyLog.hpp"

namespace Elog
{
    Logger::Logger()
    {
        std::cout << "Constr";
    }

    Logger::~Logger()
    {
        std::cout << "Dtor";
    }

    Logger::Logger(Logger&& other)
    {
        std::cout << "Move constr";
    }

    Logger& Logger::operator=(Logger&& other)
    {
        std::cout << "Move op";
        return *this;
    }
}