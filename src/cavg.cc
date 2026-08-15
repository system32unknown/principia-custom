#include "cavg.hh"
#include "settings.hh"

edevice *cavg::solve_electronics() {
    if (!this->s_in[0].is_ready())
        this->s_in[0].get_connected_edevice();

    float v = this->s_in[0].get_value();

    float f = this->properties[0].v.f;

    if (v <= 0.f)
        this->value = 0.f;
    else
        this->value = f * this->value + (1.f - f)*v;

    float clamped_value = 0.f;
    if (settings["disable_overloader"]->v.b) clamped_value = tclampf(this->value, 0.f, 1.f);
    else clamped_value = this->value;
    this->s_out[0].write(clamped_value);

    return 0;
}
