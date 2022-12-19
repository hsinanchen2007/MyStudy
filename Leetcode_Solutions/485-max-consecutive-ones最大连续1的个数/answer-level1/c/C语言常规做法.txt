```c
int findMaxConsecutiveOnes(int* nums, int numsSize){
    short count=0,max=count,i;
    for(i=0;i<numsSize;i++){
        if(nums[i]==1){
            count++;
            if(count>max) max=count;
        }
        else count=0;
    }
    return max;
}
```