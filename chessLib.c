#include <stdio.h>
#include <stdlib.h>
#include "chessLib.h"
#define M 8





int ** createMatrix()
{

    int a;
    int ** board = (int**)(calloc(M,sizeof(int*)));

    for(a = 1; a <= M; a++)
    {
        board[a] = (int *) calloc(M, sizeof(int));
    }

    return board;
}

void printMatrix(int ** board)
{

    int i,j;
    for( i =0; i<M; i++)
    {
        for(j=0; j<M; j++)
        {
            printf("%d ",board[i][j]);
        }
        puts("");
    }

}

struct poz *hareketSah(struct poz ilkPoz)
{
    int dusey = ilkPoz.dusey%65;
    int yatay = 7-(ilkPoz.yatay-2);


    int **board = createMatrix();


    if(yatay == 1)
    {

        int i,j;

        for(i=yatay; i<=yatay+1; i++)
        {
            for(j=dusey-1; j<= dusey+1; j++)
            {

                board[i][j]=1;
                board[yatay][dusey]=2;
            }
        }

    }
    else if(yatay == 8)
    {

        int a,b;

        for(a=yatay; a>=yatay-1; a--)
        {
            for(b=dusey-1; b<= dusey+1; b++)
            {

                board[a][b]=1;
                board[yatay][dusey]=2;
            }
        }


    }
    else if(dusey == 0)
    {

        int i,j;

        for(i=yatay-1; i<=yatay+1; i++)
        {
            for(j=dusey; j<= dusey+1; j++)
            {

                board[i][j]=1;
                board[yatay][dusey]=2;
            }
        }

    }
    else if(dusey == 7)
    {

        int a,b;

        for(a=yatay-1; a<=yatay+1; a++)
        {
            for(b=dusey; b>= dusey-1; b--)
            {

                board[a][b]=1;
                board[yatay][dusey]=2;
            }
        }

    }


    else
    {

       int i,j;
        for(i=yatay-1; i<=yatay+1; i++)
        {
            for(j=dusey-1; j<=dusey+1; j++)
            {


                if(i == yatay && j==dusey)
                {

                    board[i][j] = 2;

                }
                else
                {

                    board[i][j] = 1;
                }

            }
        }
    }

    int a,b;
    for(a=1; a<=M; a++)
    {
        for(b=0; b<M; b++)
        {
            printf("%d ",board[a][b]);


        }
        puts("");
    }

};


struct poz *hareketVezir(struct poz ilkPoz)
{
    int i,j;
    int dusey = ilkPoz.dusey%65;
    int yatay = 7-(ilkPoz.yatay-2);


    int **board = createMatrix();

    for(i=1; i<=M; i++)
    {
        for(j=0; j<M; j++)
        {
            board[i][dusey]=1;
            board[yatay][j] = 1;
            board[yatay][dusey] = 2;

        }

    }
    int x=0;
    int y=0;

    board[yatay][dusey] = 2;

    while(x<=M && y<=M)
    {
        x++;
        y++;

        if((yatay-x > 0)&&(dusey-y > -1))
        {

            board[yatay-x][dusey-y] = 1;

        }
        if((yatay+x <9) && (dusey+y < 8))
        {

            board[yatay+x][dusey+y] = 1;
        }
        if((yatay-x >0) && (dusey+y < 8))
        {

            board[yatay-x][dusey+y] = 1;
        }
        if((yatay+x <9) && (dusey-y > -1))
        {

            board[yatay+x][dusey-y] = 1;
        }

    }

    int a,b;
    for(a=1; a<=M; a++)
    {
        for(b=0; b<M; b++)
        {
            printf("%d ",board[a][b]);


        }
        puts("");
    }


};

struct poz *hareketFil(struct poz ilkPoz)
{


    int dusey = ilkPoz.dusey%65;
    int yatay = 7-(ilkPoz.yatay-2);


    int **board = createMatrix();

    int i=0;
    int j=0;

    board[yatay][dusey] = 2;

    while(i<=M && j<=M)
    {
        i++;
        j++;

        if((yatay-i > 0)&&(dusey-j > -1))
        {

            board[yatay-i][dusey-j] = 1;

        }
        if((yatay+i <9) && (dusey+j < 8))
        {

            board[yatay+i][dusey+j] = 1;
        }
        if((yatay-i >0) && (dusey+j < 8))
        {

            board[yatay-i][dusey+j] = 1;
        }
        if((yatay+i <9) && (dusey-j > -1))
        {

            board[yatay+i][dusey-j] = 1;
        }

    }

    int a,b;
    for(a=1; a<=M; a++)
    {
        for(b=0; b<M; b++)
        {
            printf("%d ",board[a][b]);


        }
        puts("");
    }


};

struct poz *hareketPiyon(struct poz ilkPoz)
{


    int dusey = ilkPoz.dusey%65;
    int yatay = 7-(ilkPoz.yatay-2);


    int **board = createMatrix();

    if(yatay == 1)
    {

        printf("Tahta disi !\n");
        board[yatay][dusey]=2;
    }
    else
    {
        board[yatay-1][dusey]=1;
        board[yatay][dusey] = 2;

    }

    int a,b;
    for(a=1; a<=M; a++)
    {
        for(b=0; b<M; b++)
        {
            printf("%d ",board[a][b]);


        }
        puts("");
    }


};



struct poz *hareketAt(struct poz ilkPoz)
{

    int i,j;
    int dusey = ilkPoz.dusey%65;
    int yatay = 7-(ilkPoz.yatay-2);


    int **board = createMatrix();

     if(yatay == 1 )
    {

        board[yatay][dusey]=2;
        board[yatay+1][dusey-2]=1;
        board[yatay+1][dusey+2]=1;
        board[yatay+2][dusey-1]=1;
        board[yatay+2][dusey+1]=1;

    }
    else if(yatay == 2)
    {

        board[yatay][dusey]=2;
        board[yatay-1][dusey-2]=1;
        board[yatay-1][dusey+2]=1;
        board[yatay+2][dusey-1]=1;
        board[yatay+2][dusey+1]=1;
        board[yatay+1][dusey-2]=1;
        board[yatay+1][dusey+2]=1;


    }
    else if(yatay == 8)
    {

        board[yatay][dusey]=2;
        board[yatay-1][dusey-2]=1;
        board[yatay-1][dusey+2]=1;
        board[yatay-2][dusey+1]=1;
        board[yatay-2][dusey-1]=1;
    }
    else if(yatay == 7)
    {

        board[yatay][dusey]=2;
        board[yatay+1][dusey-2]=1;
        board[yatay+1][dusey+2]=1;
        board[yatay-2][dusey-1]=1;
        board[yatay-2][dusey+1]=1;
        board[yatay-1][dusey-2]=1;
        board[yatay-1][dusey+2]=1;

    }
    else if(dusey == 0)
    {

        board[yatay][dusey]=2;
        board[yatay+1][dusey+2]=1;
        board[yatay+2][dusey+1]=1;
        board[yatay-2][dusey+1]=1;
        board[yatay-1][dusey+2]=1;

    }
    else if(dusey == 1)
    {

        board[yatay][dusey]=2;
        board[yatay+2][dusey-1]=1;
        board[yatay+2][dusey+1]=1;
        board[yatay+1][dusey+2]=1;
        board[yatay-1][dusey+2]=1;
        board[yatay-2][dusey+1]=1;
        board[yatay-2][dusey-1]=1;

    }

    else
    {

        board[yatay][dusey] = 2;

        board[yatay-1][dusey-2]=1;
        board[yatay+1][dusey-2]=1;
        board[yatay-1][dusey+2]=1;
        board[yatay+1][dusey+2]=1;
        board[yatay-2][dusey-1]=1;
        board[yatay-2][dusey+1]=1;
        board[yatay+2][dusey-1]=1;
        board[yatay+2][dusey+1]=1;



    }
    
    int a,b;
    for(a=1; a<=M; a++)
    {
        for(b=0; b<M; b++)
        {
            printf("%d ",board[a][b]);


        }
        puts("");
    }


};

struct poz *hareketKale(struct poz ilkPoz)
{
    int i,j;
    int dusey = ilkPoz.dusey%65;
    int yatay = 7-(ilkPoz.yatay-2);


    int **board = createMatrix();

    for(i=1; i<=M; i++)
    {
        for(j=0; j<M; j++)
        {
            board[i][dusey]=1;
            board[yatay][j] = 1;
            board[yatay][dusey] = 2;

        }

    }

    int a,b;
    for(a=1; a<=M; a++)
    {
        for(b=0; b<M; b++)
        {
            printf("%d ",board[a][b]);


        }
        puts("");
    }



};

void hareketYazdir(char tas, struct poz ilkPoz)
{


    switch(tas)
    {

    case 'S':

        *hareketSah(ilkPoz);
        break;

    case 'V':
        *hareketVezir(ilkPoz);
        break;

    case 'F':
        *hareketFil(ilkPoz);
        break;

    case 'A':
        *hareketAt(ilkPoz);
        break;

    case 'K':
        *hareketKale(ilkPoz);
        break;

    case 'P':
        *hareketPiyon(ilkPoz);
        break;

    }

}

