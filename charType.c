//Jeffrey Yang
//1606512
//CMPS 12M
//2/11/2018
//reads lines from an input file, and analyzes the content of each line
//charType.c

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
void extract_chars(char* s, char* a, char* d, char* p, char* w);
int main(int argc, char* argv[]){
    FILE* in;
    in = fopen(argv[1], "r");
    FILE* out;
    out = fopen(argv[2], "w");
    char* line;
    //advanced efficient memory allocation
    line  = malloc(6969);
    char* letters;
    letters = malloc(6969);
    char* numbers;
    numbers = malloc(6969);
    char* punctuation;
    punctuation = malloc(6969);
    char* spaces;
    spaces = malloc(6969);
    int linenumber = 1;
    // check command line for correct number of arguments
   if(argc != 3){
      printf("Usage: %s input-file output-file\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   // open input file for reading
   if(in == NULL){
      printf("Unable to read from %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   // open output file for writing
   if(out == NULL){
      printf("Unable to write to file %s\n", argv[2]);
      exit(EXIT_FAILURE);
   }

    while(fgets(line, 6969, in) != NULL){
    	//zu used because d gave a warning
    	fprintf(out, "line %d contains:\n", linenumber);
    	extract_chars(line, letters, numbers, punctuation,spaces);
	    if(strlen(letters) != 1){
		   fprintf(out, "%zu alphabetic characters: %s \n", strlen(letters), letters);
	    }
	    else{
		   fprintf(out, "1 alphabetic character: %s \n", letters);
	    }
	    if(strlen(numbers) != 1){
		    fprintf(out, "%zu numeric characters: %s \n", strlen(numbers), numbers);
	    }
	    else{
		    fprintf(out, "1 numeric character: %s \n", numbers);
	    }
	    if(strlen(punctuation) != 1){
		    fprintf(out, "%zu punctuation characters: %s \n", strlen(punctuation), punctuation);
	    }
	    else{
		    fprintf(out, "1 punctuation character: %s \n", punctuation);
	    }
	    if(strlen(spaces) != 1){
		    fprintf(out, "%zu whitespace characters: %s \n", strlen(spaces), spaces);
	    }
	    else{
		    fprintf(out, "1 whitespace character: %s \n", spaces);
	    }
	    linenumber++;
	}
	//memory management

    free(line);
    line = NULL;
    free(letters);
    letters = NULL;
    free(numbers);
    numbers = NULL;
    free(punctuation);
    punctuation = NULL;
    free(spaces);
    spaces = NULL;
    fclose(in);
    fclose(out);
    return EXIT_SUCCESS;


}
void extract_chars(char* s, char* a, char* d, char* p, char* w){
	int aindex = 0;
	int dindex = 0;
	int pindex = 0;
	int windex = 0;
	for(int aa = 0; aa < strlen(s); aa++){ //fills each array with correct type from
		if(isalpha((int)s[aa])){
			a[aindex] = s[aa];
			aindex++;
		}
		if(isdigit((int)s[aa])){
			d[dindex] = s[aa];
			dindex++;
		}
		if(ispunct((int)s[aa])){
			p[pindex] = s[aa];
			pindex++;
		}
		if(isspace((int)s[aa])){
			w[windex] = s[aa];
			windex++;
		}
	}
	a[aindex] = '\0';
	d[dindex] = '\0';
	p[pindex] = '\0';
	w[windex] = '\0';

}
