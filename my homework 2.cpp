#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

int i,loc1,loc2,temp,d,x=0,y=0,guess,t=1,basamak,j,temp2,z=1,result,sum;
int B[1000]={};
int C[10]={};

printf("-----------------------------------------------\n");
printf("--------       NUMBER GUESS GAME       --------\n");
printf("-----------------------------------------------\n");
//  random say� bulma k�sm� ;
int A[10]={0,1,2,3,4,5,6,7,8,9};
srand(time(NULL));
for(i=0;i<100;i++)
{
	loc1=rand()%10;
	loc2=rand()%10;
	temp=A[loc1];
	A[loc1]=A[loc2];
	A[loc2]=temp;
}
// random say�n�n 0 ile ba�lamas�n� engellemek i�in ;
if(A[0]==0)
{
	temp=A[0];
	A[0]=A[1];
	A[1]=temp;
}
printf("\n");
// kullan�c�dan basamak say�s�n� alma k�sm� ;
printf("Enter the number of digits for the game 4-10=");
scanf("%d",&d);

 printf("\n");
 //kullan�c�dan tahmin almay� tekrarlamak i�in k�s�m ;
 for(;z>0;){
// x== yeri do�ru mu -- y==i�inde var m�  ;
	x=0,y=0;
//kullan�c�dan tahmin al�nan k�s�m ;
printf("Enter a guess with different digits=");
scanf("%d",&guess);
B[t]=guess;
basamak= guess;
// tahmini basamaklar�na ay�rma k�sm� ;
for(i=1;i<=d;i++)
{
	C[i-1]=basamak%10; 
	basamak= basamak/10;
}
// y k�sm� ;
for(i=0;i<d;i++)
{
	for(j=0;j<d;j++)
	{
	if(C[i]==A[j])
	{
		y=y+1;
	}
	}
}
// x k�sm� ;
for(i=0;i<d;i++)
{

	if(C[d-i-1]==A[i])
	{
		x=x+1;
	}	
	
}
// yeri do�ru olan say�lar� randomun i�inde olan say�lardan ��karmak i�in olan k�s�m  ;
y=y-x;
sum=x-y;
	result=printf("+%d-%d\n",x,y);
	if(sum!=d)
 	{
 		t=t+1;
 	}
 	
	if(sum==d)
	{
	      z=0;
	      printf("Congratz you won the game\n");
    		 printf("Total number of tries=%d\n",t-1);
    
	}	
}
// tahminleri k���kten b�y��e s�ralama;
	for(i=0;i<t;i++)
{
	for(j=i+1;j<t+1;j++)
	{
		if(B[j]<B[i])
		{
			temp2=B[i];
	          B[i]=B[j];
		     B[j]=temp2;
		}
	}
}
printf("---------------------------------------------------------\n");
	printf("All guesses from smallest to largest:");
for(i=2;i<=t;i++)
{
	printf("%d,",B[i]);
}
printf("\n");
printf("---------------------------------------------------------\n");
	
return 0;	
}
