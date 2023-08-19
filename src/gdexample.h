#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class GDExample : public Sprite2D {
    GDCLASS(GDExample, Sprite2D)

    public:
        GDExample();
        ~GDExample();

        void _process(double delta);
    
    protected:
        static void _bind_methods();

        double get_amplitude() const;
        void set_amplitude(const double new_amplitude);
        
        double get_speed() const;
        void set_speed(const double new_speed);

    private:
        double time_passed;
        double amplitude;
        double speed;
};

}

#endif //GDEXAMPLE_H