/* 
*    QUESTION 1:
* Given a set of M positive integers A = a1, . . . , aM, 
* develop an dynamic programming that finds a partition
* A1, A2 such that | S1 - S2 | is minimized, 
* where Si is the sum of elements in Ai
*/
#include<stdio.h>
#include <stdbool.h>
#define INT_MAX 50
#define MAX_ARRAY 100


int main() 
{ 
	int i,j,k,q,r,t,sum=0;
	int fark = INT_MAX; 
    
    
    int arr[] = {1,5,7}; 
    int n = sizeof(arr)/sizeof(arr[0]); //KAc elamanlý
   
    /*
    printf("Array kac elemanli olacak?\n");
    scanf("%d",&number);
    for(ar=0;ar<number;ar++){
    	scanf("%d",arr[ar]) ;
    	
	}*/
    

    for (i = 0; i < n; i++) 
        sum += arr[i]; 
  
    bool dp[n+1][sum+1]; 
  
    
    for (j = 0; j <= n; j++) 
        dp[j][0] = true; 
  
    
    for ( k = 1; k <= sum; k++) 
        dp[0][i] = false; 
  
   
    for ( r=1; r<=n; r++) 
    { 
        for ( t=1; t<=sum; t++) 
        { 
           
            dp[r][t] = dp[r-1][r]; 
  
            
            if (arr[r-1] <= j) 
                dp[r][t] |= dp[r-1][t-arr[r-1]]; 
        } 
    } 

      
    for ( q=sum/2; q>=0; q--) 
    { 
         
        if (dp[n][q] == true) 
        { 
            fark = sum-2*q; 
            break; 
        } 
    } 
	
    printf("en az fark: %d",fark);
    
    return 0; 
} 

