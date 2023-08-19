#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

GDExample::GDExample() {
    time_passed = 0.0;
    amplitude = 10.0;
    speed = 1.0;
}

GDExample::~GDExample() {}

void GDExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_amplitude"), &GDExample::get_amplitude);
    ClassDB::bind_method(D_METHOD("set_amplitude", "new_amplitude"), &GDExample::set_amplitude);

    ClassDB::add_property(
        "GDExample",
        PropertyInfo(Variant::FLOAT, "amplitude"),
        "set_amplitude",
        "get_amplitude");

    ClassDB::bind_method(D_METHOD("get_speed"), &GDExample::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "new_speed"), &GDExample::set_speed);

    ClassDB::add_property(
        "GDExample",
        PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0, 20, 0.1"),
        "set_speed",
        "get_speed");
}

void GDExample::_process(double delta) {
    time_passed += speed * delta;

    Vector2 new_position = Vector2(
        amplitude + (amplitude * sin(time_passed * 2.0)),
        amplitude + (amplitude * cos(time_passed * 1.5)));
    
    set_position(new_position);
}


double GDExample::get_amplitude() const {
    return amplitude;
}

void GDExample::set_amplitude(const double new_amplitude) {
    amplitude = new_amplitude;
}

double GDExample::get_speed() const {
    return speed;
}

void GDExample::set_speed(const double new_speed) {
    speed = new_speed;
}