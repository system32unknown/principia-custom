#include "invertergate.hh"
#include "settings.hh"

edevice*
invertergate::solve_electronics()
{
    if (!this->s_in[0].is_ready()) {
        return this->s_in[0].get_connected_edevice();
    }

    float value = 1.f - this->s_in[0].get_value();

    if (settings["disable_overloader"]->v.b)
        this->s_out[0].write(tclampf(value, 0.f, 1.f));
    else this->s_out[0].write(value);

    return 0;
}
