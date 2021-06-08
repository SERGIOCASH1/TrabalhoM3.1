// Trabalho M3.1 - ALG II - Sérgio Venturi.cpp 

#include <iostream>
#include <time.h>

struct Jogador {
  std::string nome;
  int pontuacao;
};

void shellSort(Jogador* vetorJogador, int tamanhoVetor) {
    for (int gap = tamanhoVetor/2; gap > 0; gap /= 2){
        for (int i = gap; i < tamanhoVetor; i += 1){    
            auto temp = vetorJogador[i];
            int j, pontos = vetorJogador[i].pontuacao;  
                     
            for (j = i; j >= gap && vetorJogador[j - gap].pontuacao > pontos; j -= gap)
                vetorJogador[j] = vetorJogador[j - gap];
            vetorJogador[j] = temp;
        }
    }
}

int particao(Jogador* vetor, int esquerda, int direita){
  int i = esquerda, j = direita;
  int pivo = vetor[(esquerda + direita) / 2].pontuacao;
  while (i <= j) {
    while (vetor[i].pontuacao < pivo)
      i++;
    while (vetor[j].pontuacao > pivo)
      j--;
    if (i <= j) {
      auto tmp = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = tmp;
      i++;
      j--;
    }
  };
  return i;
}

void quickSort(Jogador* vetor, int esquerda, int direita) {
  int index = particao(vetor, esquerda, direita);
  if (esquerda < index - 1)
    quickSort(vetor, esquerda, index - 1);
  if (index < direita)
    quickSort(vetor, index, direita);
}

void valoresAleatorios(Jogador* vetorJogador, int tamanhoVetor) {
  int tamanhoNome;
  srand(time(NULL));
  std::string alfabeto[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v", "w", "x","y","z"};

  for (int i = 0; i < tamanhoVetor; i++) {
    std::string nomeJogador = "";
    tamanhoNome = (rand() % 10) + 3;

    for(int j = 0; j < tamanhoNome; j++){
      int letra = (rand() % 26);          
      nomeJogador.append(alfabeto[letra]);
          
    }
    vetorJogador[i].nome = nomeJogador;
    vetorJogador[i].pontuacao = (rand() % 251);
  }
}

void bubbleSort(Jogador* vetorJogador, int tamanhoVetor){
  for (int j = 0; j < tamanhoVetor; j++) {
		bool ordenado = true;
		for (int i = 0; i < tamanhoVetor - 1 - j; i++) {
			if (vetorJogador[i].nome > vetorJogador[i + 1].nome) {
				auto temp = vetorJogador[i];
				vetorJogador[i] = vetorJogador[i + 1];
				vetorJogador[i + 1] = temp;
				ordenado = false;
			}
		}
		if (ordenado)
			break;
	}
}

void melhoresPontuacoes10(Jogador* vetorJogador, int tamanhoVetor){
  std::cout << " --------------- Top 10 ---------------\n\n" ;
      for(int i = 1; i <= 10; i++){
        std::cout << vetorJogador[tamanhoVetor - i].nome << " - " << vetorJogador[tamanhoVetor - i].pontuacao << std::endl;
      }
      std::cout << std::endl;
}

void melhoresPontuacoes100(Jogador* vetorJogador, int tamanhoVetor){
    std::cout << " -------------- Top 100 ---------------\n\n" ;
      for(int i = 1; i <= 100; i++){
        std::cout << vetorJogador[tamanhoVetor - i].nome << " - " << vetorJogador[tamanhoVetor - i].pontuacao << std::endl;
      }
      std::cout << std::endl;
}

void exibirVetor(Jogador* vetor, int tamanho){
  for (int i = 0; i < tamanho; i++) {
		std::cout << vetor[i].nome << " - " << vetor[i].pontuacao << "\n";
	}
	std::cout << "\n\n";
}

int main()
{
  srand(time(NULL));

  int opcao;
  int tamanhoVetor = 1000;
  Jogador* vetorJogador = new Jogador[tamanhoVetor];

  valoresAleatorios(vetorJogador, tamanhoVetor);
  std::cout << "Vetor baguncado: \n" << std::endl;
  exibirVetor(vetorJogador, tamanhoVetor);

  while (true){
    std::cout << "Selecione uma das opcoes para ordenacao: " << std::endl;
    std::cout << "Exibir jogadores em ordem alfabetica (1) " << std::endl;
    std::cout << "Melhores pontuacoes TOP 10           (2) " << std::endl;
    std::cout << "Melhores pontuacoes TOP 100          (3) " << std::endl;
    std::cout << "Gerar outro vetor aleatorio          (4) " << std::endl;
    std::cout << "Sair                                 (-) " << std::endl;
    
    std::cin >> opcao;
    std::cout << "\n";

    if (opcao == 1){
      bubbleSort(vetorJogador, tamanhoVetor);
      std::cout << "Vetor Organizado: \n" << std::endl;
      exibirVetor(vetorJogador, tamanhoVetor);
    }
    else if(opcao == 2){
      quickSort(vetorJogador, 0, tamanhoVetor);
      melhoresPontuacoes10(vetorJogador, tamanhoVetor);
    }
    else if(opcao == 3){
      shellSort(vetorJogador, tamanhoVetor);
      melhoresPontuacoes100(vetorJogador, tamanhoVetor);
      
    }
    else if(opcao == 4){
      valoresAleatorios(vetorJogador, tamanhoVetor);
      std::cout << "Vetor baguncado: \n" << std::endl;
      exibirVetor(vetorJogador, tamanhoVetor);
    }
    else{
      break;
    }
  }

 delete[] vetorJogador;
}


