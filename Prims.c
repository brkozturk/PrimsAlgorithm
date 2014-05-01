#include<stdio.h>
#include<conio.h>
int i,j,k,a,b,u,v,n,gecici=1;
int min,eniyi=0,gidilen[10]={0},matris[10][10];
void main()
{
	printf("\n Dugum sayisini girin (Max 9) = ");
	scanf("%d",&n);
	printf("\n Dugumler arasi maliyetleri girin (Max 999) = \n");
	for(i=1;i<=(n-1);i++)
		for(j=(i+1);j<=n;j++)
		{
			printf("\n\t Dugum %d ile %d arasi:",i,j);
			scanf("%d",&matris[i][j]);
			if(matris[i][j]==0)
			{matris[i][j]=1000;}
			matris[j][i]=matris[i][j];
		}
	printf("\n Maliyet Matrisi:\n");
	for(i=1;i<=n;i++)
	{
		printf("\n\t");
		for(j=1;j<=n;j++)
		{	if(matris[i][j]==1000)
			{printf("%3d",0);}
			else{printf("%3d",matris[i][j]);}
		}
	}
	printf("\n\n Minimum Kenarlarin Maliyeti:\n");
	gidilen[1]=1;
	printf("\n");
	while(gecici < n)
	{
		for(i=1,min=1000;i<=n;i++)
			for(j=1;j<=n;j++)
				if(matris[i][j]< min)
					if(gidilen[i]!=0)
						{
							min=matris[i][j];
							a=u=i;
							b=v=j;
						}				
		if(gidilen[u]==0 || gidilen[v]==0)
		{
			printf("\n\t Kenar %d:(%d ve %d)  Maliyet:%d",gecici++,a,b,min);
			eniyi+=min;
			gidilen[b]=1;
		}
		matris[a][b]=matris[b][a]=1000;
	}
	printf("\n\n Toplam Minimum Maliyet = %d",eniyi);
	getch();
}
