题目要求的是$g\leq G,p\geq P$的方法总数。根据容斥原理，我们可以得到
$$N(g\leq G)=N(g\leq G,p\geq P)+N(g\leq G,p<P)$$
从而我们可以把题目转化为，求$g\leq G$以及$g\leq G,p<P$的方法总数。这样就变成了最经典的背包问题，分别是一维约束和二维约束。注意一下`profit[i]`可能为0，所以在枚举第二维约束的时候需要枚举到0。

不太熟悉背包问题的同学可能不清楚为什么约束维要从大到小循环。这里从大到小循环，先更新后面较大的值，可以保证在计算前面较小的值的时候，不会受到影响。而如果从小到大循环，就可能出现1更新了3，又用更新了的3去更新别的数，这样就重复计数了。当然，如果一定要从小到大循环也是可以的，但就需要再增加一个临时数组，用来保存更新前的状态。

参考代码：
```cpp
typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int N = group.size();
        vector<ll> f(G + 1);
        f[0] = 1;
        for (int i = 0; i < N; ++i)
            for (int j = G; j > 0; --j)
                if (j >= group[i])
                    f[j] = (f[j] + f[j - group[i]]) % MOD;
        ll TF = 0;
        for (ll i : f)
            TF = (TF + i) % MOD;
        vector<vector<ll>> g(G + 1, vector<ll>(P));
        g[0][0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = G; j > 0; --j)
                for (int k = P - 1; k >= 0; --k)
                    if (j >= group[i] && k >= profit[i])
                        g[j][k] = (g[j][k] + g[j - group[i]][k - profit[i]]) % MOD;
        }
        ll TG = 0;
        for (auto v : g)
            for (ll i : v)
                TG = (TG + i) % MOD;
        return (TF - TG + MOD) % MOD;
    }
};
```