#include "yar/Exception.hpp"
#include <sstream>
using namespace yar;

Exception::Exception()
{

}
Exception::Exception(int _code, const std::string& _err, const std::string& _func, const std::string& _file, int _line, const std::string& callstack_):
    code(_code), err(_err), func(_func), file(_file), line(_line), _callstack(callstack_)
{
    formatMessage();
}
Exception::~Exception() throw()
{

}

const char* Exception::what() const throw()
{
    return msg.c_str();
}

const char* Exception::callstack() const throw()
{
    return _callstack.c_str();
}

void Exception::formatMessage()
{
    std::stringstream ss;
    ss << file;
    ss << ':' << line << ": error: (" << code << ") " << err << " in function " << func;
    msg = ss.str();
}

