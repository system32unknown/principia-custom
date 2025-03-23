#include "sqrtgate.hh"
#include "settings.hh"

edevice*
sqrtgate::solve_electronics()
{
    if (!this->s_in[0].is_ready())
        return this->s_in[0].get_connected_edevice();

    float in = this->s_in[0].get_value();
    float value = 0.0;
    if (settings["disable_overloader"]->v.b)
        value = tclampf(in, 0.f, 1.f);
    else value = in;
    value = sqrtf(value);

    this->s_out[0].write(value);

    return 0;
}
