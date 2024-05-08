#include "complex_num.h"

complex_num::complex_num(double r, double i): real_mod{r}, im_mod{i}{
    // Write your code here
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    z.real_mod = real_mod + w.real_mod;
    z.im_mod = im_mod + w.im_mod;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    z.real_mod = real_mod - w.real_mod;
    z.im_mod = im_mod - w.im_mod;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    //(ac-bd) + i(ad+bc)
    z.real_mod = (real_mod * w.real_mod) - (im_mod * w.im_mod);
    z.im_mod = (real_mod * w.im_mod) + (im_mod * w.real_mod);
    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    // z/w = (a+ib)/(c+id) = ((ac+bd)/(c^2+d^2)) + i((bc-ad)/(c^2+d^2))
    z.real_mod = (real_mod * w.real_mod + im_mod * w.im_mod) / (im_mod * im_mod + w.im_mod * w.im_mod);
    z.im_mod = (im_mod * w.real_mod + real_mod * w.im_mod) / (im_mod * im_mod + w.im_mod * w.im_mod);  
    return z;
}

void complex_num::print(std::ostream &os){
    os << real_mod;
    if (im_mod != 0) {
        os << (im_mod < 0 ? " - " : " + ") << "i" << (im_mod < 0 ? -1 * im_mod : im_mod);
    }
}