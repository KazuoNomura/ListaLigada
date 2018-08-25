#include "ep.h"

// ######### ESCREVA O NUMERO DO SEU GRUPO AQUI, CONFORME LINK NA ESPECIFICACAO DO EP
// ignore os warning to compilador, se houver
char* grupo() {
    return("01");
}

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
// ignore os warning to compilador, se houver
char* nroUSP1() {
    return("10816781");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
// ignore os warning to compilador, se houver
char* nroUSP2() {
    return("10346593");
}



// o EP consiste em implementar esta funcao
NO* codificar(NO* frase) {

    NO* resp = NULL;

    // sua rotina de codificacao aqui (o exemplo cria apenas um elemento X)
    resp = (NO*) malloc(sizeof(NO));
    resp->letra = 'X';
    resp->prox = NULL;

    return resp;

}

void criarFrase(NO* inicio, char frase[]){
    int tamanho = strlen(frase);
    NO* ant = inicio;
    if(tamanho>0){
        for(int i = 1; i<=tamanho; i++){
            NO* atual = (NO*)malloc(sizeof(NO));
            atual->letra = frase[i];
            atual->prox = NULL;
            ant->prox = atual;
            ant = atual;
        }
    }
}

NO* inicializarLista(char frase[]){
    if(frase != NULL){
        NO* primeiro = (NO*)malloc(sizeof(NO));
        primeiro->letra = frase[0];
        primeiro->prox = NULL;
        return primeiro;
    }
    return NULL;
}

void imprimirFrase(NO* frase){
    NO* aux = frase;
    while(aux){
        printf("%c", aux->letra);
        aux = aux->prox;
    }
}





//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------



int main() {

    char frase[500] = "ESTRUTURAS DE DADOS E MUITO LEGAL.";
    NO* lista = inicializarLista(frase);
    criarFrase(lista,frase);

	// aqui vc pode incluir codigo para inserir elementos
	// de teste na sua lista apontada por p

	// o EP sera testado com chamadas deste tipo
	NO* teste = NULL;
	//teste = codificar(p);

	// e aqui precisaria percorrer a lista teste para ver se ficou correta etc.
	imprimirFrase(lista);

}

// por favor nao inclua nenhum código abaixo da função main()
