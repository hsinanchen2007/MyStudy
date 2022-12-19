### 解题思路
此处撰写解题思路

1. 每个整数异或自身，都能得到0
2. 0 异或任何整数得到该整数
3. 只出现一次的整数，只需要遍历异或就可以得到
4. 
### 代码

```c
int singleNumber(int* nums, int numsSize){
    if (nums == NULL || numsSize < 1) {
        return 0;
    }

    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res = res ^ nums[i];
    }

    return res;
}
```