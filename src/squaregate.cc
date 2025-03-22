#include "squaregate.hh"
#include "settings.hh"

edevice*
squaregate::solve_electronics()
{
    if (!this->s_in[0].is_ready())
        return this->s_in[0].get_connected_edevice();

    float value = this->s_in[0].get_value();
    float clamp_value = (settings["disable_overloader"]->v.b) ? tclampf(value, 0.f, 1.f) : value;
    clamp_value *= clamp_value;

    this->s_out[0].write(clamp_value);

    return 0;
}
