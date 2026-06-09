遍历数组，为奇数时置于新数组前端，否则置于后端。
```c
int* exchange(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    int *res=malloc(sizeof(int)*numsSize);
    int i,j=0,k=numsSize-1;
    for(i=0;i<numsSize;i++){
        if(nums[i]%2==1){
            res[j]=nums[i];
            j++;
        }
        else{
            res[k]=nums[i];
            k--;
        }
    }
    return res;
}
```