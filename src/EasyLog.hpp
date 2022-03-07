#ifndef EASY_LOG_HPP
#define EASY_LOG_HPP

#include <iostream>

namespace Elog
{
    class Logger
    {
    public:
        Logger();
        ~Logger();

        Logger(const Logger& other) = delete;
        Logger& operator=(const Logger& other) = delete;

        Logger(Logger&& other);
        Logger& operator=(Logger&& other);

        template<typename T>
        Logger& operator<<(T data);
    private:

    };
}

#endif //EASY_LOG_HPP