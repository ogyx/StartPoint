#include "dotpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace  DotEngine
{
    std::shared_ptr<spdlog::logger> Log::s_DotEngineCoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_DotEngineClientLogger;

    void Log::InitLog()
    {
        // set the log pattern:Time Name Message
        spdlog::set_pattern("%^[%T] %n: %v%$");

        // create engine logger
        s_DotEngineCoreLogger = spdlog::stderr_color_mt("DOT");
        s_DotEngineCoreLogger->set_level(spdlog::level::trace);

        // create app logger
        s_DotEngineClientLogger = spdlog::stderr_color_mt("APP");
        s_DotEngineCoreLogger->set_level(spdlog::level::trace);
    }
}