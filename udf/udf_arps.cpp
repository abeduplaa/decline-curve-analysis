#include <cstdint>
#include <math.h>
#if defined(clang) && defined(CUDA) && defined(CUDA_ARCH) #define DEVICE device #else #define DEVICE #endif
#if defined(clang) && defined(CUDA) && defined(CUDA_ARCH) #define NEVER_INLINE #else #define NEVER_INLINE attribute((noinline)) #endif
#if defined(clang) && defined(CUDA) && defined(CUDA_ARCH) #define ALWAYS_INLINE #else #define ALWAYS_INLINE attribute((always_inline)) #endif
#define EXTENSION_NOINLINE extern "C" NEVER_INLINE DEVICE

EXTENSION_NOINLINE float udf_arps(const int32_t t, const float qi, const float b, const float di){return qi * exp(-1 * di * t)}
