#include <iostream>
using namespace std;

// Código Realizado em dupla por Gustavo Murai e Igor Murai

#define FILEIRAS 15
#define POLTRONAS 40

// Declaração da matriz de ocupação
char teatro[FILEIRAS][POLTRONAS];

// Função para inicializar o teatro (todas as poltronas começam vazias)
void inicializarTeatro() {
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < POLTRONAS; j++) {
            teatro[i][j] = '.';  // '.' significa lugar vago
        }
    }
}

// Função para mostrar o mapa de ocupação
void mostrarMapa() {
    cout << "Mapa de Ocupacao: " << endl;
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < POLTRONAS; j++) {
            cout << teatro[i][j] << " ";  // Mostra '.' ou '#'
        }
        cout << endl;
    }
}

// Função para calcular o faturamento
void calcularFaturamento(int &totalOcupados, double &valorBilheteira) {
    totalOcupados = 0;
    valorBilheteira = 0.0;

    // Calcular o total de ocupados e o valor da bilheteira
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < POLTRONAS; j++) {
            if (teatro[i][j] == '#') {  // Se a poltrona estiver ocupada
                totalOcupados++;

                // Determina o valor do ingresso baseado na fileira
                if (i < 5) {  // Fileiras 1 a 5
                    valorBilheteira += 50.00;
                } else if (i < 10) {  // Fileiras 6 a 10
                    valorBilheteira += 30.00;
                } else {  // Fileiras 11 a 15
                    valorBilheteira += 15.00;
                }
            }
        }
    }
}

// Função para reservar a poltrona
void reservarPoltrona() {
    int fileira, poltrona;

    cout << "Digite o numero da fileira (1 a 15): ";
    cin >> fileira;
    cout << "Digite o numero da poltrona (1 a 40): ";
    cin >> poltrona;

    // Verificar se os números são válidos
    if (fileira < 1 || fileira > 15 || poltrona < 1 || poltrona > 40) {
        cout << "Entrada invalida! Tente novamente." << endl;
        return;
    }

    // Ajustando para índices de 0 a 14 e 0 a 39
    fileira--;
    poltrona--;

    // Verificar se a poltrona está ocupada
    if (teatro[fileira][poltrona] == '#') {
        cout << "Erro: a poltrona ja esta ocupada!" << endl;
    } else {
        teatro[fileira][poltrona] = '#';  // Reserva a poltrona
        cout << "Reserva realizada com sucesso!" << endl;
    }
}

int main() {
    int opcao;
    int totalOcupados = 0;
    double valorBilheteira = 0.0;

    // Inicializa o teatro
    inicializarTeatro();

    do {
        cout << "\nMenu de Opcoes:" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mostrar mapa de ocupacao" << endl;
        cout << "3. Faturamento" << endl;
        cout << "0. Finalizar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Finalizando programa..." << endl;
                break;
            case 1:
                reservarPoltrona();
                break;
            case 2:
                mostrarMapa();
                break;
            case 3:
                calcularFaturamento(totalOcupados, valorBilheteira);
                cout << "Qtde de lugares ocupados: " << totalOcupados << endl;
                cout << "Valor da bilheteira: R$ " << valorBilheteira << endl;
                break;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }

    } while (opcao != 0);

    return 0;
}
