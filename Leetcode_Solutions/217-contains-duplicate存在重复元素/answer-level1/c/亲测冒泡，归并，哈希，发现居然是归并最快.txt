```
void Merge(int A[],int low,int mid,int high,int *B){
    int i,j,k;
    printf("low=%d,high=%d\n",low,high);
    for(k=low;k<=high;k++)
        B[k]=A[k];
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i]<=B[j]){
            A[k]=B[i++];
        }else
        {
            A[k]=B[j++];
        }
        
    }
    while(i<=mid)A[k++]=B[i++];
    while(j<=high)A[k++]=B[j++];
}
void MergeSort(int A[],int low,int high,int *B){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(A,low,mid,B);
        MergeSort(A,mid+1,high,B);
        Merge(A,low,mid,high,B);
    }
}
bool containsDuplicate(int* nums, int numsSize){
    
    int *B=(int*)malloc(sizeof(int)*(numsSize+1));
    MergeSort(nums,0,numsSize-1,B);
    for(int i = 0;i < numsSize -1;i++){
            if(nums[i] == nums[i + 1]) return true;
    }
    return false;

}
```
