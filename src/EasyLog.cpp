#include <chrono>

#include "EasyLog.hpp"

#define DEFAULT_BUFFER_SIZE 1024
#define DAY_TOTAL_SECONDS 86400
#define HOUR_TOTAL_SECONDS 3600
#define MINUTE_TOTAL_SECONDS 60

namespace Elog
{
    bool Logger::init()
    {
        m_should_check_date = true;
        return true;
    }

    bool Logger::shutdown()
    {
        return true;
    }

    Logger::Logger(Logger&& other)
    {
        std::cout << "Move constr\n";
    }

    Logger& Logger::operator=(Logger&& other)
    {
        std::cout << "Move op\n";
        return *this;
    }

    Logger& Logger::operator<<(std::ostream& (*fun)(std::ostream&))
    {
        std::cout << std::endl;
        return *this;
    }

    std::string Logger::get_current_time()
    {
        long long time = std::time(0);
        std::string out_time;

        time %= DAY_TOTAL_SECONDS;
        std::uint8_t hours = time / HOUR_TOTAL_SECONDS;
        out_time += std::to_string(hours) + ":";
        time -= hours * HOUR_TOTAL_SECONDS;

        std::uint8_t minutes = time / MINUTE_TOTAL_SECONDS;
        out_time += std::to_string(minutes) + ":";
        time -= minutes * MINUTE_TOTAL_SECONDS;

        out_time += std::to_string(time);

        return out_time;
    }

    std::string Logger::get_current_date()
    {
        return "date";
    }
}