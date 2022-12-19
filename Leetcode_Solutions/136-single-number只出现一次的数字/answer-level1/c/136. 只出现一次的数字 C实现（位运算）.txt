### 解题思路
    本人前一题解为了练习uthash.h用了哈希表，实际上不用，异或运算的特性即可。
    出现两次的数异或在res每一位上的信息必然被置为0（请细品）只出现一次的数的每一位信息会保留在res中。
    请细品。
### 代码

```c
int singleNumber(int* nums, int numsSize){
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res ^= nums[i];
    }
    return res;
}
```