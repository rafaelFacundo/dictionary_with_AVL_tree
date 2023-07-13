#include <iostream>
#include "solucao.hpp"
using namespace std;

int main()
{
    DicioAVL<double, double> *teste = new DicioAVL<double, double>();
    // auto testeBusca = teste->inserir(1, 1917);
    auto busca = teste->buscar(-1898);
    if (busca == teste->end())
    {
        cout << "=== CHAVE NÃO FOI ENCONTRADA ===\n";
    }
    auto retornoInsercao = teste->inserir(299.25, -56);

    cout << "O RETORNO INSERCAO FOI == " << retornoInsercao.chave() << '\n';

    retornoInsercao = teste->inserir(7.75, 67.5);

    retornoInsercao = teste->inserir(67.5, -40.5);

    retornoInsercao = teste->inserir(82.5, 4.5);

    retornoInsercao = teste->inserir(-3.75, 94.5);

    retornoInsercao = teste->inserir(-124.25, 54);

    retornoInsercao = teste->inserir(16, 53.5);

    teste->printarDicionario();

    busca = teste->buscar(4445466556656565);
    if (busca == teste->end())
    {
        cout << "=== CHAVE NÃO FOI ENCONTRADA ===\n";
    }
    else
    {
        cout << "+++ ACHEI A CHAVE 67\n";
    }

    /* auto nove = teste->buscar(9);
    cout << "achado " << nove.valor() << '\n';

    teste->remover(nove);

    nove = teste->buscar(13);
    auto seila = teste->buscar(17);

    teste->remover(seila);

    teste->printarDicionario();

    cout << "++++++++++++++++++++++++++++\n";

    teste->remover(nove);

    teste->printarDicionario(); */

    return 0;
}

/* g++ -Wall -Wextra -std=c++17 -pedantic main.cpp */

/*


    Vai inicializar ... ok.
    Vai inserir (299.25, -56) ... ok.
    Vai inserir (7.75, 67.5) ... ok.
    Vai inserir (67.5, -40.5) ... ok.
    Vai inserir (82.5, 4.5) ... ok.
    Vai inserir (-3.75, 94.5) ... ok.
    Vai inserir (-124.25, 54) ... ok.
    Vai inserir (16, 53.5) ... ok.
 */