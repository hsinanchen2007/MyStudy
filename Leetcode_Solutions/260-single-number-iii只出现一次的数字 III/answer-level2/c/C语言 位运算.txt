### 解题思路
思路见注释，此处仅做为C代码写法参考

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int i, res = 0, xorRes = 0, pos = 0;
    *returnSize = 2;
    int *resArr = (int *)malloc(sizeof(int) * 2);

    //异或 - 得到两个只出现一次的元素的异或值
    for(i = 0; i < numsSize; i++) xorRes ^= nums[i];
    //从右到左找到xorRes第一个为1的位置
    while(((xorRes >> pos) & 1) != 1) pos++;
    //在nums中查找在相同位置上位1的数，并累计异或，保证这个数只出现一次 a ^ a ^ b = b
    for(i = 0; i < numsSize; i++){
        if((nums[i] >> pos) & 1) res ^= nums[i];
    }
    resArr[0] = res;
    resArr[1] = res ^ xorRes;
    return resArr;
}
```