#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "romai.h"

void mainTasks( FILE *stream ){
	char buffer[1023];
	
	int cap = 4;
	int cnt = 0;
	char **lines = (char**)malloc( cap * sizeof(char *));
	if( lines == NULL ){
		fprintf(stderr, "Memory allocation unsuccesful!\n");
		exit(1);
	}
	
	//Sorok beolvasása
	while( fgets(buffer, 1024, stream) != NULL ){
		buffer[strlen(buffer) - 1] = '\0'; // levettem a \n-t
		int length = strlen(buffer);
		char * line = (char*) malloc( length + 1 * sizeof(char));
		if( line == NULL ){
			fprintf(stderr, "Memory allocation unsuccesful!\n");
			exit(1);
		}
		int i;
		for( i = 0; i < length; i++ ){
			line[i] = buffer[i];
		}
		line[ length ] = '\0';
		if( cnt == cap ){
			cap *= 2;
			lines = (char**)realloc( lines, cap * sizeof(char*) );
			if( lines == NULL ){
				fprintf(stderr, "Memory allocation unsuccesful!\n");
				exit(1);
			}
		}
		lines[cnt] = line;
		cnt ++;
	}
	int i;
	for( i = 0; i < cnt; i++ ){
		printRom( lines[i] );
	}
	
	//Free
	for( int i = 0; i < cnt; i++ ){
		free(lines[i]);
	}
	free(lines);
}

