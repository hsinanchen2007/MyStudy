```
int findMin(int* nums, int numsSize){
    int n=nums[0];
    for(int i=1;i<numsSize;i++)
        if(nums[i]<n){
            n=nums[i];
            break;
        }
    return n;
}
```
