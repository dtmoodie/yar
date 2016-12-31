#pragma once

#if (defined WIN32 || defined _WIN32 || defined WINCE || defined __CYGWIN__) && defined yar_EXPORTS
#  define YAR_EXPORTS __declspec(dllexport)
#elif defined __GNUC__ && __GNUC__ >= 4
#  define YAR_EXPORTS __attribute__ ((visibility ("default")))
#else
#  define YAR_EXPORTS
#endif