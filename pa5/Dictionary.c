// Jeffrey Yang
// jedyang
// CMPS 12B
// 3/8/2018
// Dictionary.c
// Implements Dictionary ADT using hash tables and linked lists

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include "Dictionary.h"

const int tableSize = 101;

//provided hash functions
unsigned int rotate_left(unsigned int value, int shift) {
   int sizeInBits = 8*sizeof(unsigned int);
   shift = shift & (sizeInBits - 1);
   if ( shift == 0 )
      return value;
   return (value << shift) | (value >> (sizeInBits - shift));
}

// pre_hash()
// turn a string into an unsigned int
unsigned int pre_hash(char* input){
   unsigned int result = 0xBAE86554;
   while (*input) {
      result ^= *input++;
      result = rotate_left(result, 5);
   }
   return result;
}

// hash()
// turns a string into an int in the range 0 to tableSize-1
int hash(char* key){
   return pre_hash(key)%tableSize;
}

//////////////////

typedef struct NodeObj{
  char* key;
  char* value;
  struct NodeObj* next;
} NodeObj;

typedef NodeObj* Node;

Node newNode(char *k, char *v){
  Node N = malloc(sizeof(NodeObj));
  N -> key = k;
  N -> value = v;
  N ->next = NULL;
  return N;
}
Node findKey(Node R, char* k){
   while(R != NULL){
      if(strcmp(R->key, k) == 0){
         return R;
      }
      else{
         R = R->next;
      }
   } 
   return NULL;
}
typedef struct DictionaryObj{
  Node* ht;
  int numItems;
} DictionaryObj;

void freeNode(Node* pN){
        if(pN != NULL && *pN != NULL){
                free(*pN);
                *pN = NULL;
        }
}
void makeEmpty(Dictionary D){
  if(D == NULL){
      fprintf(stderr, "Dictionary Error: calling makeEmpty() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
  }
    
  if(D->numItems == 0){
     fprintf(stderr, "Dictionary Error: calling makeEmpty() on an empty Dictionary\n");
     exit(EXIT_FAILURE);
  }
  for(int i = 0; i < tableSize; i++){
          while(D->ht[i] != NULL){
           Node temp = D->ht[i];
           D->ht[i] = temp->next;
           D->numItems--;
           freeNode(&temp);
       }
  }
}


void insert(Dictionary D, char*k, char*v){
  Node temp = newNode(k,v);
  int index = hash(k);
  if(D->ht[index] == NULL){
    D->ht[index] = temp;
    D->numItems++;
  }
  else{
    temp->next = D->ht[index];
    D->ht[index] = temp;
    D->numItems++;
  }
}
int isEmpty(Dictionary D){
   if(D == NULL){
      fprintf(stderr, "Dictionary Error: calling isEmpty() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   return (D->numItems == 0);
}

void delete(Dictionary D, char* k){
        if(lookup(D,k) == NULL){
                fprintf(stderr, "Dictionary Error: key nonexistent \n");
                exit(EXIT_FAILURE);
        }
        int index = hash(k);
        if(findKey(D->ht[index], k) == NULL){
          fprintf(stderr, "Dictionary Error: cannot delete() non-existent key: %s\n", k);
          exit(EXIT_FAILURE);
        }
        if(findKey(D->ht[index],k) == D ->ht[index]){
          Node temp = D->ht[index];
          D -> ht[index] = D->ht[index]->next;
          freeNode(&temp);
          D->numItems--;
        }
        else{
          Node target = findKey(D->ht[index],k);
          Node temp = D->ht[index];
          while(target != temp->next){
            temp = temp->next;
          }
          temp->next = temp->next->next;
          D->numItems--;
          freeNode(&target);

        }

}

































// other methods

char* lookup(Dictionary D, char* k){
   int index = hash(k);
   Node temp = findKey(D->ht[index], k);
   if(temp == NULL){
      return NULL;
   }
   else{
      return temp->value;
   }
}

void printDictionary(FILE* out, Dictionary D){
   if(D == NULL){
      fprintf(stderr, "Dictionary Error: calling printDictionary() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   Node P;
   for(int i = 0; i<tableSize; i++){
      P = D->ht[i];
      while(P!=NULL){
         fprintf(out, "%s %s\n", P->key, P->value);
         P = P->next;
      }
   }
}





void freeArray(Dictionary D){
  free(D->ht);
}


void freeDictionary(Dictionary* pD){
        if(pD != NULL && *pD != NULL){
                makeEmpty(*pD);
                
        }
        freeArray(*pD);
        free(*pD);
        *pD = NULL;
}


Dictionary newDictionary(){
        Dictionary D = malloc(sizeof(DictionaryObj));
        assert(D!=NULL);
        D->ht = malloc(sizeof(NodeObj) * tableSize);
        D->numItems = 0;
        return D;
}


int size(Dictionary D){
	return D -> numItems;
}


