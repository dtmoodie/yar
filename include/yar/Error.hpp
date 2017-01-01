#pragma once
#include "Export.hpp"
#include "Exception.hpp"



namespace yar
{
    typedef void(*StaticErrorHandler_f)(int, const char*, const char*, int, const char*);

    YAR_EXPORTS void setErrorHandler(StaticErrorHandler_f handler);
    YAR_EXPORTS void error(int code, const char* file, const char* function, int line, const char* msg);
}