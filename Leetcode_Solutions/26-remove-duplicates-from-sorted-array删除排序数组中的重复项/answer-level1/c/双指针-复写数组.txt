### 解题思路
这题好在是已经排序好的数组，所以便可以较快的比较是否为重复项。
首先按照双指针的思想，一个（慢）指针为数组本身进行复写，一个（快）指针不断移动并判断是否为重复项；当快指针不等于此时的慢指针时，只移动快指针，直到它们不相等时，慢指针往下挪一位，此时让快指针的值复写掉慢指针的值，计算器加一。

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int count=1;
    int *q=nums;
    if(numsSize==0)
        return 0;
    for(int i=0;i<numsSize;i++){
        if(nums[count-1]!=q[i]){
            count++;
            nums[count-1]=q[i];
        }
    }
    return count;
}
```