#include "yar/Error.hpp"
#include "yar/Logging.hpp"
yar::StaticErrorHandler_f error_handler;

void yar::setErrorHandler(StaticErrorHandler_f handler)
{
    error_handler = handler;
}
void yar::error(int code, const char* file, const char* function, int line, const char* msg)
{
    if(error_handler)
    {
        error_handler(code, file, function, line, msg);
    }
    throw yar::Exception(code, msg, function, file, line, print_callstack(0, true));
}