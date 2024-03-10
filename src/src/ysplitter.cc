#include "ysplitter.hh"
#include "game.hh"

edevice*
ysplitter::solve_electronics()
{
    if (!this->s_in[0].is_ready()) {
        return this->s_in[0].get_connected_edevice();
    }

    float v = this->s_in[0].get_value();

    this->s_out[0].write(v);
    this->s_out[1].write(v);

    return 0;
}

edevice*
megasplitter::solve_electronics()
{
    if (!this->s_in[0].is_ready()) {
        return this->s_in[0].get_connected_edevice();
    }

    const float v = this->s_in[0].get_value();

    for (int i = 0; i < 7; i++) {
        this->s_out[i].write(v);
    }

    return 0;
}

edevice*
halfunpack::solve_electronics()
{
    if (!this->s_in[0].is_ready())
        return this->s_in[0].get_connected_edevice();

    float v = this->s_in[0].get_value();

    v *= 2.f;

    if (v >= 1.f) {
        this->s_out[1].write(tclampf(v - 1.f, 0.f, 1.f));
        this->s_out[0].write(0.f);
    } else {
        this->s_out[1].write(0.f);
        this->s_out[0].write(tclampf(1.f - v, 0.f, 1.f));
    }

    return 0;
}
