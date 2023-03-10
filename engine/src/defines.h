#pragma once

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef float f32;
typedef double f64;

typedef int b32;
typedef char b8;

#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");

#define TRUE 1
#define FALSE 0

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define TPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#elif defined(__linux__) || defined(__unix__)
#define TPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define TPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
#define TPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
#define TPLATFORM_POSIX 1
#elif __APPLE__
#define TPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
#define TPLATFORM_IOS 1
#define TPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define TPLATFORM_IOS 1
#elif TARGET_OS_MAC
#else
#error "Unknown Apple platform
#endif
#else
#error "Unknown platform"
#endif

#ifdef TEXPORT
#ifdef _MSC_VER
#define TAPI __declspec(dllexport)
#else
#define TAPI __attribute__((visibility("default")))
#endif
#else
#ifdef _MSC_VER 
#define TAPI __declspec(dllimport)
#else
#define TAPI
#endif
#endif

#define TCLAMP(value, min, max) (value <= min) ? min : (value >= max) ? max : value;