
看了很多题解，大多都是贪心算法进行解题

**动态规划思路：**

假设dp[i]表示从0跳到i的最小跳跃数，则可以得到状态转移方程如下所示：


***dp[i] = Min(dp[j]) + 1*** (j取值范围为[0, i], 限制条件为 j + dp[j] >= i)

意思是i这个位置的跳跃数等于 0 - i中能跳到i这个节点中最小的一个

疑问？
不增加break会在最后一个用例超时，增加后就不太符合转移方程了

# 参考代码
```
#define MAX_SIZE 10000
int Min(int a, int b)
{
    return a > b ? b : a;
}
int jump(int* nums, int numsSize){
    
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    memset(dp, 0, sizeof(int) * numsSize);
    
    for (int i = 1; i < numsSize; i++) {
        dp[i] = i;
        for (int j = 0; j <= i; j++) {
            if (j + nums[j] >= i) {
                dp[i] = Min(dp[i], dp[j]);
                break; // ???
            }
        }
        dp[i] += 1;
    }
    
    return dp[numsSize - 1];
    
}
```
