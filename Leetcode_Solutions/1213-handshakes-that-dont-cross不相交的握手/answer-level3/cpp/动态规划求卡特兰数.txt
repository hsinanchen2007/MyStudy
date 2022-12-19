### 解题思路

1. 固定一个人先握手，可以把人群划分为两个子图，每个都是最优子结构；
2. 固定的人握手选择不是随机的，假定所有人编号为 P ~ P+2k-1，我们固定第一个人为P，他只能选择P, P+1, P+3, ………， P+2k-1这些人握手。否则，将会产生奇数个节点的子图，无法合法划分；
3. 对于每个子图，递归进行划分；
4. 最终的方案数为 P(2k) = Sum { P(2*i) * P(2*k - 2*i - 2) }, 其中 i = 0 ~ k - 1。可以用动态规划，避免底层卡特兰数的重复计算。

### 代码

```cpp
class Solution {
private:
    int n;
    unsigned long MOD = 1000000007L;
    vector<unsigned long> dp;
public:
    int numberOfWays(int num_people) {
        n = num_people;
        dp.resize(n+2);
        if(n % 2)
            return 0;
        int k = n / 2;
        dp[0] = 1;
        for(int i=1; i<=k; i++) {
            for(int j=0; j<i; j++) {
                dp[2 * i] += dp[2 * j] * dp[2 * i - 2 * j - 2];
                dp[2 * i] %= MOD;
            }
        }
        return dp[n] % MOD;
    }
};
```