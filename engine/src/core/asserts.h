#pragma once

#include "defines.h"

#define TASSERTIONS_ENABLED

#ifdef TASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

TAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define TASSERT(expr)                                                   \
    {                                                                   \
        if(expr) {                                                      \
        } else {                                                        \
            report_assertion_failure(#expr, "", __FILE__, __LINE__);    \
            debugBreak();                                               \
        }                                                               \
    }

#define TASSERT_MSG(expr, message)                                           \
    {                                                                        \
        if(expr) {                                                           \
        } else {                                                             \
            report_assertion_failure(#expr, #message, __FILE__, __LINE__);    \
            debugBreak();                                                    \
        }                                                                    \
    }

#ifdef _DEBUG
#define TASSERT_DEBG(expr, message)                                          \
    {                                                                        \
        if(expr) {                                                           \
        } else {                                                             \
            report_assertion_failure(#expr, message, __FILE__, __LINE__);    \
            debugBreak();                                                    \
        }                                                                    \
    }
#else
#define TASSERT_DEBUG(expr)
#endif

#else
#define TASSERT(expr)
#define TASSERT_MSG(expr, message)
#define TASSERT_DEBUG(expr)
#endif