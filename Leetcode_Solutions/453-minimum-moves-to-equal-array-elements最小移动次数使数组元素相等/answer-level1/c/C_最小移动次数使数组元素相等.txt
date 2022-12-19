### 解题思路
"移动"，就是指在数组中选取任一元素nums[i]，令nums[i]以外的元素值+1
技巧: 除了nums[i]都加1==只有nums[i]减一。所以每个除了最小元素，每个元素可以减去n之后等于最小元素，那么答案就是所有的n的和
### 代码

```c
int minMoves(int* nums, int numsSize){

    int min=(~((unsigned)0))>>1;

    for(int i=0;i<numsSize;++i)
        if(min>nums[i])
            min=nums[i];

    int result=0;
    for(int i=0;i<numsSize;++i)
        result=result+(nums[i]-min);

    return result;
}
```