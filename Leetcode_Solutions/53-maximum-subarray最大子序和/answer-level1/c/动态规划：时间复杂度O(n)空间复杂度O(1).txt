### 解题思路
动态规划：问题能不能用动态规划解决取决于这些”小问题“会不会被被重复调用。

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int ret = nums[0];
    int dp = nums[0];
    int tmp = 0;
    int i = 1;
    for(; i < numsSize; i++){
        tmp = dp + nums[i];
        dp = (tmp > nums[i]) ? tmp : nums[i];
        ret = (ret > dp) ? ret : dp;
    }
    return ret;
}
```