#include "register_types.h"

#include "gdexample.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

static const ModuleInitializationLevel minimum_initialisation_level = MODULE_INITIALIZATION_LEVEL_SCENE;

void initialise_example_module(ModuleInitializationLevel p_level) {
    if (p_level != minimum_initialisation_level) {
        return;
    }

    ClassDB::register_class<GDExample>();
}

void uninitialise_example_module(ModuleInitializationLevel p_level) {
    if (p_level != minimum_initialisation_level) {
        return;
    }
}

extern "C" {
    GDExtensionBool GDE_EXPORT example_library_init(
            GDExtensionInterfaceGetProcAddress p_get_proc_address,
            const GDExtensionClassLibraryPtr p_library,
            GDExtensionInitialization *r_initialisation) {
        godot::GDExtensionBinding::InitObject init_obj(
            p_get_proc_address, p_library, r_initialisation);
        
        init_obj.register_initializer(initialise_example_module);
        init_obj.register_terminator(uninitialise_example_module);
        init_obj.set_minimum_library_initialization_level(minimum_initialisation_level);

        return init_obj.init();
    }
}