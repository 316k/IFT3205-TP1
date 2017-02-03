/*------------------------------------------------------*/
/* Prog    : Tp1_IFT3205-1-1.c                          */
/* Auteur  :                                            */
/* Date    : 18/05/2010                                 */
/* version :                                            */ 
/* langage : C                                          */
/* labo    : DIRO                                       */
/*------------------------------------------------------*/

/*------------------------------------------------*/
/* FICHIERS INCLUS -------------------------------*/
/*------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "FonctionDemo1.h"

/*------------------------------------------------*/
/* DEFINITIONS -----------------------------------*/   
/*------------------------------------------------*/
#define NAME_VISUALISER "display "
#define NAME_IMG_IN  "photograph"
#define NAME_IMG_OUT "image-Tp1_IFT3205-2-1d"

/*------------------------------------------------*/
/* PROTOTYPE DE FONCTIONS  -----------------------*/   
/*------------------------------------------------*/
void PreFFT_Translation(float** Matrix, int length, int width);

/*------------------------------------------------*/
/* PROGRAMME PRINCIPAL   -------------------------*/                     
/*------------------------------------------------*/
int main(int argc,char **argv) {
    int i,j,k;
    int length,width;
    char BufSystVisuImg[100];
    float** MatriceImgR;
    float** MatriceImgI;
    float** MatriceImgM;

    /*Allocation memoire pour la matrice image*/
    MatriceImgR=LoadImagePgm(NAME_IMG_IN,&length,&width);
    MatriceImgI=fmatrix_allocate_2d(length,width);
    MatriceImgM=fmatrix_allocate_2d(length,width);

    /*Initialisation a zero de toutes les matrices */
    for(i=0;i<length;i++) 
        for(j=0;j<width;j++) 
        {
            MatriceImgI[i][j]=0.0;
            MatriceImgM[i][j]=0.0;
        }

    // Traitement pour recentrer l'harmonique 0 de la TF au centre de l'image
    PreFFT_Translation(MatriceImgR, length, width);
  
    /*FFT*/
    FFTDD(MatriceImgR,MatriceImgI,length,width);

    

    for(i=0;i<length;i++) 
        for(j=0;j<width;j++) 
        {
            if(j > width/2 + 10 || j < width/2 - 10) {
                MatriceImgI[i][j]=0;
                MatriceImgR[i][j]=0;
            }
            
            
        }
    /*Module*/
    
    IFFTDD(MatriceImgR,MatriceImgI,length,width);
    PreFFT_Translation(MatriceImgR, length, width);
    Recal(MatriceImgR, length, width);
    /*Sauvegarde de MatriceImgM sous forme d'image pgm*/
    SaveImagePgm(NAME_IMG_OUT,MatriceImgR,length,width);

    /*Liberation memoire pour les matrices*/
    free_fmatrix_2d(MatriceImgR);
    free_fmatrix_2d(MatriceImgI); 
    free_fmatrix_2d(MatriceImgM);    

    /*Commande systeme: visualisation de Ingout.pgm*/
    strcpy(BufSystVisuImg,NAME_VISUALISER);
    strcat(BufSystVisuImg,NAME_IMG_OUT);
    strcat(BufSystVisuImg,".pgm&");
    printf(" %s",BufSystVisuImg);
    system(BufSystVisuImg);

    /*retour sans probleme*/ 
    printf("\n C'est fini ... \n\n");
    return 0; 	 
}


void PreFFT_Translation(float** Matrix, int length, int width) {
    int x,y;
    for(x=0; x<length; x++)
        for(y=0; y<width; y++)
            if((x + y) % 2 == 1)
                Matrix[x][y] = -Matrix[x][y];
}
