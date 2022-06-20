#include <stdio.h>
#include <string.h>


int arab[7] = {1, 5, 10, 50, 100, 500, 1000};
char romai[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
// ASCII 0..9 = 48..57

int createNum( char c ){
	int i = (int)c;
	return i - 48;
}

int findInd( int bNum ){
	int i = 0;
	while( i < 7 && arab[i] != bNum ){
		i++;
	}
	return i;
}

void printRom( char * line ){
		int f = (int)line[0];
		if( f > 48 && f <= 57 ){ // szám (nem 0)
			int l = strlen( line );
			int tPow = 1;
			for( int i = 1; i < l; i++ ){
				tPow *= 10;
			}
			
			int i;
			for( i = 0; i < l; i++ ){
				int num = createNum( line[i] );
				int bNum = num * tPow;

				if( num == 0 ){ // Ha 0 lenne az aktuális helyiértéken
					tPow = tPow / 10;
					continue;

				} else if( num == 4 || num == 9 ){
					int theB = (num + 1) * tPow;
					int indS = findInd( tPow );
					int indT = findInd( theB );
					printf("%c%c", romai[indS], romai[indT]);
					
				} else if( num == 5 ){
					int ind = findInd( bNum ); 
					printf("%c", romai[ind]);
				
				} else { // 1, 2, 3, 6, 7, 8
					if( num > 5 ){
						int F = 5 * tPow;
						int indF = findInd( F );
						printf("%c", romai[indF]);
						num = num - 5;
					}
					int indS = findInd( tPow );
					char rNum = romai[indS];
					for( int i = 0; i < num; i++ ){
						printf("%c", rNum);
					}
				
				}
				tPow = tPow / 10;
			}
			printf("\n");
			
			
		}else if( f == 48 ){ // Ha 0
			printf("%d: wrong input!\n", 0);
		
		} else { // Ha szöveg
			printf("%s: wrong input!\n", line);
		}
}
