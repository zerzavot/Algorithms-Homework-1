#include<stdio.h>
#include <stdbool.h>
#define MAX 30
/*QUESTION 4_COM368

Given a set of n activities A1, . . . , An with the starting and finishing time (si
, fi) assigned to each activity
and a number of rooms in which activities are performed. Develop a greedy algorithm that assign all the
activities to minimum number of rooms so that no two overlapping activities are performed in same room.
Also, prove that your algorithm satisfies the greedy-choice property.


*/
struct Activities { 
    int start; 
    int end; 
    int room;
}; 
/*Aktiviteleri 3 deger alacak sekilde structor yapýsýna koydum*/



int main() 
{ 
int i,a,b,c,d;
struct Activities temp={0,0,0};

	//burada aktivitelerin baslangýc ve bitis zamanlarýný verdým
    struct Activities arr[] = { {4,15}, { 8, 9 }, { 1, 2}, { 3, 4 },{5,7}, { 5, 9 }, { 0, 6 } }; 
    
    //kac tane aktivite oldugu
    int n1 = sizeof(arr) / sizeof(arr[0]); 
    
    printf("how many activity is there?  %d\n",n1);
    
    for(i=0;i<n1;i++)
    {
	printf ("%d. ACTIVITY:  start time= %d, end time= %d room: %d\n", i+1,arr[i].start, arr[i].end,arr[i].room);
    
	}
	
	//Bitis zamanýna göre aktivitelerin sort edilmesi
	//______________________________________________
	for(a=0;a<n1;a++){
		for(b=a+1;b<n1;b++){
			
			if(arr[a].end>arr[b].end){
				temp=arr[a];
				arr[a]=arr[b];
				arr[b]=temp;
			}
		}
	}
	printf("\n..:AFTER SORTING:..\n");
	for(i=0;i<n1;i++)
    {
	printf ("%d. ACTIVITY:  start time= %d, end time= %d room: %d\n", i+1,arr[i].start, arr[i].end,arr[i].room);
    
	}
	//_____________________________________________
	int r=0;
	int array[MAX];
	int co;
	 //ilk odayý aldý
	/*
		for(c=0;c<n1;c++){ //room belirle
		
			for(d=1+c;d<=n1;d++){ //bosalan activiteleri yerlestýr
				
						printf("arr[c]: %d  %d.d start:%d end:%d\n",arr[c].start,d,arr[d].start,arr[d].end);
						
					}
					
				}*/
				
			
		
		//odalarýn belirlenme iþlemi
		//eger end pointime esit veya buyukse bi sonraki aktivite de ayný
		//odayý alsýn
		for(c=0;c<n1;c++){ //room belirle
		int p=0;
		if(arr[c].room==0){
			r++; arr[c].room=r; printf("^^^^^^^^^^^^ %d\n",arr[c].room);
		}
			for(d=1+c;d<n1;d++){ //bosalan activiteleri yerlestýr
				//room alamayanlar için
					//arr[c].room=r;
					if(arr[c].end<=arr[d].start && arr[d].room==0){
						//velevki bu odanýn býtýs tairihinden sonra baslar ise
						//bu aktivitenin de roomunu öyle ayarla
						printf("\n ayni%d\n",d);
						arr[d].room=r;
						break;
					}
					/**/
				
				
			}
			
		}
			
		
		
	
		printf("\n..:AFTER ROOMING:..\n");
	for(i=0;i<n1;i++)
    {
	printf ("%d. ACTIVITY:  start time= %d, end time= %d room: %d\n", i+1,arr[i].start, arr[i].end,arr[i].room);
    
	}
	/*
	for(i=0;i<co;i++){
		printf("\n*******%d \n",array[i]);
	}
*/
	//_____________________________________________	
	
    return 0; 
}

