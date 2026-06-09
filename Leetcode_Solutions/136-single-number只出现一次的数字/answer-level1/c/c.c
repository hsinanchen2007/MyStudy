### 解题思路
此处撰写解题思路
1、本题只想到了暴力法和哈希表法，但不满足时间复杂度o（n）以及空间复杂度为常数的要求；
2、看解答，发现采用异或运算。两个相同的值，异或后值为0。0^a=a。这样可得出最终结果

### 代码

```c
int singleNumber(int* nums, int numsSize){
     int result = nums[0];
     int i;

     for(i = 1; i < numsSize;  i++)
     {
         result ^= nums[i];
     }

     return result;
}
```