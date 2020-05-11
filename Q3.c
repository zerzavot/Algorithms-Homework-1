    #include <stdio.h>
    #include <stdlib.h>
     /**
	 QUESTION 3_COM368
	 
	 Given an array of size n that has the following specifications:
- each element in the array contains either a policeman or a thief
- each policeman can catch only one thief
- policeman cannot catch a thief who is more than K units away from the policeman
Devise a greedy algorithm that finds the maximum number of thieves that can be caught. Also, prove
that your algorithm satisfies the greedy-choice property. For the array [ P, T, T, P, T ] and k = 1, your
algorithm should output 2 (first policeman catches first thief and second one catches either second or third
thief) For the array [ T, T, P, P, T, P ] and k = 2 your algorithm should output 3.
	 
	 */
    int main()
    {
    	
	
    int i,j,p,q,cnt=0   ;
    
    int poInt,thiInt,absValue;
    char cha;
    
    int o;
    char who[]={'T','T' ,'P' ,'P' ,'T' ,'P' };  int k=2;
    int count = sizeof(who) / sizeof(who[0]); 
    int polis[count],thief[count];
    
	for( o=0;o<count;o++){
		printf("%c ",who[o]);
	}
    //__________________________________________
    //Polislerle hýrsýzlarýn arraydeki yerini tespit
    //int polis[count] ve thief[count] isimli iki array yerleri tutar
    
    p=0; q=0;
		for(j=0;j<count;j++){
	
			if(who[j]=='P')
			{
				polis[p]=j+1;
				p++;
			}
			else{ //THIEF
				thief[q]=j+1; //arraydeki yeri tam versin
				q++; //minik arrayleri eleman geldikçe artýr
			}
		}
		
	//__________________________________________	
	/*
	Eger thief arrayindeki yerden Polis arrayindeki yeri
	çýkartýrsak elimizde k degerinden kücük bir sayý veya esit gelmeli
	eger gelirse polis hýrsýzý yakaladý demektir.
	
	*/	
		p=0; q=0;
	//abs(-1)=1
	while(polis[p]!=0 && thief[q]!=0){
		//printf(" geldi while ");
		poInt=polis[p];
		thiInt=thief[q];
		absValue=abs(poInt-thiInt);
		//printf(" %d ",absValue);
		//printf(" %d ",polis[p]);
		if(absValue<= k){
			//printf(" geldi abs ");
			cnt++;
			p++;
			q++;
		}
		else{
			if(polis[p]>thief[q])
				q++;
			else
				p++;
		}
		
	}
	//__________________________________________	
	
   
   printf("\nHow many thieves can be caught? %d\n",cnt) ;
    
  
    
     return 0;
    }
