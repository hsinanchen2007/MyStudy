参考448
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    if(nums==NULL){
        return nums;
    }
    int* ret=(int*)malloc(numsSize*sizeof(int));
    *returnSize=0;
    int index=0;
    for(int i=0;i<numsSize;i++){
        if(nums[abs(nums[i])-1]>0){
            nums[abs(nums[i])-1]=-1*nums[abs(nums[i])-1];
        }
        else if(nums[abs(nums[i])-1]<0){
            ret[index]=abs(nums[i]);
            index++;
        }
    }
    *returnSize=index;
    return ret;
}
```
