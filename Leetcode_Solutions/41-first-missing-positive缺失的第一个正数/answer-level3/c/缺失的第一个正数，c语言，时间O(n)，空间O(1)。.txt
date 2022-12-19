### 解题思路

官方题解，三次遍历。时间O(n)，空间O(1)。
1.遍历数组，将负数，零，和大于numsSize的数替换为1。检查 1 是否存在于数组中，如果没有，1 即为答案。
2.遍历数组，每读一个数字，取其绝对值|a|，如果数组第|a|个数字（下标为|a|-1）为正数，就将其变为负数。
3.遍历数组，如果发现存在正数了，则第一个未出现的正整数为这个正数的下标+1。如果遍历完也没发现正数，那么第一个未出现的正整数为numsSize+1，并且数组中第一个未出现正整数最大为numsSize+1。

### 代码
```c
int firstMissingPositive(int* nums, int numsSize){
    int mark = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == 1){
            mark = 1;
        }
        if(nums[i]<=0 || nums[i]>numsSize){
            nums[i] = 1;
        }
    }
    if(mark == 0){
        return 1;
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i] < 0){
            if(nums[-nums[i]-1] > 0){
                nums[-nums[i]-1] = -nums[-nums[i]-1];
            }
        }else{
            if(nums[nums[i]-1] > 0){
                nums[nums[i]-1] = -nums[nums[i]-1];
            }
        }    
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i] > 0){
            return i+1;
        }
    }
    return numsSize+1;
}
```