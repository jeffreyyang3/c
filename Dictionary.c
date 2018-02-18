//Jeffrey Yang
//jedyang
//CMPS 12M
//2/17/18
//Dictionary.c
//extends dictionary ADT

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include "Dictionary.h"


typedef struct NodeObj{
	char* key;
	char* value;
	struct NodeObj* next;
} NodeObj;

typedef NodeObj* Node;

typedef struct DictionaryObj{
	Node head;
	int numItems;
} DictionaryObj;

Node newNode(char* k, char* v){
	Node N = malloc(sizeof(NodeObj));
	assert(N != NULL);
	N->key = k;
	N->value = v;
	return N;
}

void freeNode(Node* pN){
	if(pN != NULL && *pN != NULL){
		free(*pN);
		*pN = NULL;
	}
}

void freeDictionary(Dictionary* pD){
	if(pD != NULL && *pD != NULL){
		makeEmpty(*pD);
		free(*pD);
		*pD = NULL;
	}
}

int isEmpty(Dictionary D){
	if(D -> numItems == 0){
		return 1;
	}
	else{
		return 0;
	}
}

char* lookup(Dictionary D, char* k){
       Node N = D->head;
       if( D == NULL ){
         fprintf(stderr, "Dictionary Error: calling lookup() on NULL Dictionary\n");
         exit(EXIT_FAILURE);
       }
       while(N != NULL){
         if(strcmp(N->key,k) == 0){
            return N->value;
				 }
        		N = N->next;
       }
       return NULL;
}

void insert(Dictionary D, char* k, char* v){
	if(lookup(D, k) != NULL){
		fprintf(stderr, "Dictionary Error: lookup on null reference \n");
		exit(EXIT_FAILURE);
	}
	else if(size(D) == 0){
		D->head = newNode(k,v);
		D->numItems = 1;
	}
	else{
		Node temp = D-> head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode(k,v);
		D->numItems++;
	}
}
void printDictionary(FILE* out, Dictionary D){
	Node temp = D->head;
	for(int i = 0; i < D->numItems; i++){
		fprintf(out, "%s %s \n", temp->key, temp->value);
		temp = temp->next;
	}
}
void makeEmpty(Dictionary D){
	D->head = NULL;
	D -> numItems = 0;
}
void delete(Dictionary D, char* k){
	if(lookup(D,k) == NULL){
		fprintf(stderr, "Dictionary Error: key nonexistent \n");
		exit(EXIT_FAILURE);
	}
	if(D -> numItems == 1){
		makeEmpty(D);
	}
	if(strcmp(D->head->key, k) == 0){
		D->head = D ->head->next;
	}
	else{
		Node temp = D -> head;
		while(strcmp(temp->next-> key, k) != 0){
			temp = temp->next;
		}
		temp->next = temp->next->next;
		D->numItems--;
	}
}
Dictionary newDictionary(){
   	Dictionary D = malloc(sizeof(DictionaryObj));
   	assert(D!=NULL);
   	D->head = NULL;
    D->numItems = 0;
  	return D;
}
int size(Dictionary D){
	return D -> numItems;
}
