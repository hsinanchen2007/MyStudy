### 解题思路
本题采用动态规划和排列组合的知识解决，思路非常清晰，具体分析过程如下：

1.利用dp思路，对于dp[n]利用dp[n-1]的结果得到

2.如何利用dp[n-1]得到dp[n]?

3.对于前n-1个D&P，有gap=(n-1)*2+1个缝隙，可供第n个D&P插入

4.可以从gap中任选两个分别插入D和P，即C(gap, 2)

5.也可以从gap中选择1个，放入DP，即C(gap,1)

6.得到结果dp[n] = dp[n-1] * (C(gap,2) + C(gap,1))

![image.png](https://pic.leetcode-cn.com/a9277f634b0f9523183be5fd7149fac6bcccf30cc7c3d73e61b267b7c26d4f71-image.png)


### 代码

```c

typedef long long ll_t;

/*
//从n个数中选m
ll_t comb(ll_t n, ll_t m) {
    if(n == m || m == 0) {
        return 1;
    }

    ll_t ret = 1;
    for(int i = 0; i < m; i++) {
        ret *= n - i;
    }

    for(int i = 0; i < m; i++) {
        ret /= i + 1;
    }

    return ret;
}
*/
//【算法思路】dp+数学。
// 假设有n-1个值，增加一个后，可以有如下新的结果：
// n-1个值有gap = (n-1) * 2 + 1个缝隙
// 可以选择其中两个缝隙，分别放入D和P，即C(gap, 2)
// 也可以选择一个缝隙，放入DP,即C(gap,1)
// 所以n个值的结果 = dp[n-1] * (C(gap,2) + C(gap,1))
int countOrders(int n){
    if(n == 1) {
        return 1;
    }

    ll_t *dp = (ll_t *)calloc(n + 1, sizeof(ll_t));
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        ll_t gap = (i - 1) * 2 + 1;
        //dp[i] = dp[i - 1] * (comb(gap, 2) + gap);
        dp[i] = dp[i - 1] * (gap * (gap - 1) / 2 + gap) % 1000000007;
    }

    return dp[n];
}
```