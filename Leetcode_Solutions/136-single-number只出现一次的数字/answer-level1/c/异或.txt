### 解题思路
1. 所有数做异或操作，相同的数结果为0，最后剩的就是唯一出现的数

### 代码

```c
int singleNumber(int* nums, int numsSize){
    int i, sum = 0;

    for (i = 0; i < numsSize; i++) sum ^= nums[i];
    return sum;
}
```