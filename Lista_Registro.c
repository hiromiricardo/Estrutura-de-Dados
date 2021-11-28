#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<string.h>

struct dados_paciente{
	int matricula;
	char nome[60];
	float peso,altura,IMC;
};

struct dados_paciente Paciente[4];
	int mat,quant=-1,i,j,achou,pos;
	char name[60];
	float pes,alt,im;

void Inserir_Inicio(){
	if(quant==3)
	printf("Lista Cheia!\n");
	else{
		printf("Informe a matricula do paciente: ");
		scanf("%d",&mat);
		fflush(stdin);
		printf("Informe o nome do paciente: ");
		scanf("%[^\n]",name);
		printf("Informe o peso do paciente: ");
		scanf("%f",&pes);
		printf("Informe a altura do paciente: ");
		scanf("%f",&alt);
		im=pes/(alt*alt);
		for(i=quant+1;i>0;i--)
			Paciente[i]=Paciente[i-1];
		quant++;
		Paciente[0].matricula=mat;
		strcpy(Paciente[0].nome,name);
		Paciente[0].peso=pes;
		Paciente[0].altura=alt;
		Paciente[0].IMC=im;
		printf("\nO paciente sob:\nMatricula: %d\nNome: %s\nPeso: %0.2f, 
				Altura: %0.2f e IMC: %0.2f\nFoi inserido no inicio com sucesso!
				\n",mat,name,pes,alt,im);
	}
}

void Inserir_Final(){
	if(quant==3)
	printf("Lista Cheia!\n");
	else{
		printf("Informe a matricula do paciente: ");
		scanf("%d",&mat);
		fflush(stdin);
		printf("Informe o nome do paciente: ");
		scanf("%[^\n]",name);
		printf("Informe o peso do paciente: ");
		scanf("%f",&pes);
		printf("Informe a altura do paciente: ");
		scanf("%f",&alt);
		im=pes/(alt*alt);
		quant++;
		Paciente[quant].matricula=mat;
		strcpy(Paciente[quant].nome,name);
		Paciente[quant].peso=pes;
		Paciente[quant].altura=alt;
		Paciente[quant].IMC=im;
		printf("\nO paciente sob:\nMatricula: %d\nNome: %s\nPeso: %0.2f, 
				Altura: %0.2f e IMC: %0.2f\nFoi inserido no final com sucesso!
				\n",mat,name,pes,alt,im);
	}
	
}

void Inserir_Qualquer_Posicao(){
	if(quant==3)
	printf("Lista Cheia!\n");
	else{
		printf("Informe a matricula do paciente: ");
		scanf("%d",&mat);
		fflush(stdin);
		printf("Informe o nome do paciente: ");
		scanf("%[^\n]",name);
		printf("Informe o peso do paciente: ");
		scanf("%f",&pes);
		printf("Informe a altura do paciente: ");
		scanf("%f",&alt);
		im=pes/(alt*alt);
		printf("Informe a posicao (1..4) em que deseja inserir o elemento: ");
		scanf("%d",&pos);
		pos--;
		if(pos<0 || pos>3)
		printf("Posicao invalida!\n");
		else{
			for(i=quant+1;i>pos;i--)
				Paciente[i]=Paciente[i-1];
			quant++;
		Paciente[pos].matricula=mat;
		strcpy(Paciente[pos].nome,name);
		Paciente[pos].peso=pes;
		Paciente[pos].altura=alt;
		Paciente[pos].IMC=im;
		printf("\nO paciente sob:\nMatricula: %d\nNome: %s\nPeso: %0.2f, 
				Altura: %0.2f e IMC: %0.2f\nFoi inserido na posicao %d com 
				sucesso!\n",mat,name,pes,alt,im,pos+1);
		}
	}
}

void Remover_Elemento(){
	if(quant==-1)
	printf("Lista Vazia!\n");
	else{
		printf("Informe a matricula a ser removida: ");
		scanf("%d",&mat);
		achou=-1;
		for(i=0;i<=quant;i++)
			if(Paciente[i].matricula==mat)
				achou=i;
			if(achou!=-1)
				{
					for(i=achou;i<quant;i++)
						Paciente[i]=Paciente[i+1];
					quant--;
			printf("A matricula %d do paciente de:\nNome: %s\nPeso: %0.2f, 
					Altura: %0.2f e IMC: %0.2f\nFoi Removida da posicao %d da 
					lista!\n",mat,Paciente[achou].nome,Paciente[achou].peso, 
					Paciente[achou].altura,Paciente[achou].IMC,achou+1);
				}
				else printf("A matricula %d nao foi encontrada!\n",mat);
	}
}

void Esvaziar_Lista(){
	char rpp;
	if(quant==-1)
	printf("Lista Vazia!\n");
	else{
		printf("Tem certeza que deseja limpar a lista?\n");
		printf("S -Sim, N -Nao: ");
		scanf(" %c",&rpp);
		if(rpp=='s'){
			quant=-1;
			printf("\nLista limpada com sucesso!\n");
		}
		else printf("\nOperacao cancelada!\n");
	}
}

void Select_Sort(){
	if(quant==-1)
	printf("Lista Vazia!\n");
	else{
		int men,ind;
		
		for(i=0;i<3;i++){
			ind=i;
			men=Paciente[ind].matricula;
			
			for(j=i+1;j<4;j++){
				
				if(men>Paciente[j].matricula){
					ind=j;
					men=Paciente[ind].matricula;
				}
				
				if(men<Paciente[i].matricula){
					
					mat=Paciente[i].matricula;
					Paciente[i].matricula=Paciente[ind].matricula;
					Paciente[ind].matricula=mat;
					
					strcpy(name,Paciente[i].nome);
					strcpy(Paciente[i].nome,Paciente[ind].nome);
					strcpy(Paciente[ind].nome,name);
					
					pes=Paciente[i].peso;
					Paciente[i].peso=Paciente[ind].peso;
					Paciente[ind].peso=pes;
					
					alt=Paciente[i].altura;
					Paciente[i].altura=Paciente[ind].altura;
					Paciente[ind].altura=alt;
					
					im=Paciente[i].IMC;
					Paciente[i].IMC=Paciente[ind].IMC;
					Paciente[ind].IMC=im;
				}
			}			
		}
		printf("A ordenacao por Select Sort foi realizada com sucesso!\n");
	}
}

void Ordenar_Crescente(){
	if(quant==-1)
	printf("Lista Vazia!\n");
	else{
		for(i=0;i<quant;i++)
			for(j=0;j<quant;j++)
				if(Paciente[j].matricula>Paciente[j+1].matricula)
				{
					mat=Paciente[j].matricula;
					Paciente[j].matricula=Paciente[j+1].matricula;
					Paciente[j+1].matricula=mat;
					
					strcpy(name,Paciente[j].nome);
					strcpy(Paciente[j].nome,Paciente[j+1].nome);
					strcpy(Paciente[j+1].nome,name);
					
					pes=Paciente[j].peso;
					Paciente[j].peso=Paciente[j+1].peso;
					Paciente[j+1].peso=pes;
					
					alt=Paciente[j].altura;
					Paciente[j].altura=Paciente[j+1].altura;
					Paciente[j+1].altura=alt;
					
					im=Paciente[j].IMC;
					Paciente[j].IMC=Paciente[j+1].IMC;
					Paciente[j+1].IMC=im;
					
				}
		printf("A ordenacao por troca crescente foi realizada com sucesso!\n");
	}
}

void Ordenar_Decrescente(){
	if(quant==-1)
	printf("Lista Vazia!\n");
	else{
		for(i=0;i<quant;i++)
			for(j=0;j<quant;j++)
				if(Paciente[j].matricula<Paciente[j+1].matricula)
				{
					mat=Paciente[j].matricula;
					Paciente[j].matricula=Paciente[j+1].matricula;
					Paciente[j+1].matricula=mat;
					
					strcpy(name,Paciente[j].nome);
					strcpy(Paciente[j].nome,Paciente[j+1].nome);
					strcpy(Paciente[j+1].nome,name);
					
					pes=Paciente[j].peso;
					Paciente[j].peso=Paciente[j+1].peso;
					Paciente[j+1].peso=pes;
					
					alt=Paciente[j].altura;
					Paciente[j].altura=Paciente[j+1].altura;
					Paciente[j+1].altura=alt;
					
					im=Paciente[j].IMC;
					Paciente[j].IMC=Paciente[j+1].IMC;
					Paciente[j+1].IMC=im;
				}
		printf("A ordenacao por ordem decrescente foi realizada com sucesso!\n");
	}
}

void Busca_Sequencial(){
	if(quant==-1)
	printf("Lista Vazia!\n");
	else{
		printf("Informe a matricula a ser pesquisada: ");
		scanf("%d",&mat);
		i=0;
		achou=0;		//flag
		while (i<=quant && achou==0)
			if(Paciente[i].matricula==mat)
			{
				achou=1;
				pos=i;
			}
			else i++;
		if(achou==0)
		printf("A matricula %d nao foi encontrada!\n",mat);
		else
			printf("A matricula %d do paciente de:\nNome: %s\nPeso: %0.2f, 
					Altura: %0.2f e IMC: %0.2f\nFoi encontrado na posicao %d da 
					lista!\n",mat,Paciente[pos].nome,Paciente[pos].peso,
					Paciente[pos].altura,Paciente[pos].IMC,pos+1);
	}
}

void Busca_Binaria(){
	int start,end,aux;
	if(quant==-1)
	printf("Lista Vazia!\n");
	else{
				Ordenar_Crescente();	//Chamada funcao Ordenar_Crescente
		achou=0;
		start=0;
		end=quant;
		pos=(start+end)/2;
		printf("\nInforme a matricula a ser pesquisada: ");
		scanf("%d",&mat);
		while(achou==0 && start<=end)
			if(mat==Paciente[pos].matricula)
				achou=1;
				else{
					if(mat<Paciente[pos].matricula)
					end=pos-1;
					else start=pos+1;
					pos=(start+end)/2;
				}
			if(achou==0)
			printf("\nA matricula %d nao foi encontrada!\n",mat);
			else printf("A matricula %d do paciente de:\nNome: %s\nPeso: %0.2f, 
						Altura: %0.2f e IMC: %0.2f\nFoi encontrado na posicao %d 
						da lista!\n",mat,Paciente[pos].nome,Paciente[pos].peso,
						Paciente[pos].altura,Paciente[pos].IMC,pos+1);
	}
}

void Exibir_Primeiro(){
	if(quant==-1)
	printf("Lista Vazia!\n");
	else
		printf("Paciente sob:\nMatricula %d\nNome: %s\nPeso: %0.2f, Altura: %0.2f 
				e IMC: %0.2f\n",Paciente[0].matricula,Paciente[0].nome,
				Paciente[0].peso,Paciente[0].altura,Paciente[0].IMC);
}

void Exibir_Ultimo(){
	
	if(quant==-1)
	printf("Lista Vazia!\n");
	else
		printf("Paciente sob:\nMatricula %d\nNome: %s\nPeso: %0.2f, Altura: %0.2f 
				e IMC: %0.2f\n",Paciente[quant].matricula,Paciente[quant].nome,
				Paciente[quant].peso,Paciente[quant].altura,Paciente[quant].IMC);
}

void Exibir_Lista(){
	if(quant==-1)
	printf("Lista Vazia!\n");
	else {
		for(i=0;i<=quant;i++){
			printf("Paciente sob:\nMatricula %d\nNome: %s\nPeso: %0.2f, Altura: %0.2f 
					e IMC: %0.2f\n",Paciente[i].matricula,Paciente[i].nome,
					Paciente[i].peso,Paciente[i].altura,Paciente[i].IMC);
			printf("\n");
		}
		printf("\n");
	}
}

void main(){
			setlocale(LC_ALL,"Portuguese,brazil");
	int code;
	char res;
	do{
		printf(" 1- Inserir matricula no inicio;\n");
		printf(" 2- Inserir matricula no final;\n");
		printf(" 3- Inserir matricula em qualquer posicao;\n");
		printf(" 4- Remover matricula;\n");
		printf(" 5- Esvaziar lista;\n");
		printf(" 6- Ordenar as matriculas em ordem crescente;\n");
		printf(" 7- Ordenar as matriculas em ordem decrescente;\n");
		printf(" 8- Buscar matricula na lista;\n");
		printf(" 9- Busca binaria (a lista sera organizada em ordem crescente!);\n");
		printf("10- Buscar matricula na lista por Select Sort;\n");
		printf("11- Exibir a primeira matricula da lista;\n");
		printf("12- Exibir a ultima matricula da lista;\n");
		printf("13- Exibir lista;\n");
		printf("14- Sair.\n");
		printf("Escolha uma operacao: ");
		scanf("%d",&code);
		printf("\n");
		switch(code){
			case 1: Inserir_Inicio();
			break;
			case 2: Inserir_Final();
			break;
			case 3: Inserir_Qualquer_Posicao();
			break;
			case 4: Remover_Elemento();
			break;
			case 5: Esvaziar_Lista();
			break;
			case 6: Ordenar_Crescente();
			break;
			case 7: Ordenar_Decrescente();
			break;
			case 8: Busca_Sequencial();
			break;
			case 9: Busca_Binaria();
			break;
			case 10: Select_Sort();
			break;
			case 11: Exibir_Primeiro();
			break;
			case 12: Exibir_Ultimo();
			break;
			case 13: Exibir_Lista();
			break;
			case 14: exit(0);
			break;
			default: printf("\nOperacao invalida!\n");
		}
		printf("\nDeseja continuar? ('S' - Sim, 'N' - Nao): ");
		scanf(" %c",&res);
		system("cls");
	}
	while (res!= 'n');
}
