### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/72ce872a20854fcec4eae11a2928f82e57b11b1279551e7fa696d9422f90628c-image.png)
几个重要性质：
1) 异或两个相同的数，等于没有异或，经常用于消除出现两次的数字
2) x &-x 可以生成一个保留最右边 bit为1的数字，其他bit都置为0
3) 两个只出现1次的数字，那么这个Bit1不是x就是y的，再一次&全部的数字，就可以得到x或者y
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int bitmask = 0;
    for (int i = 0; i < numsSize; i++) {
        bitmask ^= nums[i];
    }

    int diff = bitmask & (-bitmask);

    int x = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & diff) {
            x ^= nums[i];
        }
    }

    int *ans = calloc(2, sizeof(int));
    ans[0] = x;
    ans[1] = bitmask ^ x;
    *returnSize = 2;

    return ans;
}
```