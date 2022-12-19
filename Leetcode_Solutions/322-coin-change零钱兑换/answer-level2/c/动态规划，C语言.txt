![零钱.PNG](https://pic.leetcode-cn.com/388a6e151d1fe48655dea1bc96d090f438799301acf0d30d02d55b634fd284e7-%E9%9B%B6%E9%92%B1.PNG)

方法一：递归
1、递归关系
dp(v) = min(dp(v-c) + 1)
2、边界条件
v == c ,return 1
方法二：备忘录
与递归类似，记录递归过程数据
```
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int dp(int* coins, int coinsSize, int amount, int *f)
{
    int min = 0xfffffff;
    int ret = 0;
    int flag = 0;
    if (amount == 0) {
        return 0;
    }
    
    for (int i = 0; i < coinsSize; ++i) {
        if (coins[i] == amount) {
            f[amount] = 1;
            return 1;
        }
        
        if (flag || coins[i] > amount) {
            continue;
        }
        
        if (f[amount - coins[i]] != 0) {
            min = MIN(min, f[amount - coins[i]]);
        } else {
            ret = dp(coins, coinsSize, amount - coins[i], f);
            if (ret == 1) {
                min = 1;
                flag = 1;
                continue;
            }
            if (ret != -1) {
                min = MIN(min, ret);
            }
        }
    }
    
    if (min != 0xfffffff) {
        f[amount] = min + 1;
        return f[amount];
    }
    return -1;
}

int coinChange(int* coins, int coinsSize, int amount){
    int *f = malloc(sizeof(int) * (amount + 1));
    
    memset(f, 0, sizeof(int) * (amount + 1));
    return dp(coins, coinsSize, amount, f);
}

```

方法二:动态规划
核心思想最有子结构，即子问题已经是最优解
1、状态转移关系
f[j] = 1 + min(f[j-c1], f[j-c2],...,f[j-cn])
2、边界条件，即初始值
当v == c时 ,f[v] = 1

```
int coinChange(int* coins, int coinsSize, int amount){
    int *f = NULL;
    int min = 0;
    
    if (amount == 0) {
        return 0;
    }
    f = malloc(sizeof(int) * (amount + 1));
    memset(f, 0, sizeof(int) * (amount + 1));
    
    for (int i = 0; i < coinsSize; ++i) {
        if (coins[i] <= amount) {
            f[coins[i]] = 1;
        }
    }
    for (int i = 1; i <= amount; ++i) {
        min = 0;
        if (f[i] != 0) {
            continue;
        }
        for (int j = 0; j < coinsSize; ++j) {
            if (coins[j] >= i) {
                continue;
            }
            if (f[i - coins[j]] == 0) {
                continue;
            }
            if (min == 0) {
                min = f[i - coins[j]];
            } else {
                min = min < f[i - coins[j]] ? min : f[i - coins[j]];
            }
        }
        if (min != 0) {
            f[i] = min + 1;
        }
    }
    if (f[amount] != 0) {
        return f[amount];
    }
    return -1;
}
```
