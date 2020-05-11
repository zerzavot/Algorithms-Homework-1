#include<stdio.h>
#include <stdbool.h>
#define MAX 50
 
/*

QUESTION 2:
2. Given bit strings X = x1xm, Y = y1yn, and Z = z1zm+n, if Z can be obtained by interleaving the bits in
X and Y in a way that it maintains the left-to-right order of the bits in X and Y , then we say Z is an
interleaving of X and Y . For example if X = 101 and Y = 01 , then Z = 10011 is an interleaving of X
and Y , but Z = 11010 is not. Develop a (dynamic programming) algorithm that determines whether Z
is an interleaving of X and Y or not.

*/
int main()
{
    int X[]={1,0,1};
    int Y[]={0,1};
    int Z[]={1,1,0,1,0}; //NOT
    //int Z[]={1,0,0,1,1}; //Ok
    int i,j;
    
    
    
     
    int sizeX = sizeof(X)/sizeof(X[0]);
    int sizeY = sizeof(Y)/sizeof(Y[0]);
    int sizeZ = sizeof(Z)/sizeof(Z[0]);
     
    //printf("sizeX %d\n sizeY %d\n sizeZ %d\n",sizeX,sizeY,sizeZ);
     
    int D[sizeX][sizeY];
    
    printf("\nX is: ");
    for(i=0;i<sizeX;i++){
    	printf("%d ",X[i]);
	}
	printf("\nY is: ");
	for(i=0;i<sizeY;i++){
    	printf("%d ",Y[i]);
	}
	printf("\nZ is: ");
    for(i=0;i<sizeZ;i++){
    	printf("%d ",Z[i]);
	} 
	printf("\n\n");
     
    if(sizeX==0 &&sizeY==0 && sizeZ==0){
    	printf("true 1\n");
    	return 1;
	}
	if(sizeZ!=sizeX+sizeY){
		printf("false 1\n");
    	return 0;
	}
	////////////////////////////////////
	int flag1=0;
	for(i = 0; i < sizeY; i++)
    {
    	if(Y[i]==Z[i]){
    		flag1=1;
		} 
        else{
        	flag1=0; break;
		} 
    }
	if(sizeX==0 && sizeZ==sizeY && flag1==1){
		printf("true 2\n");
		return 1;
	}

	//////////////////////////////////
	int flag2=0;
	for(i = 0; i < sizeX; i++)
    {
    	if(X[i]==Z[i]){
    		flag2=1;
		} 
        else{
        	flag2=0; break;
		} 
    }
	if(sizeY==0 && sizeZ==sizeX && flag2==1){
		printf("true 3\n");
		return 1;
	}
	
     
    D[0][0]=1;
	 
     
     
    for(i=0;i<sizeX;i++){
    	for(j=0;j<sizeY;j++)
    	{
    	D[i][j]=(	(X[i]==Z[i+j]) && D[i-1][j]) ||( (Y[j]==Z[i+j]) && D[i][j-1]);
		}
	}
	/*
	for(i=0;i<sizeX;i++){
    	for(j=0;j<sizeY;j++)
    	{
    	printf("%d ",D[i][j]);
		}
		printf("\n");
	}*/
	
	if(D[sizeX-1][sizeY-1]==0){
		printf("Z is an interleaving of X and Y");	
	}
	else{
		printf("Z is not an interleaving of X and Y");
	}
	//Z is an interleaving of X and Y or not.
	//printf("INTER : %d",D[sizeX-1][sizeY-1]);
	return D[sizeX][sizeY];
}
