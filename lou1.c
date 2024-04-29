//Author: Louis w Pierce III
//Program: Mean/Max/Mode/Min/List	
//Date:4-16-24

#include <stdio.h>

#define FILE_NAME "Design document (LP).txt"

	int main() {
		FILE *fptr;
		fptr = fopen(FILE_NAME, "w");
	
		if(fptr ==NULL) {
		printf("I could'nt open the file!\n");
	return 0;
	}
	
	fprintf(fptr, "Hello\n");
	
	fclose(fptr);
	
	return 0;
	}
