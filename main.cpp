#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <gtest/gtest.h>

class NumeroGenerator {
public:
    static bool GenerarArchivo(const std::string& nombreArchivo) {
        std::vector<int> numeros;
        for (int i = 1; i <= 36 * 256; ++i) {
            numeros.push_back(i);
        }

        std::random_device rd;
        std::mt19937 generator(rd());
        std::shuffle(numeros.begin(), numeros.end(), generator);

        std::ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            for (size_t i = 0; i < numeros.size(); ++i) {
                archivo << numeros[i];
                if (i != numeros.size() - 1) {
                    archivo << ",";
                }
            }
            archivo.close();
            return true;
        } else {
            return false;
        }
    }
};

// Prueba unitaria usando Google Test
TEST(NumeroGeneratorTest, ArchivoGeneradoExitosamente) {
    const std::string nombreArchivo = "numeros_36KB.txt";

    bool resultado = NumeroGenerator::GenerarArchivo(nombreArchivo);

    EXPECT_TRUE(resultado) << "No se pudo generar el archivo exitosamente.";
// Puedes agregar más aserciones aquí para verificar el contenido o tamaño del archivo si es necesario.
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}