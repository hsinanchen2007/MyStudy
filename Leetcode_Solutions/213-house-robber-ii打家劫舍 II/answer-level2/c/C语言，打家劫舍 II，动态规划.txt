  
动态规划的关键就是找通项公式，这个题的通项公式很简单，
  
会DP应该都能想到：dp[i] = MAX(dp[i-1], dp[i-2] + nums[i])。
  
主要障碍在于首尾相连，第1间房子偷不偷如果用变量来记录比较麻烦。
  
直接分2种情况，同步DP就简单很多。
  
```C
#define MAX(a,b) ((a)>(b)?(a):(b))

int rob(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    //分两种情况dp，a为偷第1间，b为不偷第1间
    int i, a[numsSize], b[numsSize];
    a[0] = nums[0];
    a[1] = nums[0];
    b[0] = 0;
    b[1] = nums[1];
    for(i = 2; i < numsSize; i++) {
        a[i] = MAX(a[i-1], a[i-2] + nums[i]);
        b[i] = MAX(b[i-1], b[i-2] + nums[i]);
    }
    return MAX(a[numsSize-2], b[numsSize-1]);
}
```
