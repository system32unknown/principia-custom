#include "sqrtgate.hh"

edevice*
sqrtgate::solve_electronics()
{
    if (!this->s_in[0].is_ready())
        return this->s_in[0].get_connected_edevice();

    float in = this->s_in[0].get_value();
    float v = (settings["fix_sqrt"]) ? tclampf(in, 0.f, 1.f) : in;
    v = sqrtf(v);

    this->s_out[0].write(v);

    return 0;
}
