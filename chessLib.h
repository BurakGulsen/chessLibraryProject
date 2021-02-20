#define CHESSLIB_H_


typedef struct poz{
	
	
	char dusey;
	short yatay;
	
}poz;


int ** createMatrix();
void printMatrix(int ** );
struct poz *hareketSah(struct poz );
struct poz *hareketVezir(struct poz );
struct poz *hareketFil(struct poz );
struct poz *hareketPiyon(struct poz );
struct poz *hareketAt(struct poz );
struct poz *hareketKale(struct poz );
void hareketYazdir(char , struct poz );
