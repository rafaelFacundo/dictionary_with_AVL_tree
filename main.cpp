#include "solucao.hpp"

int main()
{
    DicioAVL<int, int> teste();
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