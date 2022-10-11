
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
		
		
		
		
	}
	
	
	
	

	
	return 0;
}

