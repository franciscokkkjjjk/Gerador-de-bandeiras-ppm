#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int i, j;

void plot (int col, int lin, int red, int green, int blue, int **mat)
{			
  
    mat[col * 3][lin] = red;
    mat[col * 3 + 1][lin] = green;
    mat[col * 3 + 2][lin] = blue;
 
    return;

}

void letraMiniscula(char *palavra) {
    for(i = 0; i < strlen(palavra); ++i)
        palavra[i] = tolower(palavra[i]);
}

void incializaMatriz(int col, int lin, int **matriz){
    for(i = 0; i < col; ++i)
        for(j = 0; j < lin; ++j)
            matriz[i][j] = 0;
}

void geraNigeria(int lin, int **matriz) {
        for(i = 0; i < lin; ++i) 
            for(j = 0; j < lin; ++j) 
                if(j < lin/3 || j > (lin*2)/3)
                    plot (j, i, 0, 255, 0, matriz);
                else 
                    plot(j, i, 255, 255, 255, matriz); 
}

void gerarLatvia(int lin, int **matriz) {
    for(i = 0; i < lin; ++i)
        for(j = 0; j < lin; ++j)
            if(i < lin/3.3 || i > (lin*2)/3.3)
                plot(j, i, 255, 0, 0, matriz);
            else 
                plot(j, i, 255, 255, 255, matriz);
}

void gerarFilandia(int lin, int **matriz) {
    for(i = 0; i < lin; ++i)
        for(j = 0; j < lin; ++j)
            if(i < lin/3.3 || i > 40/3.3)
                if(j < (lin*3)/6 && j > lin/6)
                    plot(j, i, 0, 0, 255, matriz);
            else 
                plot(j, i, 255, 255, 255, matriz);
            else 
                plot(j, i, 0, 0, 255, matriz);
}

void gerarSuecia(int lin, int **matriz) {
    for(i = 0; i < lin; ++i)
        for(j = 0; j < lin; ++j)
            if(i < lin/3.3 || i > 40/3.3)
                if(j < (lin*3)/6 && j > lin/6)
                    plot(j, i, 255, 255, 0, matriz);
            else 
                plot(j, i, 0, 0, 255, matriz);
            else 
                plot(j, i, 255, 255, 0, matriz);
}

void gerarGabao(int lin, int **matriz) {
    for(i = 0; i < lin; ++i)
        for(j = 0; j < lin; ++j)
            if(i < lin/3.3)
                plot(j, i, 0, 255, 0, matriz);
            else if(i > (lin*2)/3.3)
                plot(j,i, 0,0,255, matriz);
            else
                plot(j, i, 255, 255,0, matriz);
}
void gerarGambia(int lin,int **matriz) {
    for(i = 0; i < lin; ++i) 
        for(j = 0; j < lin; ++j) 
            if(i < lin/3.3)
                plot(j, i, 255, 0, 0, matriz);
            else if(i > (lin*2)/3.33)
                plot(j,i, 0,255,0, matriz);
            else
                plot(j,i, 255, 255, 255, matriz);
    for(i = 0; i < lin; ++i) 
        for(j = 0; j < lin; ++j) 
            if(i > lin/2.80 && i < (lin*2)/3.5)
                plot(j,i, 0, 0, 255, matriz);
}
void gerarMauricio(int lin, int **matriz) {
    for(i = 0; i < lin; ++i)    
        for(j = 0; j < lin; ++j)
            if(i < lin/4)
                plot(j,i, 255, 0, 0, matriz);
            else if(i < lin*2/4)
                plot(j,i, 0, 0, 255, matriz);
           else if(i < lin*3/4)
                plot(j,i, 255, 255, 0, matriz);
            else
                plot(j,i, 0, 255, 0, matriz);
}

void gerarAlemanha(int lin, int **matriz) {
    for(i = 0; i < lin; ++i)    
        for(j = 0; j < lin; ++j)
            if(i < lin/3)
                plot(j,i, 0, 0, 0, matriz);
            else if(i < lin*2/3)
                plot(j,i, 255, 0, 0, matriz);
            else 
                plot(j,i, 255, 255, 0, matriz);
}
void gerarEua(int linh, int **matriz) {
    int k;
    for(i = 0, k = 1; i < linh; ++i) { 
        for(j = 0; j < linh; ++j) {
            if(j < linh/2 && i < linh/3.33) {
                plot(j,i, 0, 0, 255, matriz);
                continue;
            }
            if((j >= linh/2 || i >= linh/3.33) && i >= (linh*(k-1))/13) {
                if((k % 2) == 0)
                    plot(j,i,255,255,255, matriz);
                else
                    plot(j,i,255,0,0, matriz);
            }
        }
        if(i >= (linh*k)/13) k++;
    }
}
void imprimirMatriz(int coluna, int linha, char matriz[11][10]) {
    for(i = 0; i < linha; ++i) {
        for(j = 0; j < coluna; ++j)
            printf("%c", matriz[i][j]);
        printf("\n");
    }
}

void estrelinha(int col, int lin, int **matriz) {
    float x;
    x = 0;
    for(int l = lin; l < lin+10; l++)  {
        plot(col+x,l, 255,255,255, matriz);
        plot(col-x,l, 255,255,255, matriz);
        x = x+0.4;
    }
    for(int l = lin; l < lin+10; l++)  {
        plot(col-x,l, 255,255,255, matriz);
        plot(col+x,l, 255,255,255, matriz);
        x = x+0.4;
    }
}

void bloco(int col, int lin, int larg, int alt, int red, int green, int blue, int **mat){
    for (int i =col; i < (col+larg); i++)
        for (int j = lin; j <(lin+alt); j++)
            plot(i,j,red,green,blue,mat);
        return;
}

int main(void)
{
    int **matriz, comparacao = 1, opcaoSelecionada;
    char nome[30], nomeArquivo[15], sair, comandoTerminal[40];
    FILE *p;
    long int  tamanhoColuna, tamanhoLinha;
    char bandeiras[11][10] = {
        {"nigeria"},
        {"latvia"},
        {"finlandia"},
        {"suecia"},
        {"gabao"},
        {"gambia"},
        {"mauricio"},
        {"alemanha"},
        {"eua"}
    };
    
    do {
         printf("Digite o tamanho da imagem (ela eh sempre um quadrado): ");
        scanf("%li", &tamanhoLinha);

        tamanhoColuna = tamanhoLinha*3;

        matriz = (int**)malloc(sizeof(int*)*tamanhoColuna);
        for(i = 0; i < tamanhoColuna; ++i)
            matriz[i] = (int*)malloc(sizeof(int)*tamanhoLinha);

        strcpy(comandoTerminal, "");
        printf("Escolha uma bandeira para ser gerada:\n");
        imprimirMatriz(10, 11, bandeiras);
        printf("Qual bandeira? ");
        scanf("%s", nome);
        
        letraMiniscula(nome);

        for(i = 0; i < 9; ++i) {
            comparacao = 0;
            if(strcmp(bandeiras[i],  nome) == 0) {
                comparacao = 1;
                break;           
            }
        }
        if(!comparacao) {
            puts("Bandeira nao encontrada.\n");
            exit(0);
        }

        opcaoSelecionada = i;
        
        strcat(nome, ".ppm");
        
        if((p = fopen(nome, "w")) == NULL) {
            printf("Nao deu bom\n");
            exit(0);
        }
    
        incializaMatriz(tamanhoColuna, tamanhoLinha, matriz);

        switch(opcaoSelecionada) {
            case 0:
                geraNigeria(tamanhoLinha, matriz);
                break;
            case 1:
                gerarLatvia(tamanhoLinha, matriz);
                break;
            case 2:
                gerarFilandia(tamanhoLinha, matriz);
                break;
            case 3:
                gerarSuecia(tamanhoLinha, matriz);
                break;
            case 4:
                gerarGabao(tamanhoLinha, matriz);
                break;
            case 5:
                gerarGambia(tamanhoLinha, matriz);
                break;
            case 6: 
                gerarMauricio(tamanhoLinha, matriz);
                break;
            case 7: 
                gerarAlemanha(tamanhoLinha, matriz);
                break;
            case 8: 
                gerarEua(tamanhoLinha, matriz);
                estrelinha(20, 20, matriz);
                break;
        }
        
        fprintf (p, "P3\n%ld %ld\n255\n", tamanhoLinha, tamanhoLinha);
        
        for (j = 0; j < tamanhoLinha; j++)
            for (i = 0; i < tamanhoColuna; i++)
                fprintf (p,"%d ", matriz[i][j]);
        fclose(p);
        #if _win32
            strcat(comandoTerminal, "start ");
            strcat(comandoTerminal, nome);
            system(comandoTerminal);
        #else 
            strcat(comandoTerminal, "xdg-open ./");
            strcat(comandoTerminal, nome);
            system(comandoTerminal);
        #endif
        printf("Deseja sair? ");
        scanf("%*c%c", &sair);
    } while(sair != 'S' && sair != 's');
    
    return 0;
}