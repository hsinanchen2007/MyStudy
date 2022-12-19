```c
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    short i,j;
    *returnSize=0;
    for(i=0;i<numsSize;i=i+2) *returnSize=*returnSize+nums[i];
    int* a=(int*)malloc(*returnSize*sizeof(int));
    for(i=0,j=0;j<*returnSize;j++){
        if(nums[i]>0){
            a[j]=nums[i+1];
            nums[i]--;
        }
        else{
            i=i+2;
            j--;
        }
    }
    return a;
}
```