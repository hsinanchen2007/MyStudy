# 方法一：穷举法
对所有符号组合求和，并求出等于S的个数
参考：[https://leetcode-cn.com/problems/target-sum/solution/mu-biao-he-by-leetcode/]()

**执行结果**
![截图.PNG](https://pic.leetcode-cn.com/cf8fbb2d9d9cabddfee4e4985fe5d06a677ba2de870acd7ced15c0138dce2302-%E6%88%AA%E5%9B%BE.PNG)

```c []
int count;
/*
i - 前i个元素
sum - 前i个元素的和
*/
void calculate(int* nums, int numsSize, int i, int sum, int S)
{
    if(i == numsSize) {
        if (sum == S) {
            count++;
        }
    } else {
        calculate(nums, numsSize, i + 1, sum + nums[i], S);
        calculate(nums, numsSize, i + 1, sum - nums[i], S);
    }
}

int findTargetSumWays(int* nums, int numsSize, int S){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    count = 0;

    calculate(nums, numsSize, 0, 0, S);

    return count;
}
```

# 方法二：记忆化搜索
参考：[https://leetcode-cn.com/problems/target-sum/solution/494-mu-biao-he-liang-chong-fang-fa-dfsji-yi-hua-so/]()
在解法一的过程中，实际上是有重叠子问题的，对于这一类重叠子问题，无需再重复递归计算。
使用一张表来存储子问题的解，当后续遇到相同子问题时，直接查表返回
memo[i][cur] 表示前i个数，总和为cur时，能达成numsSize个数总和为S的方案数

**执行结果**
![截图.PNG](https://pic.leetcode-cn.com/11b38b10730e7de95e7ec4917cf06bcb9db58068ed09ca3c09a58b47708c7362-%E6%88%AA%E5%9B%BE.PNG)


```c []
/*
i - 前i个元素
sum - 前i个元素的和
*/
int calculate(int* nums, int numsSize, int i, int sum, int S, int**memo)
{
    if(i == numsSize) {
        if (sum == S) {
            return 1;
        }
        return 0;
    }

    if(memo[i][sum + 1000] != -1) {
        return memo[i][sum + 1000];
    }

    memo[i][sum + 1000] = calculate(nums, numsSize, i + 1, sum + nums[i], S, memo) + 
                          calculate(nums, numsSize, i + 1, sum - nums[i], S, memo);
    
    return memo[i][sum + 1000];
}

int findTargetSumWays(int* nums, int numsSize, int S){
    int **memo;
    int i, j;

    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    memo = malloc(sizeof(int*) * numsSize);
    for(i=0; i<numsSize; i++) {
        memo[i] = malloc(sizeof(int) * 2000);
        for(j=0; j<2000;j++) {
            memo[i][j] = -1;
        }
    }

    return calculate(nums, numsSize, 0, 0, S, memo);
}
```

# 动态规划
递归写成非递归的形式，将子问题记录在表中，叫做动态规划
定义dp[i][j]：0~i个数和为j的方案数，可知
状态转移方程为：dp[i][j] = dp[i-1][j+nums[i]] + dp[i-1][j-nums[i]]
写成递推的形式
dp[i-1][j] -> dp[i][j+nums[i]]
dp[i-1][j] -> dp[i][j-nums[i]]
都表示左边会作为右边在状态转移方程中其中一个子问题的解

注意
对迭代0初始化时，注意nums[0]为0的情况，这时如果都用等号，会得出dp[0][1000]=1,但实际上dp[0][1000]=2（包含+0,-0）
dp[0][1000+nums[0]] = 1;
dp[0][1000-nums[0]] += 1;

**执行结果**
![QQ截图20200104221337.png](https://pic.leetcode-cn.com/da6ab732dd7b3082887492fd3ad330f0d79f1b90e5e0fedf52d8c740ed4aef23-QQ%E6%88%AA%E5%9B%BE20200104221337.png)

```c [动态规划]
int findTargetSumWays(int* nums, int numsSize, int S){
    int **dp;
    int i, j;
    int sum;

    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    dp = malloc(sizeof(int*) * numsSize);
    for(i=0; i<numsSize; i++) {
        dp[i] = malloc(sizeof(int) * 2001);
        for(j=0; j<2001;j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][1000+nums[0]] = 1;
    dp[0][1000-nums[0]] += 1;
    for(i=1; i<numsSize; i++) {
        for(sum=-1000; sum<=1000; sum++) {
            if(dp[i-1][sum+1000]) {
                dp[i][sum+nums[i]+1000] += dp[i-1][sum+1000];
                dp[i][sum-nums[i]+1000] += dp[i-1][sum+1000];
            }
        }
    }

    return S>1000 ? 0 : dp[numsSize-1][S+1000];
}
```

