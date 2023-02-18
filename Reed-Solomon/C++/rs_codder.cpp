#include <iostream>
#include <vector>
#include <libcorrect/rs.h>

int main()
{
    // Definindo os parâmetros do código Reed-Solomon
    int data_length = 4;
    // tamanho em bytes do dado a ser codificado (neste caso, 32 bits = 4 bytes)
    int parity_length = 8; // tamanho em bytes dos símbolos de paridade
    int total_length = data_length + parity_length;
    // tamanho total da palavra codificada
    int ecc_capacity = 8;  // número máximo de erros que o código pode corrigir

    // Criando o objeto "rs" usando os parâmetros definidos
    rs_t *rs = init_rs_char(data_length, parity_length, 0x11d, ecc_capacity, 1);

    // Criando um array de bytes com o dado a ser codificado (número de 32 bits)
    uint32_t data = 0x12345678;
    uint8_t input_data[data_length];
    for(int i=0; i<data_length; i++)
    {
        input_data[i] = (data >> (8*i)) & 0xFF;
    }

    // Criando um array de bytes para armazenar a palavra codificada
    uint8_t encoded_data[total_length];

    // Codificando o dado usando o código Reed-Solomon
    encode_rs_char(rs, input_data, encoded_data);

    // Imprimindo o dado original e a palavra codificada
    std::cout << "Dados originais: " << std::hex << data << std::endl;
    std::cout << "Dados codificados: ";
    for(int i=0; i<total_length; i++)
    {
        std::cout << std::hex << (int)encoded_data[i] << " ";
    }
    std::cout << std::endl;

    // Liberando a memória alocada para o objeto "rs"
    free_rs_char(rs);

    return 0;
}
