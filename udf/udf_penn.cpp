#include <cstdint>
#include <cmath>
#if defined(clang) && defined(CUDA) && defined(CUDA_ARCH) #define DEVICE device #else #define DEVICE #endif
#if defined(clang) && defined(CUDA) && defined(CUDA_ARCH) #define NEVER_INLINE #else #define NEVER_INLINE attribute((noinline)) #endif
#if defined(clang) && defined(CUDA) && defined(CUDA_ARCH) #define ALWAYS_INLINE #else #define ALWAYS_INLINE attribute((always_inline)) #endif
#define EXTENSION_NOINLINE extern "C" NEVER_INLINE DEVICE
EXTENSION_NOINLINE float udf_penn(const float qi, const float b, const float d, const float t, const int32_t lim) { 
    if (t <= lim){
        return qi / std::pow( (1 + b * d * t, 1/ b) );
    }  else {
        float qi1 = qi / std::pow( (1 + b * d * lim, 1/ b );
        float ds = (qi1  - (qi / std::pow( (1 + b * d * (lim+1), 1/ b ))) ) / qi1;
        return qi1 * std::exp(-1 * ds * (t-lim));
    }
}