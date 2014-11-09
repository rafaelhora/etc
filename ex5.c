#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 1
#define TRUE 1

int main(void)
{
	int tam[3] = {0}, i=0, cont, sin = 1, c = 0, d =0 ; //tam dá o tamanho de cada conjunto e i o estado da leitura
	char *str[3], temp[3], *dom, *cdm; //cria um vetor para cada conjunto e outro para a função 
	
	str[0] = (char *) malloc (sizeof(char)); 
	str[1] = (char *) malloc (sizeof(char)); 
	
	str[0][0] = str[0][1] = '\0';

	while(fgets(temp,3,stdin) != NULL && i<2)
	{
		
		if (temp[0] == '#')
		{
			i++;
			continue;
		}

		str[i][tam[i]] = temp[0];
		tam[i]++;
		str[i] = (char *) realloc(str[i], (tam[i] + 1) * sizeof(char));
		str[i][tam[i]] = '\0';
		if(DEBUG) printf("%s\n", str[i]);
	}

	printf("\nA = %d | B = %d", tam[0], tam[1]);

	str[2] = (char *) malloc ((80) * sizeof(char));
	fgets(str[2], 80, stdin);
	tam[2] = strlen(str[2]);
	if(DEBUG) printf("-%s-", str[2]);
	
	dom = (char *) malloc (sizeof(char));
	cdm = (char *) malloc (sizeof(char));

	for(cont = 0; cont < tam[2] ; cont++)
	{
		if(str[2][cont] != '{' && str[2][cont] != '(' && str[2][cont] != ',' && str[2][cont] != ')' && str[2][cont] != '}')
		{
			if(sin > 0 && str[2][cont] != ' ')
			{
				dom[d] = str[2][cont];
				d++;
				dom = (char *) realloc (dom, (d+1) * sizeof(char));
			}
			else
			{
				cdm[c] = str[2][cont];
				c++;
				cdm = (char *) realloc (cdm, (c+1) * sizeof(char));
			}
			sin *=-1;
		
		}
	}
	
	if(DEBUG) printf("\ndom = %s | cdm = %s|\n", dom, cdm);

	int inj=0, sobr=0;
	d = strlen(dom)-1;
	c = strlen(cdm);
		
	if(DEBUG) printf("\n d = %d | c = %d\n", d, c);

	if(tam[0] == d) inj = 1;
	if(tam[1] == c) sobr = 1;
	
	if(DEBUG) printf("\nSobr = %d, Inj = %d\n", sobr, inj); 

	if(tam[0] < d)
	{
		printf("relaca\n");
		return 0;
	}
	
	if(sobr == 1 && inj == 1) 
	{	
		printf("bijetora\n");
		return 3;
	}
	
	if(sobr == 1)
	{
		printf("sobrejetora\n");
		return 2;
	}
	if(inj == 1) 
	{	
		printf("injetora\n");
		return 1;
	}

	printf("funcao\n");
	return 4;
	
}
