#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
#include<string.h>

typedef struct {
		int valorJogo;
		int valorCarta;
		int naipeCarta;
		
	}carta;


void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void telaInicial(){
	printf("                                                      `:                                                         \n"); 
	printf("                                                     -dN/                                                        \n");
	printf("                                                   .sNMMMh:                                                      \n");
	printf("                                                 :yNMMMMMMNd/`                                                   \n");
	printf("                                               -hNMMMMMMMMMMMm+                                                  \n");
	printf("                                              -NMMMMMMMMMMMMMMMo                                                 \n");
	printf("                                              -NMMMMMMhhNMMMMMMo                                                 \n");
	printf("                                               -ohhhs:/y-oyhhs:                                                  \n");
	printf("                                                    `/NMo.                                                       \n");
	printf("                                                .:/oydmmmhs+:-                                                   \n");
	printf("-:++/:::::-`   `-oh.                      .+y+               .-/+/-- `                  `-sh.           \n");
	printf(" `mMo...-+md:  `.dM-                      .oMo                `yMd`                     `.dM.           \n");
	printf("  dM/     oMm    yM-    `...`      `..`    /Mo  `````          oMy     `..`       `..`    hM.  ````     \n");
	printf("  dM+````-dNs    yM-  `ss::sh:   .o+:/hy-  /Mo  -yo-.          oMy   :h+-/hy`   :o/:+do`  hM.  +y+-`    \n");
	printf("  dMy//+smNs.    yM-  :m: `-Mh  -N+   :h+  /Mo.+o-             oMy   sd` `sM/  oN.   sh.  hM--o+.       \n"); 
	printf("  dM/    `oMN/   yM-   ./+//Md  yM-        /Mydm.              oMy   `-//:yM/ `Nm         hMoNs`        \n");
	printf("  dM/     `NMy   yM-  +N/  .Md  oMy`    /  /Mo-dN+`         `  oMs  `hm.  oM/  mM:    `:  hM.+Nd-       \n");
	printf("``mM+```.:hNh.  `hM:  hMo.-+Mm--`hNh+/+s: `+Ms``oMh-`      :ds`sm.  .Nm:.:yMs:`:mNs//os` `dM- .hNo``    \n");
	printf("-:+++/////:.   `-++/- `+o+- +o-   :oss/`  -/++-`.+++:`     `os//`    -oo/..o+.  `/oso:  `:++/. :++/-    \n");
	
	
	
	printf("\n");
	printf("\n");
	printf("\n");
	
	printf("                                            ______________________                                               \n");
	printf("                                            | PRESSIONE QUALQUER |                                               \n");
	printf("                                            | TECLA PARA JOGAR   |                                               \n");
	printf("                                            |____________________|                                               \n");
	
	system("pause");
}
void embaralhar(carta baralho[], carta baralhoDoJogo[]){

	int vetorBinario[52]={0};
	int recebePosicao;
	
	srand(time(NULL));
				 	
	for(int i=0; i<52;i++)
	{
		recebePosicao=rand()%52;
		while(vetorBinario[recebePosicao]==1)
		{
			recebePosicao=rand()%52;
		}
		
		vetorBinario[recebePosicao]=1;
		baralhoDoJogo[i]=baralho[recebePosicao];
    }
    
    
    printf("\n\n\n");
    for(int i=0; i<52;i++){
    
    	
    			if(baralho[i].valorCarta == 1)
				{
					baralhoDoJogo[i].valorCarta =65;
					baralhoDoJogo[i].valorJogo =1;
				}
				if(baralhoDoJogo[i].valorCarta == 11)
				{
					baralhoDoJogo[i].valorCarta =74;
					baralhoDoJogo[i].valorJogo = 10;
				}
				if(baralhoDoJogo[i].valorCarta == 12)
				{
					baralhoDoJogo[i].valorCarta =81;
					baralhoDoJogo[i].valorJogo = 10;
				}
				if(baralhoDoJogo[i].valorCarta == 13)
				{
					baralhoDoJogo[i].valorCarta =75;
					baralhoDoJogo[i].valorJogo = 10;
				}
				

	}
    	
}

void criarBaralho(carta baralho[])
{
	int i=0;
		
		for(int naCarta =3;naCarta <=6;naCarta++)
		{
					
			for(int nuCarta=1; nuCarta<14; nuCarta++, i++)
			{
				baralho[i].naipeCarta = naCarta;
				baralho[i].valorCarta = nuCarta;
				baralho[i].valorJogo = nuCarta;	
				if(baralho[i].valorCarta == 1)
				{
					baralho[i].valorCarta =65;
					baralho[i].valorJogo =1;
				}
				if(baralho[i].valorCarta == 11)
				{
					baralho[i].valorCarta =74;
					baralho[i].valorJogo = 10;
				}
				if(baralho[i].valorCarta == 12)
				{
					baralho[i].valorCarta =81;
					baralho[i].valorJogo = 10;
				}
				if(baralho[i].valorCarta == 13)
				{
					baralho[i].valorCarta =75;
					baralho[i].valorJogo = 10;
				}		
			}
		
		}
}

	
main()
{
	telaInicial();
	system("cls");
	
	carta baralho[52]={};
	carta baralhoDoJogo[52];
	carta cartasJogador[13][12]={0};
		
	criarBaralho(baralho);
	embaralhar(baralho,baralhoDoJogo);
		
	system("cls");
	int  vetorEmpate[14],vetorJogador[14]={0}, pontos=0, posicaoVetorCartas, maiorPonto = 0, vencedor =0, pontosMaquina=0,jogadores=0,posicaoVetor=0,h=0,y=0,indiceNomeJogador=0;
		
	
	printf("\nDigite a quantidade de jogadores:");
	scanf("%d",&jogadores);
	fflush(stdin);
	
	
	for(int i=0; i<jogadores;i++){
		vetorJogador[i]=1;
 	}
 	char nomeJogador[12][30]={'0'};
 	
	for(int i=0;i<jogadores;i++){
			printf("Digite o nome do Jogador %d:",i+1);
			scanf("%s",&nomeJogador[i][0]);
	}
			
	fflush(stdin);
	//insere o valor 1 no vetor de jogador apartir da quantidade de jogadores que vao jogar
	for(int i=0; i<jogadores;i++){
		vetorJogador[i]=1;
 	}

	
	system("pause");

	
	
	//vai rodar ate que no indice x do vetor de jogador seje igual a  1
	/*         	 |
				 |
				 |
				\|/                  */
	while(vetorJogador[posicaoVetor]==1)
	{
		system("Cls");
		//for(int i=0; i< 12 && nomeJogador[indiceNomeJogador][0]!= '\0';i++){		
		for(int j=0;j<30;j++)
		{
			printf ("%c ", nomeJogador[indiceNomeJogador][j]);		
		}
		nomeJogador[13][0] = {'C'};
		nomeJogador[13][1] = {'P'};
		nomeJogador[13][2] = {'U'};

		indiceNomeJogador++;
		printf("\n");
		
	//	}
		//printf("\nJogador %d\n",posicaoVetor);
		char querCartas;
		querCartas='S';
		do{	
		
		
			
						
				
					printf("Voce quer carta?   [S/N]");
					scanf("%c",&querCartas);
					fflush(stdin);
					if(querCartas=='s'||querCartas=='S'){
					
			
							posicaoVetorCartas=rand()%51;
							printf("valor random:%d\n",posicaoVetorCartas);
							fflush(stdin);
							if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 65)
							{
								
								pontos+=1;
							}
							else if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 74)
							{
								
								pontos+=10;
							}
							else if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 75)
							{
								pontos+=10;
								
							}
							else if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 81)
							{
								
								pontos+=10;
							}
							else if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 13)
							{
							
								pontos+=10;
							}
							else
							{
								pontos=pontos+baralhoDoJogo[posicaoVetorCartas].valorJogo;
							}
							if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 65||baralhoDoJogo[posicaoVetorCartas].valorCarta == 74 ||baralhoDoJogo[posicaoVetorCartas].valorCarta == 81 ||baralhoDoJogo[posicaoVetorCartas].valorCarta == 75){
							
							int j=0;
						//	gotoxy(17, i++);
							printf( "  _____________");	
							printf("\n |             |");	
							printf("\n |%2c           |",baralhoDoJogo[posicaoVetorCartas].valorCarta);
							printf("\n | %c           |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
							printf("\n |             |");
							printf("\n |             |");
							printf("\n |     %c       |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
							printf("\n |             |");
							printf("\n |          %c  |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
							printf("\n |         %2c  |",baralhoDoJogo[posicaoVetorCartas].valorCarta);
							printf("\n |_____________|");
							printf("\n\n");
						
							printf("Quantidade de Pontos=%d\n",pontos);
								
						}
						else {		
							printf( "  _____________");	
							printf("\n |             |");	
							printf("\n |%2d           |",baralhoDoJogo[posicaoVetorCartas].valorCarta);
							printf("\n | %c           |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
							printf("\n |             |");
							printf("\n |             |");
							printf("\n |     %c       |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
							printf("\n |             |");
							printf("\n |          %c  |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
							printf("\n |         %2d  |",baralhoDoJogo[posicaoVetorCartas].valorCarta);
							printf("\n |_____________|");
							printf("\n\n");
						}
							
							
							printf("Quantidade de Pontos=%d\n",pontos);
							
							cartasJogador[posicaoVetor][y]=baralhoDoJogo[posicaoVetorCartas];
							fflush(stdin);
								
					
						printf("\n");
						printf("\n");
						
							y++;
							fflush(stdin);
							
							 if(pontos==21)
							{
									
									system("pause");
									vetorJogador[posicaoVetor] = pontos;
									y=0;
									
									
							}else if(pontos>21)
							{
								printf("\nVOCE PERDEU\n");
								system("pause");
								querCartas='n';
								vetorJogador[posicaoVetor] = pontos;
								
							}
							else{
								vetorJogador[posicaoVetor] = pontos;
							}
											
						
					}
				else{
					goto proxmioJogador;
				}
					
			
		}while(pontos<21);
	
		
	proxmioJogador:
	y=0;
	pontos=0;		
	posicaoVetor++;	
	}
	
	
		posicaoVetor = 0;
	while(vetorJogador[posicaoVetor]!= 0)
	{
	
		if(vetorJogador[posicaoVetor] > maiorPonto && vetorJogador[posicaoVetor]<21)
		{
			maiorPonto = vetorJogador[posicaoVetor];
		}
		
	printf("o maior ponto foi: %d\n",maiorPonto);
	printf("A pontuacao do jogador %d e : %d\n\n",posicaoVetor+1,vetorJogador[posicaoVetor]);
	posicaoVetor++;
	
	}
	
	
	while(pontosMaquina<maiorPonto && pontosMaquina<21)
	{
		posicaoVetorCartas=rand()%51;
				
					fflush(stdin);
					if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 65)
					{
						
						pontosMaquina+=1;
					}
					else if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 74)
					{
						
						pontosMaquina+=10;
					}
					else if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 75)
					{
						pontosMaquina+=10;
						
					}
					else if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 81)
					{
						
						pontosMaquina+=10;
					}
					else if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 13)
					{
					
						pontosMaquina+=10;
					}
					else
					{
						pontosMaquina=pontosMaquina+baralhoDoJogo[posicaoVetorCartas].valorJogo;
					}
					if(baralhoDoJogo[posicaoVetorCartas].valorCarta == 65||baralhoDoJogo[posicaoVetorCartas].valorCarta == 74 ||baralhoDoJogo[posicaoVetorCartas].valorCarta == 81 ||baralhoDoJogo[posicaoVetorCartas].valorCarta == 75)
					
					{
					
					int j=0;
				//	gotoxy(17, i++);
					printf( "  _____________");	
					printf("\n |             |");	
					printf("\n |%2c           |",baralhoDoJogo[posicaoVetorCartas].valorCarta);
					printf("\n | %c           |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
					printf("\n |             |");
					printf("\n |             |");
					printf("\n |     %c       |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
					printf("\n |             |");
					printf("\n |          %c  |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
					printf("\n |         %2c  |",baralhoDoJogo[posicaoVetorCartas].valorCarta);
					printf("\n |_____________|");
					printf("\n\n");
					
					printf("Quantidade de Pontos DA MAQUINA=%d\n",pontosMaquina);
					
					}
					else {		
						printf( "  _____________");	
						printf("\n |             |");	
						printf("\n |%2d           |",baralhoDoJogo[posicaoVetorCartas].valorCarta);
						printf("\n | %c           |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
						printf("\n |             |");
						printf("\n |             |");
						printf("\n |     %c       |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
						printf("\n |             |");
						printf("\n |          %c  |",baralhoDoJogo[posicaoVetorCartas].naipeCarta);
						printf("\n |         %2d  |",baralhoDoJogo[posicaoVetorCartas].valorCarta);
						printf("\n |_____________|");
						printf("\n\n");
					}
						printf("Quantidade de Pontos DA MAQUINA=%d\n",pontosMaquina);
						
						
						if(pontos<21) 
						{
							
						}
						else if(pontos==21)
						{
								system("pause");
								vetorJogador[14] = pontosMaquina;
						}else
						{
							vetorJogador[14] = pontosMaquina;
						}
		
	}
	
		posicaoVetor=0;
	while(vetorJogador[posicaoVetor]!=0 && vetorJogador[14]!=0)
	{
		if(vetorJogador[posicaoVetor] == maiorPonto)
		{
			if(vetorJogador[14]>maiorPonto)
			{
				maiorPonto = vetorJogador[14];
				vencedor = 100;
			}else
			{
				vencedor = posicaoVetor+1;
			}	
		}
		posicaoVetor++;	
	}
	if(pontosMaquina>pontos && pontosMaquina<=21)
	{
		vencedor =100;
		printf("A maquina e a vencedora, sua pontuacao foi de: %d !!!!",pontosMaquina);
	}else
	{
			if(vencedor==100)
			{
				//printf("A maquina e a vencedora, sua pontuacao foi de: %d !!!!",pontosMaquina);
				
			}else
			{
				printf("O Jogador %d e o vencedor, sua pontuacao foi de: %d !!!!",vencedor,pontos) ;
			}
	}

	//system("cls");
	for(int i=0;i<13;i++)
	{
		
		if(vetorJogador[i]==21)
		{
			printf("O jogador ");
				int j=0;	
				while(nomeJogador[i][j]!='\0')
				{
				
					printf ("%c", nomeJogador[i][j]);
					j++;
						
				}
			printf(" venceu!!!!!!");				
			printf("\n");
			printf("Com as castas:\n");
		
		
		int	d=i,h=0;
			while(cartasJogador[d][h].naipeCarta!=0 && cartasJogador[d][h].valorCarta!=0 && cartasJogador[d][h].valorJogo!=0){
					
						if(cartasJogador[d][h].valorCarta == 65||cartasJogador[d][h].valorCarta == 74 ||cartasJogador[d][h].valorCarta == 81 ||cartasJogador[d][h].valorCarta == 75)
						{
													
							printf( "  _____________");	
							printf("\n |             |");	
							printf("\n |%2c           |",cartasJogador[d][h].valorCarta);
							printf("\n | %c           |",cartasJogador[d][h].naipeCarta);
							printf("\n |             |");
							printf("\n |             |");
							printf("\n |     %c       |",cartasJogador[d][h].naipeCarta);
							printf("\n |             |");
							printf("\n |          %c  |",cartasJogador[d][h].naipeCarta);
							printf("\n |         %2c  |",cartasJogador[d][h].valorCarta);
							printf("\n |_____________|");
							printf("\n\n");								
						}
						else
						{		
							printf( "  _____________");	
							printf("\n |             |");	
							printf("\n |%2d           |",cartasJogador[d][h].valorCarta);
							printf("\n | %c           |",cartasJogador[d][h].naipeCarta);
							printf("\n |             |");
							printf("\n |             |");
							printf("\n |     %c       |",cartasJogador[d][h].naipeCarta);
							printf("\n |             |");
							printf("\n |          %c  |",cartasJogador[d][h].naipeCarta);
							printf("\n |         %2d  |",cartasJogador[d][h].valorCarta);
							printf("\n |_____________|");
							printf("\n\n");
						}
				j++;
			
				h++;
			}
				d++;
		}else{
			if(vetorJogador[i]<21 && vetorJogador[i]!=1 && vetorJogador!=0 ){
				//printf("que merda.......\n");
			}
		}
		
	}

	


}
