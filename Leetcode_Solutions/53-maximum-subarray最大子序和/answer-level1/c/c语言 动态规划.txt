### 解题思路
//动态规划问题，寻找状态，连续子数组和最大
//当前数组位i：dpmax = max(dpmax+num[i], num[i])

### 代码

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxSubArray(int* nums, int numsSize){
   int dpmax = 0;
   int max = nums[0];
   for (int i = 0; i < numsSize; i++) {
       dpmax = MAX((dpmax + nums[i]), nums[i]);
       max = MAX(max, dpmax);
   }
    return max;
}
```