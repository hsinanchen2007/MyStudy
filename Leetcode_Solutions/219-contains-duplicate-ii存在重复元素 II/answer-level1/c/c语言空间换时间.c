```
typedef struct node{
    int val;
    int index;
};

void Merge(struct node A[],int low,int mid,int high,struct node *B){
    int i,j,k;
    for(k=low;k<=high;k++){
        B[k].val=A[k].val;
        B[k].index=A[k].index;
    }
        
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i].val<=B[j].val){
            A[k].val=B[i].val;
            A[k].index=B[i++].index;
        }else
        {
            A[k].val=B[j].val;
            A[k].index=B[j++].index;
        }
        
    }
    while(i<=mid){
        A[k].val=B[i].val;
        A[k++].index=B[i++].index;
    }
    while(j<=high){
         A[k].val=B[j].val;
         A[k++].index=B[j++].index;
    }
}
void MergeSort(struct node A[],int low,int high,struct node *B){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(A,low,mid,B);
        MergeSort(A,mid+1,high,B);
        Merge(A,low,mid,high,B);
    }
}
int distance(int i,int j,int k){
    if(i-j<=k&&i-j>=0||j-i<=k&&j-1>=0)
        return 1;
    return 0;
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    struct node *B=(struct node*)malloc(sizeof(struct node)*(numsSize+1));
    struct node *A=(struct node*)malloc(sizeof(struct node)*(numsSize));
    for(int i=0;i<numsSize;i++){
        A[i].val=nums[i];
        A[i].index=i;
    }
    MergeSort(A,0,numsSize-1,B);
    for(int i = 0;i < numsSize -1;i++){
            if(A[i].val == A[i + 1].val&&distance(A[i].index,A[i+1].index,k)) return true;
    }
    return false;
}
```
