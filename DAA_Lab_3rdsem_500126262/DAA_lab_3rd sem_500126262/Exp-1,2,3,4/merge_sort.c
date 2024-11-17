#include<stdio.h>
int main(){
int n1, n2;
printf("Enter length of arr1: ");
scanf("%d", &n1);
printf("Enter length of arr2: ");
scanf("%d", &n2);
int arr1[n1], arr2[n2];
printf("Enter the elements of arr1: \n");
for(int i=0; i<n1;i++){
scanf("%d", &arr1[i]);
}
printf("Enter the elements of arr2: \n");
for(int j=0; j<n2;j++){
scanf("%d", &arr2[j]);
}
printf("arr1:\n");
for(int i=0; i<n1;i++){
printf("%d ", arr1[i]);
}
printf("\narr2:\n");
for(int i=0; i<n2;i++){
printf("%d ", arr2[i]);
}
int n = n1+n2;
int mergedarr[n];
int i=0, j=0, k=0;
while(i<n1 && j<n2){
    if(arr1[i]<arr2[j]){
        mergedarr[k] = arr1[i];
        i++;
    } else {
        mergedarr[k] = arr2[j];
        j++;
    }
    k++;
}
    while(i<n1){
        mergedarr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        mergedarr[k] = arr2[j];
        j++;
        k++;
    }

printf("\nMerged array:\n");
for(int j=0; j<n;j++){
    printf("%d ", mergedarr[j]);
}
return 0;
}