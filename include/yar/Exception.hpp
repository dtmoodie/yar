#pragma once
#include "Export.hpp"
#include <exception>
#include <string>
namespace yar
{
    class YAR_EXPORTS Exception: public std::exception
    {
    public:
        Exception();
        Exception(int _code, const std::string& _err, const std::string& _func, const std::string& _file, int _line, const std::string& callstack = "");
        virtual ~Exception() throw();
        virtual const char* what() const throw();
        virtual const char* callstack() const throw();
        void formatMessage();
    private:
        std::string msg;
        int code; 
        std::string err; 
        std::string func; 
        std::string file; 
        int line; 
        std::string _callstack;
    };
}