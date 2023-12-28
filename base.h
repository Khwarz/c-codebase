#ifndef BASE_H
#define BASE_H

// Compiler macros

#if defined(__clang__)

# define COMPILER_CLANG 1
# if defined(_WIN32)
#  define OS_WINDOWS
# elif defined(__gnu_linux__)
#  define OS_LINUX 1
# elif defined(__APPLE__) && defined(__MACH__)
#  define OS_APPLE 1
# else
#  error Unsupported platform
# endif

# if defined(__i386__)
#  define ARCH_X86 1
# elif defined(__x86_64__)
#  define ARCH_X64 1
# elif defined(__arm__)
#  define ARCH_ARM 1
# elif defined(__aarch64__)
#  define ARCH_ARM64 1
# else
#  error Unsupported architecture
# endif

#elif defined(_MSC_VER)

# define COMPILER_CL 1
# if defined(_WIN32)
#  define OS_WINDOWS 1
# else
#  error Unsupported platform
# endif

# if defined(_M_IX86)
#  define ARCH_X86 1
# elif defined(_M_AMD64)
#  define ARCH_X64 1
# elif defined(_M_ARM)
#  define ARCH_ARM 1
# else
#  error Unsupported architecture
# endif

#elif defined(__GNUC__)

# define COMPILER_GCC 1
# if defined(_WIN32)
#  define OS_WINDOWS 1
# elif defined(__gnu_linux__)
#  define OS_LINUX 1
# elif defined(__APPLE__) && defined(__MACH__)
#  define OS_APPLE 1
# else
#  error Unsupported platform
# endif

# if defined(__i386__)
#  define ARCH_X86 1
# elif defined(__x86_64__)
#  define ARCH_X64 1
# elif defined(__arm__)
#  define ARCH_ARM 1
# elif defined(__aarch64__)
#  define ARCH_ARM64 1
# else
# error Unsupported architecture
# endif

#else

# error No context cracking for this compiler

#endif

#if !defined(COMPILER_CLANG)
# define COMPILER_CLANG 0
#endif
#if !defined(COMPILER_GCC)
# define COMPILER_GCC 0
#endif
#if !defined(COMPILER_CL)
# define COMPILER_CL 0
#endif
#if !defined(OS_WINDOWS)
# define OS_WINDOWS 0
#endif
#if !defined(OS_LINUX)
# define OS_LINUX 0
#endif
#if !defined(OS_APPLE)
# define OS_APPLE 0
#endif
#if !defined(ARCH_X86)
# define ARCH_X86 0
#endif
#if !defined(ARCH_X64)
# define ARCH_X64 0
#endif
#if !defined(ARCH_ARM)
# define ARCH_ARM 0
#endif
#if !defined(ARCH_ARM64)
# define ARCH_ARM64 0
#endif

#if !defined(ENABLE_ASSERT)
#define ENABLE_ASSERT 1
#endif

// Helper macros

#define STATEMENT(S) do { S } while (0)

#if !defined(ASSERT_BREAK)
#define ASSERT_BREAK() ((*(int *) 0) = 0)
#endif

#if ENABLE_ASSERT
# define ASSERT(c) STATEMENT(if (!(c)) { ASSERT_BREAK(); })
#else
# define ASSERT(c)
#endif

#define STRINGIFY_(S) #S
#define STRINGIFY(S) STRINGIFY_(S)

#define GLUE_(A, B) A##B
#define GLUE(A, B) GLUE_(A, B)

#define ARRAY_COUNT(a) (sizeof(a)/sizeof(*(a)))

#define INT_FROM_POINTER(p) ((unsigned long long)((char*)p - (char*)0))
#define POINTER_FROM_INT(p) (void*)((char*)0 + (n))

#define MEMBER(T, m) (((T*)0)->m)
#define OFFSET_OF_MEMBER(T, m) INT_FROM_POINTER(&MEMBER(T, m))

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CLAMP(a, x, b) ((x) < (a) ? (a) : ((b) < (x) ? (b) : (x)))

#define CLAMP_TOP(a, b) MIN(a, b)
#define CLAMP_BOTTOM(a, b) MAX(a, b)

#include <string.h>

#define MEMORY_ZERO(p, z) memset((p), 0, (z))
#define MEMORY_ZERO_STRUCT(p) MEMORY_ZERO((p), sizeof(*(p)))
#define MEMORY_ZERO_ARRAY(p) MEMORY_ZERO((p), sizeof(p))
#define MEMORY_ZERO_TYPED(p, c) MEMORY_ZERO((p), sizeof(*(p)) * (c))

#define MEMORY_COMPARE(a, b, z) (memcmp((a), (b), (z)) == 0)

#define MEMORY_COPY(d, s, z) memmove((d), (s), (z))
#define MEMORY_COPY_STRUCT(d, s) MEMORY_COPY((d), (s), MIN(sizeof(*(d)), sizeof(*(s))))
#define MEMORY_COPY_ARRAY(d, s) MEMORY_COPY((d), (s), MIN(sizeof(d), sizeof(s)))
#define MEMORY_COPY_TYPED(d, s, c) MEMORY_COPY((d), (s), MIN(sizeof(*(d)), sizeof(*(s)) * (c)))

// Basic Types

#include <stdint.h>
typedef int8_t      i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;
typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;
typedef i8          b8;
typedef i16         b16;
typedef i32         b32;
typedef i64         b64;
typedef float       f32;
typedef double      f64;

typedef void VoidFunc(void);

static i8 min_i8    = (i8) 0x80;
static i16 min_i16  = (i16) 0x8000;
static i32 min_i32  = (i32) 0x80000000;
static i64 min_i64  = (i64) 0x80000000000000llu;

static i8 max_i8    = (i8) 0x7f;
static i16 max_i16  = (i16) 0x7fff;
static i32 max_i32  = (i32) 0x7fffffff;
static i64 max_i64  = (i64) 0x7fffffffffffffllu;

static u8 max_u8    = (u8) 0xff;
static u16 max_u16  = (u16) 0xffff;
static u32 max_u32  = (u32) 0xffffffff;
static u64 max_u64  = (u64) 0xffffffffffffffllu;

#endif // BASE_H

