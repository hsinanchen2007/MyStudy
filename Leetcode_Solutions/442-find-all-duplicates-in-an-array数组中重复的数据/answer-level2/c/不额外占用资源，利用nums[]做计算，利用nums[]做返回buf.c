【思路】
关键在于利用题目的条件1 ≤ a[i] ≤ n, 所以nums[i]的值肯定都小于等于n。

不额外占用资源，对nums[i]-1 为索引的数nums[nums[i]-1]增加权重 (2倍numsSize)。

一遍循环过后，所有大于4倍numsSize的元素对应的索引+1必然是重复的值。

返回值继续借用nums[]数组。


```
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int i;

    // 循环一遍，令：nums[i]-1 为索引的数nums[nums[i]-1]增加权重 (2*numsSize)
    for (i=0;i<numsSize;i++) {
        nums[(nums[i]%(numsSize<<1))-1] += (numsSize<<1);
    }
    

    *returnSize = 0;
    for (i=0;i<numsSize;i++) {
        // 所有nums[i]取值大于(4*numsSize)的，说明取值为i+1的值出现过重复
        if (nums[i] > (numsSize<<2)) {
            nums[*returnSize] = i+1;
            *returnSize = *returnSize + 1;
        }
    }

    return nums;
}
```


