#include "ep.h"

// ######### ESCREVA O NUMERO DO SEU GRUPO AQUI, CONFORME LINK NA ESPECIFICACAO DO EP
// ignore os warning to compilador, se houver
char* grupo() {
    return("01");
}

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
// ignore os warning to compilador, se houver
char* nroUSP1() {
    //Sergio Kazuo Nomura
    return("10816781");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
// ignore os warning to compilador, se houver
char* nroUSP2() {
    //Victor Sugiyama
    return("10346593");
}


//Verifica o conteudo de um NO, se eh uma vogal ou não
bool isVogal(NO* verificar){
    if((verificar->letra == 'A')||(verificar->letra == 'E')||(verificar->letra == 'I')||(verificar->letra == 'O')||(verificar->letra == 'U')){
        return true;
    }
    return false;
}

//Pega o tamanho do array de frase e cria uma lista de NO de acordo com o tamanho.
void criarFrase(NO* inicio, char frase[]){
    int tamanho = strlen(frase);
    NO* ant = inicio;
    NO* atual = NULL;
    if(tamanho>0){
        for(int i = 1; i<tamanho; i++){
            atual = (NO*)malloc(sizeof(NO));
            atual->letra = frase[i];
            atual->prox = NULL;
            ant->prox = atual;
            ant = atual;
            //printf("\ncriou %i", i);
        }
    }
}

//Inicia a Lista com o primeiro character, retorna o primeiro NO da lista e NULL se nao tiver nenhum.
NO* inicializarLista(char frase[]){
    if(frase != NULL){
        NO* primeiro = (NO*)malloc(sizeof(NO));
        primeiro->letra = frase[0];
        primeiro->prox = NULL;
        return primeiro;
    }
    return NULL;
}

//Percorre a lista e imprime o conteudo da letra de cada NO.
void imprimirFrase(NO* frase){
    NO* aux = frase;
    while(aux){
        printf("%c", aux->letra);
        aux = aux->prox;
    }
}



// o EP consiste em implementar esta funcao
NO* codificar(NO* frase) {

    bool vogal = false;

    NO* newInicio = NULL;
    NO* ant = NULL;
    NO* atual = frase;
    NO* resp = NULL;

    //Inverte as não vogais
    while(atual){
        vogal = isVogal(atual);
        //Se o inicio da lista for vogal
        if(atual==frase&&vogal){
            resp = atual;
        }
        if(!vogal){
            if(!isVogal(atual->prox)){
                newInicio = inverterParte(atual);
                if(ant)
                    ant->prox = newInicio;
            }
            if(!resp)
                resp = newInicio;
            newInicio = NULL;
        }
        ant = atual;
        atual = atual->prox;
    }
    return resp;
}


//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------



int main() {
    char frase[500] = "ESTRUTURAS DE DADOS E MUITO LEGAL.";
    //char frase[500] = "CEBOLINHA, CASCAO E RONALDINHO GAUCHO";
    NO* primeiro = inicializarLista(frase);
    criarFrase(primeiro, frase);

	// aqui vc pode incluir codigo para inserir elementos
	// de teste na sua lista apontada por p

	// o EP sera testado com chamadas deste tipo
	//imprimirFrase(primeiro);
	NO* codificado = codificar(primeiro);

	// e aqui precisaria percorrer a lista teste para ver se ficou correta etc.
	printf("\nNO PROBLEM\n");
	//imprimirFrase(codificado);
}

// por favor nao inclua nenhum código abaixo da função main()
