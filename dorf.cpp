#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void print_help() {
    std::cout << R"(USO:
dorf --path /ruta/app

Opciones:
  --path, -p     Ruta a verificar (obligatorio)
  --help, -h     Mostrar esta ayuda
)";
}

int main(int argc, char* argv[]) {
    std::string path;

    if (argc == 1) {
        print_help();
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if ((arg == "--path" || arg == "-p") && i + 1 < argc) {
            path = argv[++i];
        } else if (arg == "--help" || arg == "-h") {
            print_help();
            return 0;
        }
    }

    if (path.empty()) {
        std::cerr << "Error: Debes especificar una ruta con --path o -p\n";
        return 1;
    }

    if (!fs::exists(path)) {
        std::cout << "La ruta no existe.\n";
    } else if (fs::is_directory(path)) {
        std::cout << "Es un directorio.\n";
    } else if (fs::is_regular_file(path)) {
        std::cout << "Es un archivo.\n";
    } else {
        std::cout << "Existe, pero no es un archivo ni un directorio regular.\n";
    }

    return 0;
}
