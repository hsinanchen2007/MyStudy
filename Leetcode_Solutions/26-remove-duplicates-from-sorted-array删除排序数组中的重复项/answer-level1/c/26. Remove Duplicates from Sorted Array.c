```
int removeDuplicates(int* nums, int numsSize){
    if(numsSize < 2) return numsSize;
    int num = 0;
    nums[num++] = nums[0];
    int i;
    for(i = 0;i < numsSize - 1;i++){
        if(nums[i + 1] > nums[i])
            nums[num++] = nums[i + 1];
    }
    return num;
}
```



