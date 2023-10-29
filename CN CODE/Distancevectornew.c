/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    printf("Hello World");
   /* int DT[4][4]={
        {0,1,16,1},
        {1,0,1,16},
        {16,1,0,16},
        {1,16,16,0}
    };*/
    int nodes=7;
    int DT[nodes][nodes];
    for(int i=0;i<nodes;i++){
        
        for(int j=0;j<nodes;j++){
            DT[i][j]=nodes*2;
            if(i==j){
                DT[i][j]=0;
            }
            
        }
        
    }
    int e,t1,t2;
    scanf("%d",&e);
    for(int i=0;i<e;i++){
        printf("t1 :");
        scanf("%d",&t1);
        printf("t2 :");
        scanf("%d",&t2);
        DT[t1][t2]=1;
    }
    
    
    for(int k=0;k<nodes;k++){
        
    for(int x=0;x<nodes;x++){
    for(int i=0;i<nodes;i++){
        if(i==x){
            continue;
        }
        if(DT[x][i]==nodes*2){
            continue;
        }
        for(int j=0;j<nodes;j++){
            if(j==i){
                continue;
            }
            if(DT[x][j]>DT[i][j]+DT[x][i]){
                DT[x][j]=DT[i][j]+DT[x][i];
            }
            
        }
    }
    }
    
    }
    for(int i=0;i<nodes;i++){
        
        for(int j=0;j<nodes;j++){
            printf("%d ",DT[i][j]);
            
        }
        printf("\n");
    }
    return 0;
}
