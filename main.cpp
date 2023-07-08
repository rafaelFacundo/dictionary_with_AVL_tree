#include <iostream>
#include "solucao.hpp"
using namespace std;

int main()
{
    DicioAVL<int, int> *teste = new DicioAVL<int, int>();
    // auto testeBusca = teste->inserir(1, 1917);
    teste->buscar(-1898);
    teste->inserir(6, 2356);
    teste->inserir(7, 884545);
    teste->inserir(89, 884545);
    teste->inserir(5, 884545);

    teste->printarDicionario();

    return 0;
}

/* g++ -Wall -Wextra -std=c++17 -pedantic main.cpp */

/*

    primeiro to na raiz
    pego o filho esquerdo dela

    cheguei até o penultimo nó
    não achei a chave
    ela é diferente, logo o while vai rodar mais uma vez
    então eu coloco o ponteiroProPai no nó que eu estou
    e vejo para onde vou (vou para o sentinela independente para onde descer)
    coloco o nohQueEuEstou para o filho do nó atual
    quando o while for rodar denovo
    ele vão vai entrar pois ele chegou no sentinela
    e o sentinela sempre tem o valor que eu estou procurando
    e como a condição é ser diferente o while não vai rodar




*/