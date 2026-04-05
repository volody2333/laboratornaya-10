#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER(arr, count) \
    ( { \
        __typeof__(*(arr)) _max = (arr)[0]; \
        for(int _i = 1; _i < (count); _i++) { \
            if((arr)[_i] > _max) { \
                _max = (arr)[_i]; \
            } \
        } \
        _max; \
    } )
    
    int main() {
    	char input[1000];
    	int numbers[100];
    	int count = 0;
    	
    	printf("Vvedite chisla v odnoy stroke cherez probel: ");
    	fgets(input, sizeof(input), stdin);
    	
    	char *token = strtok(input, " \n");
    	
    	while(token != NULL && count < 100) {
    		numbers[count] = atoi(token);
    		count++;
    		token = strtok(NULL, " \n");
		}
		
		if(count == 0) {
			printf("Ne vvedeno ni odnogo chisla!\n");
			return 1;
		}
		int max = MAX_NUMBER(numbers, count);
		
		printf("Maximalnoe chislo: %d\n", max);
		
		return 0;
	}

