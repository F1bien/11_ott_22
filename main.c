
#include <stdio.h>
#include <string.h>


struct concerto
{
	int cod_concerto;
	char nome_artista[100];
	char genere[100];
};

struct data
{
	int cod_data;
	int cod_concerto;
	int cod_luogo;
	char data[10];
	int prevendite;
	float prezzo;
};

struct luogo
{
	int cod_luogo;
	char citta[100];
	int n_posti;
};

void load_data_concerti( struct concerto concerti[], FILE *fp ) {
	
	int i = 0;
	while( !feof(fp) ) {
		fscanf(fp, "%d%s%s", concerti[i].cod_concerto, concerti[i].nome_artista, concerti[i].genere);
		i += 1;
		
	}
	printf("dati concerti caricati\n");
}

void load_data_date( struct data date[], FILE *fp ) {
	
	int i = 0;
	while( !feof(fp) ) {
		fscanf(fp, "%d%d%d%s%d%f", date[i].cod_concerto, date[i].cod_data, date[i].cod_luogo, date[i].data, date[i].prevendite, date[i].prezzo);
		i += 1;
		
	}
	printf("dati date caricati\n");
}

void load_data_luoghi( struct luogo luoghi[], FILE *fp ) {
	
	int i = 0;
	while( !feof(fp) ) {
		fscanf(fp, "%s%d%d", luoghi[i].citta, luoghi[i].cod_luogo, luoghi[i].n_posti);
		i += 1;
		
	}
	printf("dati luoghi caricati\n");
}


// eserciziono 1
/*
	Stampare il concerto che ha realizzato l'incasso maggiore in prevendite
*/
float incassi ( struct data date[], int cod ) {

	int i;
	float output = 0;

	for ( i = 0 ; i < 100 ; i += 1 ) {
		if ( cod == date[i].cod_concerto ) {
			output += date[i].prevendite * date[i].prezzo;
		}
	}
	return output;
}

float eserciziono_1 ( struct concerto concerti[], struct data date[] ) {

	float temp = 0, max = 0;
	int i, max_i;

	for ( i = 0, max_i = 0 ; i < 100 ; i += 1 ) {
		temp = incassi(date, concerti[i].cod_concerto);
		if ( temp >= max ) {
			max = temp;
			max_i = i;
		}

	}

	return max_i;
}


// eserciziono 2
/*
	Per ogni concerto stampare il nome dell'artista, e la lista dei luoghi in cui si sarà
	eseguito,indicandone la quantità
*/
int lista_luoghi ( struct data date[], struct luogo luoghi[], int cod ) {

	int count = 0, i, j;

	for ( i = 0 ; i < 100 ; i += 1 ) {
		if ( date[i].cod_concerto == cod ) {
			for ( j = 0 ; j < 100 ; j += 1 ) {
				if ( date[i].cod_luogo == luoghi[j].cod_luogo ) {
					printf("\n\t%s", luoghi[j].citta);
				}
			}

			printf("\t %s", date[i].data);
			count += 1;
		}
	}

	return count;
}

void esercizio_2 ( struct concerto concerti[], struct data date[], struct luogo luoghi[] ) {

	int count, i;

	for ( i = 0 ; i < 100 ; i += 1 ) {
		printf("\n\tartista : %s", concerti[i].nome_artista);

		count = lista_luoghi(date, luoghi, concerti[i].cod_concerto);

		printf("\n\tper un totale di : %d", count);

	}


}


// eserciziono 3
/*
	Preso in input il nome di un artista X,stampare il calendario dei suoi concerti indicando
	la data e il luogo di esecuzione
*/
int ricerca_nome ( struct concerto concerti[], char input[] ) {

	int i;

	for ( i = 0 ; i < 100 ; i += 1 ) {
		if ( strcmp(concerti[i].nome_artista, input) == 0 ) {
			return i;
		}
	}

}

void esercizio_3 ( struct concerto concerti[], struct data date[], struct luogo luoghi[], char input[] ) {

	int i, cod;

	cod = ricerca_nome(concerti, input);

	printf("\n\tartista : %s", concerti[cod].nome_artista);

	lista_luoghi(date, luoghi, cod);

}

// main
int main () {
	
	int exit = 0;
	
	char fileN_concerti[100];
	strcpy(fileN_concerti, "data_conerti.txt");
	char fileN_data[100];
	strcpy(fileN_data, "data_data.txt");
	char fileN_luoghi[100];
	strcpy(fileN_luoghi, "data_luoghi.txt");
	
	FILE *fileP_concerti;
	FILE *fileP_date;
	FILE *fileP_luoghi;
	
	fileP_concerti = fopen(fileN_concerti, "r");
	if ( !fileP_concerti ) {
		printf("file %s non trovato\n", fileN_concerti);
		
		fclose(fileP_concerti);
		fileP_concerti = fopen(fileN_concerti, "w");
		fclose(fileP_concerti);
		fileP_concerti = fopen(fileN_concerti, "r");
		if ( !fileP_concerti ) {
			printf("imposibile aprire il file %s\n", fileN_concerti);
			fclose(fileP_concerti);
			exit = 1;
		}
	}
	
	fileP_date = fopen(fileN_data, "r");
	if ( !fileP_date ) {
		printf("file %s non trovato\n", fileN_data);
		
		fclose(fileP_date);
		fileP_date = fopen(fileN_data, "w");
		fclose(fileP_date);
		fileP_date = fopen(fileN_data, "r");
		if ( !fileP_date ) {
			printf("imposibile aprire il file %s\n", fileN_data);
			fclose(fileP_date);
			exit = 1;
		}
	}
	
	fileP_luoghi = fopen(fileN_luoghi, "r");
		if ( !fileP_luoghi ) {
		printf("file %s non trovato\n", fileN_luoghi);
		
		fclose(fileP_luoghi);
		fileP_luoghi = fopen(fileN_luoghi, "w");
		fclose(fileP_luoghi);
		fileP_luoghi = fopen(fileN_luoghi, "r");
		if ( !fileP_luoghi ) {
			printf("imposibile aprire il file %s\n", fileN_luoghi);
			fclose(fileP_luoghi);
			exit = 1;
		}
	}
	
	if ( exit == 0 ) {

		struct concerto concerti[100];
		struct data date[100];
		struct luogo luoghi[100];
	
		load_data_concerti(concerti, fileP_concerti);
		load_data_date(date, fileP_date);
		load_data_luoghi(luoghi, fileP_luoghi);
		
		fclose(fileP_concerti);
		fclose(fileP_date);
		fclose(fileP_luoghi);
		
		// esercizi
		
		int max_i;

		max_i = eserciziono_1(concerti, date);
		printf("\n\tl' artista che ha incassoto di piu e' %s\n", concerti[max_i].nome_artista);

		esercizio_2(concerti, date, luoghi);

		printf("\n\tINserire nome artista");
		
		char input[100];
		scanf("%s", input);

		esercizio_3(concerti, date, luoghi, input);

	}
	
	return 0;
}

