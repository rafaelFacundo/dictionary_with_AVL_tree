// -----------------------------------------------------------------------------
// Universidade Federal do Ceará, Centro de Ciências, Departamento de Computação
// Disciplina:  Laboratório de Programação - CK0215 2023.1 T01A
// Professor:   Pablo Mayckon Silva Farias
//
// Trabalho 4 - Interface para Implementação de Dicionário baseado em Árvore AVL
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// IDENTIFICAÇÃO DO(A) ESTUDANTE:
//
// NOME:      ...
// MATRÍCULA: ...
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Tudo o que está presente na interface abaixo deve ser mantido como está,
// pois esta interface será utilizada no programa do professor para a realização
// dos testes.
//
// O trabalho consiste portanto em *completar* a implementação abaixo,
// tornando-a funcional e atendendo aos requisitos deste trabalho.
//
// Os pontos a serem completados estão marcados com "TODO", isto é, "por fazer".
// -----------------------------------------------------------------------------

#ifndef DICIOAVL_HPP
#define DICIOAVL_HPP
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------

// A classe DicioAVL deve implementar um dicionário que associe chaves de tipo
// TC a valores de tipo TV.
//
// O dicionário deve organizar esses dados numa árvore AVL em que os elementos
// sejam ordenados entre si a partir de suas chaves.
//
// É pressuposto da classe que as chaves podem ser normalmente comparadas
// através dos operadores relacionais comuns: <, >=, !=, etc.

template <typename TC, typename TV>
class DicioAVL
{
public:
  // Numa implementação típica de dicionário,
  // a representação interna normalmente fica inacessível ao usuário;
  // neste trabalho, porém,
  // o professor precisa avaliar se a árvore está correta,
  // e por isso a estrutura do nó é exposta ao usuário (daí o "public" acima),
  // assim como o ponteiro raiz e a sentinela:

  struct Noh
  {
    TC chave;
    TV valor;
    Noh *pai;
    Noh *direito;
    Noh *esquerdo;
    int altura;

    // Você deve completar a estrutura do nó com:
    //
    // 1. Ponteiros para filho esquerdo, filho direito e pai.
    //
    // 2. Se necessário, algum campo adicional que viabilize a implementação
    //    da árvore AVL, como a altura do nó, a informação do balanceamento
    //    (-1, 0, +1), etc.
    //
    // Você é livre para escolher como vai representar esses elementos,
    // mas deve implementar as funções a seguir,
    // que permitirão que a estrutura da árvore seja percorrida.
    // (quando o filho direito / filho esquerdo / pai não existir,
    //  a respectiva função deve retornar um ponteiro para "sent",
    //  declarada mais abaixo):

    // TODO: defina os campos restantes do nó da árvore AVL.

    // -----------------------------------------------------------------------

    // Esta função deve retornar um ponteiro para o filho direito,
    // se o nó possuir filho direito;
    // em caso contrário, deve ser retornado um ponteiro para o nó sentinela,
    // definido mais abaixo.

    Noh *obter_dir() // Apague o ";" e escreva abaixo a implementação.
    {
      return direito;
    }

    // -----------------------------------------------------------------------

    // Esta função deve retornar um ponteiro para o filho esquerdo,
    // se o nó possuir filho esquerdo;
    // em caso contrário, deve ser retornado um ponteiro para o nó sentinela,
    // definido mais abaixo.

    Noh *obter_esq()
    {
      return esquerdo;
    }

    // -----------------------------------------------------------------------

    // Esta função deve retornar um ponteiro para o nó pai,
    // se o nó possuir nó pai;
    // em caso contrário, deve ser retornado um ponteiro para o nó sentinela,
    // definido mais abaixo.

    Noh *obter_pai()
    {
      return pai;
    }

  }; // struct Noh

  // --------------------------------------------------------------------------

  // Campos públicos de DicioAVL: raiz e sentinela.
  // Lembrete: não altere-os, pois serão usados nos testes automáticos.

  Noh sent;  // Nó sentinela.
  Noh *raiz; // "raiz" deve apontar para "sent" quando a árvore estiver vazia.

  // ==========================================================================

private:
  // Você pode incluir campos e métodos que sejam relevantes para a
  // implementação mas que fiquem inacessíveis ao usuário da classe DicioAVL.

  // ==========================================================================

public:
  // Lembrete: tudo o que está abaixo em DicioAVL deve ser mantido público e
  // inalterado, pois será utilizado nos testes do professor.
  //
  // Observe que isso não impede que você inclua métodos que não estejam
  // presentes abaixo; porém, analise se eles devem mesmo ser públicos.

  // --------------------------------------------------------------------------

  class Iterador
  {
  private:
    // Você pode incluir campos e métodos que sejam relevantes para a
    // implementação mas que fiquem inacessíveis ao usuário de "Iterador".

    // TODO: Defina os campos da classe Iterador.
    Noh *noh;
    DicioAVL *dicio;

    // -----------------------------------------------------------------------

    // O comando abaixo permite que a classe DicioAVL enxergue os membros
    // privados desta classe Iterador.
    // Isso será particularmente útil no método "remover" de DicioAVL,
    // que recebe um iterador e precisa, a partir dele, acessar o nó a ser
    // removido.

    friend DicioAVL;

    // -----------------------------------------------------------------------

  public:
    // Lembrete: tudo o que está abaixo deve ser mantido público em Iterador,
    // pois será utilizado nos testes do professor.
    //
    // Observe que isso não impede que você inclua métodos que não estejam
    // presentes abaixo.

    // -----------------------------------------------------------------------

    // Lembrete: é possível implementar diferentes construtores para uma mesma
    // classe.

    // Construtor padrão (sem argumentos): deve ser possível inicializar um
    // iterador sem que ele aponte para algum elemento específico de um
    // DicioAVL. Isso é útil para declarar uma variável de tipo Iterador sem
    // ter a obrigação de já apontá-la para um elemento de um dicionário.
    //
    // A única operação esperada sobre um iterador assim inicializado é
    // receber uma cópia de outro iterador.
    // Portanto, não se deve chamar métodos como "chave" nem operadores como
    // "==" e "++" sobre um iterador que não esteja apontando para um elemento
    // de um dicionário.
    //
    // Observação: caso deseje, você pode implementar o construtor padrão de
    // forma que seja válido chamar os operadores "==" e "!=" sobre um
    // iterador assim inicializado. Porém, isso não é exigido neste trabalho.

    Iterador(){};
    Iterador(Noh *novoNoh, DicioAVL *d) : noh{novoNoh}, dicio{d} {};
    //  {
    //  // TODO
    //  }

    // -----------------------------------------------------------------------

    // Os operadores "!=" e "==" abaixo podem ser chamados mesmo caso
    // o iterador esteja no "fim" do dicionário ("posição" em que o iterador
    // não se refere a nenhum elemento propriamente dito).

    // -----------------------------------------------------------------------

    // Este método deve retornar "true" se e somente se
    // o iterador atual e "j" NÃO SE REFEREM ao mesmo elemento ou posição do
    // dicionário.

    Noh *ponteiroDireito()
    {
      return this->noh->direito;
    }

    Noh *ponteiroEsquerdo()
    {
      return this->noh->esquerdo;
    }

    Noh *retornarEu()
    {
      return this->noh;
    }

    void setarFilhosDoNohInserido(Noh *filho)
    {
      this->noh->esquerdo = filho;
      this->noh->direito = filho;
    }

    Iterador adicionarFilho(TC c, TV v)
    {
      /* Noh *novoNohAserInserido = new Noh{};
      novoNohAserInserido->chave = c;
      novoNohAserInserido->valor = v;
      novoNohAserInserido->pai = this->noh;
      novoNohAserInserido->esquerdo = &sent;
      novoNohAserInserido->direito = &sent;
      novoNohAserInserido->altura = this->noh->altura + 1;
       */
      cout << "chave ++++++ " << this->noh->chave << "\n";
      cout << "asdhajshgkdjghsaj\n";
      int alturaNova = 0;
      if (this->noh->altura != -1)
      {
        alturaNova = this->noh->altura + 1;
      }
      Noh *novoNohAserInserido = new Noh{c, v, this->noh, nullptr, nullptr, alturaNova};
      if (this->noh->chave >= c)
      {
        this->noh->direito = novoNohAserInserido;
      }
      else
      {
        this->noh->esquerdo = novoNohAserInserido;
      }
      return Iterador(novoNohAserInserido, this->dicio);
    }

    bool operator!=(Iterador j)
    {
      return this->noh != j.noh;
    }

    // -----------------------------------------------------------------------

    // Este método deve retornar "true" se e somente se
    // o iterador atual e "j" SE REFEREM ao mesmo elemento ou posição do
    // dicionário.

    bool operator==(Iterador j)
    {
      return this->noh == j.noh;
    }

    // -----------------------------------------------------------------------

    // Os métodos abaixo possuem como PRÉ-CONDIÇÃO o fato de que o iterador
    // aponta para um elemento propriamente dito do dicionário, ou seja,
    // que o iterador não aponta para o "fim" do dicionário.
    //
    // Como para toda pré-condição, é responsabilidade do usuário de Iterador
    // garantir que ela será satisfeita sempre que o método for chamado.
    //
    // Portanto, esses métodos NÃO PRECISAM TESTAR se o iterador aponta para o
    // "fim" do dicionário.

    // -----------------------------------------------------------------------

    // Este método deve retornar a "chave" do elemento apontado pelo iterador.

    TC chave()
    {
      return this->noh->chave;
    }

    // -----------------------------------------------------------------------

    // Este método deve retornar o "valor" do elemento apontado pelo iterador.

    TV valor()
    {
      return this->noh->valor;
    }

    int alturaIterador()
    {
      return this->noh->altura;
    }

    Noh *chaveMax()
    {
      Noh *nohQueEuEstou = this->dicio->raiz->esquerdo;

      if (nohQueEuEstou != &this->dicio->sent)
      {
        while (nohQueEuEstou->direito != &this->dicio->sent)
        {
          nohQueEuEstou = nohQueEuEstou->direito;
        }
      }

      return nohQueEuEstou;
    }

    // -----------------------------------------------------------------------

    // Este método deve fazer o iterador passar ao próximo elemento do
    // dicionário, isto é, ao elemento da CHAVE SUCESSORA, na ordem crescente
    // das chaves, se houver uma chave sucessora.
    //
    // Caso não haja chave sucessora (ou seja, caso o iterador aponte para a
    // maior chave), o iterador deve passar a apontar para o "fim" do
    // dicionário.
    Noh *sucessor;
    Iterador &
    operator++()
    {
      if (this->noh == this->chaveMax())
      {

        this->noh = &this->dicio->sent;
      }
      else if (this->noh->direito != &this->dicio->sent)
      {

        sucessor = this->noh->direito;
        while (sucessor->esquerdo != &this->dicio->sent)
        {
          sucessor = sucessor->esquerdo;
        }
        this->noh = sucessor;
      }
      else if (this->noh == this->noh->pai->esquerdo)
      {

        this->noh = this->noh->pai;
      }
      else if (this->noh == this->noh->pai->direito)
      {

        this->noh = this->noh->pai->pai;
      }
      else if (this->noh == this->dicio->raiz)
      {
        this->noh = &this->dicio->sent;
      }
      return *this;
    }

  }; // class Iterador

  // --------------------------------------------------------------------------

  // Métodos públicos de DicioAVL:

  // --------------------------------------------------------------------------

  // Construtor: deve inicializar o dicionário como vazio.

  DicioAVL()
  {
    // definition of the fields of the noh
    // chave,valor,pai,esquerdo,direito
    // this->sent = new Noh{-123, 0, nullptr, nullptr, nullptr};
    // this->raiz = new Noh{0, 0, &this->sent, &this->sent, &this->sent};
    this->sent.chave = -123;
    this->sent.valor = 456;
    this->sent.direito = nullptr;
    this->sent.esquerdo = nullptr;
    this->sent.pai = nullptr;
    this->sent.altura = 0;

    this->raiz = new Noh{-456, 7777, &(this->sent), &(this->sent), &(this->sent), 0};
    this->raiz->esquerdo = &(this->sent);
  }

  // --------------------------------------------------------------------------

  // Destrutor: deve desalocar toda a memória dinamicamente alocada pelo
  // dicionário (no caso, basicamente a árvore AVL).

  ~DicioAVL()
  {
  }

  // --------------------------------------------------------------------------

  // Este método deve retornar um iterador apontando para o elemento de menor
  // chave, caso exista um.
  // Se o dicionário estiver vazio, deve retornar um iterador para o "fim".

  Iterador begin()
  {
    Noh *nohQueEuEstou = this->raiz;
    while (nohQueEuEstou->esquerdo != &this->sent)
    {
      nohQueEuEstou = nohQueEuEstou->esquerdo;
    }
    return Iterador(nohQueEuEstou, this);
  }

  // --------------------------------------------------------------------------

  // Deve retornar um iterador num estado especial, que seja diferente do
  // estado de um iterador que aponte para um elemento propriamente dito,
  // e que dessa forma sirva para caracterizar a situação em que o iterador
  // tenha atingido o "fim" do dicionário.

  Iterador end()
  {
    return Iterador(&this->sent, this);
  }

  // --------------------------------------------------------------------------

  // Este método deve inserir a chave "c" e o valor "v" no dicionário, partindo
  // da PRÉ-CONDIÇÃO de que a chave "c" não está presente no dicionário,
  // ou seja, a função não precisa nem deve fazer esse teste.
  //
  // Em caso de falha de alocação de memória,
  // o método deve jogar uma exceção do tipo std::bad_alloc
  // (que já é aquele jogada pelo operador "new" em caso de falha de alocação).
  //
  // A função deve retornar um iterador apontando para o elemento inserido.
  //
  // ATENÇÃO: o iterador retornado deve continuar válido e relativo ao par
  // -------  (c,v) enquanto esse par não for removido do dicionário.
  //
  // A observação acima é particularmente importante para o caso da REMOÇÃO
  // em que o nó do par a ser removido possui dois filhos. Nesse caso, não
  // basta apenas copiar os campos do nó sucessor para o nó em questão, pois
  // isso faria com que o par sucessor mudasse de nó, invalidando algum
  // iterador relativo a esse par; portanto, nesse caso da remoção, é
  // necessário que o nó do sucessor realmente ocupe o lugar da árvore que
  // estava sendo ocupado pelo nó a ser removido.

  void concertarInsercao(Noh *nohComeco)
  {
    while (nohComeco != this->raiz)
    {
      Noh *aux;
      cout << "==========\n";
      cout << "dir " << nohComeco->direito->altura << '\n';
      cout << "esq " << nohComeco->esquerdo->altura << '\n';
      cout << "==========\n";
      // bool Esent = (nohComeco->esquerdo->direito == nullptr) || (nohComeco->esquerdo->esquerdo == nullptr) || (nohComeco->direito->direito == nullptr) || (nohComeco->direito->esquerdo == nullptr);
      cout << "aaaaa  " << Esent << '\n';
      cout << "=============\n";
      if ((nohComeco->direito->altura - nohComeco->esquerdo->altura) == -2 && (nohComeco->esquerdo->direito->altura - nohComeco->esquerdo->esquerdo->altura) == -1)
      {
        cout << "Altura pendendo pra esquerda e msm lado vou rotacionar para direita \n";
        aux = nohComeco->esquerdo;
        nohComeco->esquerdo = nohComeco->esquerdo->direito;
        aux->pai = nohComeco->pai;
        nohComeco->pai = aux;
        aux->direito = nohComeco;
      }
      else if ((nohComeco->direito->altura - nohComeco->esquerdo->altura) == 2 && (nohComeco->esquerdo->direito->altura - nohComeco->esquerdo->esquerdo->altura) == 1)
      {
        cout << "Altura pendendo pra esquerda e msm lado vou rotacionar para esquerda \n";
        aux = nohComeco->direito;
        nohComeco->direito = nohComeco->direito->direito;
        aux->pai = nohComeco->pai;
        nohComeco->pai = aux;
        aux->direito = nohComeco;
      }
      else if ((nohComeco->direito->altura - nohComeco->esquerdo->altura) == -2 && (nohComeco->esquerdo->direito->altura - nohComeco->esquerdo->esquerdo->altura) == 1)
      {
        cout << "asssssssssssdas\n";
        aux = nohComeco->esquerdo->direito;
        nohComeco->esquerdo->direito = nohComeco->esquerdo->direito->direito;
        aux->pai = nohComeco->esquerdo->pai;
        nohComeco->esquerdo->pai = aux;
        aux->direito = nohComeco->esquerdo;

        aux = nohComeco->esquerdo;
        nohComeco->esquerdo = nohComeco->esquerdo->direito;
        aux->pai = nohComeco->pai;
        nohComeco->pai = aux;
        aux->direito = nohComeco;
      }
      else if ((nohComeco->direito->altura - nohComeco->esquerdo->altura) == 2 && (nohComeco->esquerdo->direito->altura - nohComeco->esquerdo->esquerdo->altura) == -1)
      {
        cout << "asdad\n";
      }

      nohComeco = nohComeco->pai;
    }
    cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
  }

  Iterador inserir(TC c, TV v)
  {
    Noh *nohOndInser = this->buscarParaInserir(c);
    // Iterador fimDoDicionario = this->end();
    Noh *nohAretornar;
    bool alturaAlmentou = false;

    if (nohOndInser == this->raiz)
    {

      nohOndInser->esquerdo = new Noh{c, v, nohOndInser, &this->sent, &this->sent, 1};
      nohOndInser->direito = new Noh{c, v, nohOndInser, &this->sent, &this->sent, 1};
      nohAretornar = nohOndInser->direito;
      alturaAlmentou = true;
    }
    else if (c >= nohOndInser->chave)
    {
      nohOndInser->direito = new Noh{c, v, nohOndInser, &this->sent, &this->sent, 1};
      nohAretornar = nohOndInser->direito;
      if (nohOndInser->esquerdo == &this->sent)
      {
        alturaAlmentou = true;
      }
    }
    else
    {
      nohOndInser->esquerdo = new Noh{c, v, nohOndInser, &this->sent, &this->sent, 1};
      nohAretornar = nohOndInser->esquerdo;
      if (nohOndInser->direito == &this->sent)
      {
        alturaAlmentou = true;
      }
    }
    if (alturaAlmentou)
    {
      while (nohOndInser != this->raiz)
      {
        nohOndInser->altura += 1;
        nohOndInser = nohOndInser->pai;
      }
      concertarInsercao(nohAretornar->pai);
    }
    return Iterador(nohAretornar, this);
  }

  // --------------------------------------------------------------------------

  // Deve retornar um iterador apontando para o elemento de chave "c",
  // caso essa chave esteja presente no dicionário.
  // Se a chave não estiver presente, deve retornar um iterador para o "fim".

  Iterador buscar(TC c)
  {
    Iterador nohQueEuEstou = this->begin();
    this->sent.chave = c;
    Iterador fimDoDicio = this->end();
    cout << "O set da nova chave foi " << fimDoDicio.chave() << "\n";
    while (nohQueEuEstou.chave() != fimDoDicio.chave())
    {
      ++nohQueEuEstou;
    }
    if (nohQueEuEstou == fimDoDicio)
    {
      cout << "Não encontrei a chave\n";
    }
    else
    {
      cout << "Encontrei a chave\n";
    }
    return nohQueEuEstou;
  }

  Noh *buscarParaInserir(TC c)
  {
    Noh *nohQueEuEstou = this->raiz->esquerdo;
    Noh *nohDoPai = nullptr;
    this->sent.chave = c;
    if (nohQueEuEstou->chave == sent.chave)
    {

      nohDoPai = this->raiz;
    }
    else
    {

      while (nohQueEuEstou->chave != c)
      {
        nohDoPai = nohQueEuEstou;

        if (c >= nohQueEuEstou->chave)
        {

          nohQueEuEstou = nohQueEuEstou->direito;
        }
        else
        {
          nohQueEuEstou = nohQueEuEstou->esquerdo;
        }
      }
    }

    return nohDoPai;
  }

  void printarDicionario()
  {
    Iterador nohQueEuEstou = this->begin();
    Iterador fim = this->end();
    cout << nohQueEuEstou.chave() << '\n';
    cout << fim.alturaIterador() << '\n';

    while (nohQueEuEstou != fim)
    {
      cout << "||== Chave: " << nohQueEuEstou.chave() << '\n';
      cout << "||== Valor: " << nohQueEuEstou.valor() << '\n';
      cout << "||== Altur: " << nohQueEuEstou.alturaIterador() << '\n';
      cout << "========================\n";
      ++nohQueEuEstou;
    }
  }

  // --------------------------------------------------------------------------

  // Este método deve remover do dicionário o elemento apontado pelo iterador
  // recebido, caso o iterador aponte para um elemento do dicionário.
  //
  // É PRÉ-CONDIÇÃO da função que o iterador recebido estará apontando
  // para algum elemento ou para o "fim" do dicionário.
  //
  // Se o iterador apontar para o "fim" do dicionário,
  // a função deve simplesmente deixar o dicionário inalterado.

  void remover(Iterador i);
  //  {
  //  // TODO
  //  }

}; // class DicioAVL

// -----------------------------------------------------------------------------

#endif
