#include <stdio.h>

#include "mainTasks.h"

int main(int argc, char *argv[]){

	FILE *stream;
	
	if( argc < 2){ // Beolvasás a stdin-ről
	
		stream = stdin;
		mainTasks(stream);
	
	} else { // Beolvasás a fájlokból
		int i;
		for(i = 1; i < argc; i++){
		
			stream = fopen(argv[i], "r");
			if( stream == NULL ){
				fprintf(stderr, "File opening unsuccessful!\n");
				continue;
			}
			
			mainTasks(stream);
			fclose(stream);
		}
		
	}

	return 0;
}

