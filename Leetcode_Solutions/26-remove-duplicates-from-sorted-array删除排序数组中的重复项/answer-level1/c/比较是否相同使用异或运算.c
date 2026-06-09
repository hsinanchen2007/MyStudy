### 解题思路
相同的数异或结果为0，不同为非0.

### 代码


```c
int removeDuplicates(int* nums, int numsSize){
    if(numsSize<2) return numsSize;

    int i=0,j=1;
    for(;j<numsSize;++j)
        if(nums[i]^nums[j])     
            nums[++i]=nums[j];

    return i+1;
}
```