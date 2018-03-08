//Jeffrey Yang
//1606512
//CMPS 12B
// 1/13/2018
// test client for dictionary ADT
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

#define MAX_LEN 180

int main(int argc, char* argv[]){
   Dictionary A = newDictionary();
   char* k;
   char* v;
   char* word1[] = {"asdf", "fff", "12b", "xxx"};
   char* word2[] = {"foo","bar","blah","galumph"};
   int i;

   for(i=0; i<4; i++){
      insert(A, word1[i], word2[i]);
   }


   printDictionary(stdout, A);


   for(i=0; i<4; i++){
      k = word1[i];
      v = lookup(A, k);
      printf("key=\"%s\" %s\"%s\"\n", k, (v==NULL?"not found ":"value="), v);
   }



   // insert(A, "fff", "glow"); // error: key collision

   delete(A, "asdf");
   delete(A, "xxx");
   // delete(A, "seven"); key nonexistent
   printDictionary(stdout, A);

   makeEmpty(A);
   printf("%s\n", (isEmpty(A)?"true":"false"));

   freeDictionary(&A);

   return(EXIT_SUCCESS);
}
