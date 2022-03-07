#ifndef EASY_LOG_HPP
#define EASY_LOG_HPP

#include <iostream>
#include <cstdint>

#ifdef __linux__
    #if TERM == xterm
        #define COLORS_SUPPORT 1

        struct Colors
        {
            static constexpr const std::uint8_t  BLACK_FORE = 30;
            static constexpr const std::uint8_t  RED_FORE = 31;
            static constexpr const std::uint8_t  GREEN_FORE = 32;
            static constexpr const std::uint8_t  YELLOW_FORE = 33;
            static constexpr const std::uint8_t  WHITE_FORE = 37;

            static constexpr const std::uint8_t  BLACK_BACK = 40;
            static constexpr const std::uint8_t  RED_BACK = 41;
            static constexpr const std::uint8_t  GREEN_BACK = 42;
            static constexpr const std::uint8_t  YELLOW_BACK = 43;
            static constexpr const std::uint8_t  WHITE_BACK = 47;

            static constexpr const std::uint8_t  RESET = 0;
        };
    #else
        #define COLORS_SUPPORT 0
    #endif

#endif //__linux__

#ifdef _WIN32
    #error "Windows not supported"
#endif    //_WIN32

namespace Elog
{
    class Logger
    {
    public:
        Logger() = default;
        ~Logger() = default;

        bool init();
        bool shutdown();

        Logger(const Logger& other) = delete;
        Logger& operator=(const Logger& other) = delete;

        Logger(Logger&& other);
        Logger& operator=(Logger&& other);

        template<typename T>
        Logger& operator<<(T data)
        {
            std::cout << get_current_time() << data;
            return *this;
        }

        Logger& operator<<(std::ostream& (*fun)(std::ostream&));
    private:
        std::string get_current_time();
        std::string get_current_date();
    private:
        std::string m_buffer;
        bool m_should_check_date;
    };
}


#endif //EASY_LOG_HPP