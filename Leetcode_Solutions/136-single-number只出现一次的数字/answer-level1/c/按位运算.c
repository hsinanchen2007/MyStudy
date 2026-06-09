### 解题思路
其实按位, 本质上和数学计算是一样的
- 数学
   2*(去掉重复的) - 所有的加起来
- 按位异或
   重复的变为0, 最后剩下不重复的
### 代码

```c
int singleNumber(int* nums, int numsSize){
    int res = 0;
    for(int i=0;i<numsSize;i++)
        res ^= nums[i];
    return res;
}
```