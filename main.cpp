#include <spdlog/spdlog.h>

int main ()
{
//    spdlog::info("good day");
    
     auto logger = spdlog::stdout_logger_mt("console");
  logger->info("version {} was started", version());

    
    
}
