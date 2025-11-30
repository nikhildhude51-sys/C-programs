#include <stdio.h>
#include<math.h>
int main() {
     printf("=====================================================\n");
    printf("          STATISTICAL MEASURES CALCULATOR\n");
    printf("=====================================================\n");

    int n,i,j;
    printf("Enter The No.of Data Items :\n");
    scanf("%d",&n);
    printf("\n");
    int data[n],freq[n];
    printf("Enter The Data Items :\n");
    for(i=0;i<n;i++){
        scanf("%d",&data[i]);
        freq[i]=1;
    }
    
    int temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(data[i]>data[j]){
            temp=data[i];
            data[i]=data[j];
            data[j]=temp;
        }
        }
    }
    printf("\n");
    printf("The Sorted Data :\n");
    for(i=0;i<n;i++){
        printf("%d ",data[i]);
    } 
    
    //*******************************FOR _ MEAN********************************
     float mean;
     int sum=0;
     for(i=0;i<n;i++){
         sum+=data[i];
     }
    mean=(float)sum/n;
    printf("\n  \n");
    printf("*********************THE RESULTS*********************\n");
    printf(" ");
    printf("\nThe Mean :%.2f",mean);
    
    //*******************************FOR _ MEDIAN*******************************
     float median;
     if(n%2==0){
         median=(data[n/2-1]+data[n/2])/2.0;
     }
    else{
        median=data[n/2];
    }
    printf("\n ");
    printf("\nThe Median :%.2f",median);
    printf("\n \n");
     
    //*******************************FOR _ MODE********************************
    
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(data[i]==data[j]){
               freq[i]++;
               freq[j]=0;}
        }
       }
    int max_freq=freq[0];
    for(i=0;i<n;i++){
    if(freq[i]>max_freq){
        max_freq=freq[i];
    }
    } 
     
    int countmaxf=0;
    for(i=0;i<n;i++){
        if(freq[i]==max_freq){
            countmaxf++;
        }
    }
    
    if(countmaxf==1){
        for(i=0;i<n;i++){
            if(freq[i]==max_freq){
                printf("The Mode=%d (frequency=%d)\n",data[i],max_freq);
                break;
            }
        }
    }else{
          if(max_freq==1){
          printf("Mode Does Not Exist!\n");
          }
           
          else { 
             printf("MULTIMODAL DATA .Frequency=%d.Modes are :",max_freq);
        for(i=0;i<n;i++){
            if(freq[i]==max_freq){
                printf("%d ",data[i]);
            }
        }
    }
    }
    printf(" \n");
    
    
    //*******************************FOR _ VARIANCE***************************
    
    float alpha[n];
    for(i=0;i<n;i++){
        alpha[i]=(float)data[i]-mean;
    }
    float beta[n];
    for(i=0;i<n;i++){
        beta[i]=alpha[i]*alpha[i];
    }
    float sumbeta=0.0;
    for(i=0;i<n;i++){
        sumbeta+=beta[i];
    }
    float variance=sumbeta/n;
    printf("The Variance :%.2f",variance);
    
    //*******************************FOR _ STANDARD_DEVIATION*****************
    printf("\n \n");
    float sd=sqrt(variance);
    printf("The Standard Deviation :%.2f",sd);
    
     printf("\n---------------- EXTRA INFORMATION ----------------\n");

    printf("Minimum Value : %d\n", data[0]);
    printf("Maximum Value : %d\n", data[n - 1]);
    printf("Range : %d\n", data[n - 1] - data[0]);
      
      printf("=====================================================\n");
    printf("               END OF CALCULATION\n");
    printf("=====================================================\n");
 
    return 0;
}
