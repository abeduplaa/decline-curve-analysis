#include <cstdint>
#include "/home/mapdadmin/abraham/oil-gas/decline-curve-analysis-gpu/udf/OmniSciTypes.h"

EXTENSION_NOINLINE float udf_penn(const float qi, const float b, const float d, const float t, const int32_t lim) { 
    if (t <= lim){
        return qi / std::pow( (1 + b * d * t, 1/ b) );
    }  else {
        float qi1 = qi / std::pow( (1 + b * d * lim, 1/ b );
        float ds = (qi1  - (qi / std::pow( (1 + b * d * (lim+1), 1/ b ))) ) / qi1;
        return qi1 * std::exp(-1 * ds * (t-lim));
    }
}
