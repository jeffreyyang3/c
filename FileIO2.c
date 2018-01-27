#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
	FILE* in; /* file handle for input */
	FILE* out; /* file handle for output */
	char word[256]; /* char array to store words from input file */
/* check command line for correct number of arguments */
	if( argc != 3 ){
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
/* open input file for reading */
	in = fopen(argv[1], "r");
	if( in==NULL ){
		printf("Unable to read from file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
/* open output file for writing */
	out = fopen(argv[2], "w");
	if( out==NULL ){
		printf("Unable to write to file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
/* read words from input file, print on separate lines to output file*/
	while( fscanf(in, " %s", word) != EOF ){
		char s[] = "asdf123";
		int i = 0;
		int j = strlen(s)-1;
		int temp;
		while(i < j){
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;
		}
		for(i = 0;i < j; i++){
			fprintf(out, "%c", s[i]);
		}
		fprintf(out, "\n");
	}


/* close input and output files */
	fclose(in);
	fclose(out);
	return(EXIT_SUCCESS);
}

