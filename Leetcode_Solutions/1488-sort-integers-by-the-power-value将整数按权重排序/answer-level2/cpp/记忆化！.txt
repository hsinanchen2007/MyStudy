不难根据题意写出来一个求任意整数权重的程序。为了计算某个区间内所有整数对应的权值，发现这其中有很多子问题是重复的，例如：在求 `3` 的权重时，我们也计算了 `10` 的权值。因此，只要把这些结果都缓存起来，下一次遇到同样的问题直接查询即可。

根据那两条计算规则，我们发现，若是偶数，那么它会变成一半，即更小了。若是偶数，那么它会变成3倍加1，而 $3(2n+1)+1=6n+4=2(3n+2)$ 是一个偶数！因此，虽然奇数的下一个数会增加，但不会一直增加。因此对于给定的区间 `[lo, hi]`，所需要计算的子问题的个数应该是与 `hi` 成线性的。理论上应该可以给出一个上界，但是比赛的时候把 `[1, 1000]` 输进去跑一下就知道能不能过了。

代码如下：

```c++
class Solution {
    unordered_map<int, int> w;
    
    int weight(int n) {
        if (w.find(n) == w.end()) {
            if (n == 1) {
                w[1] = 0;
            } else if (n % 2 == 0) {
                w[n] = 1 + weight(n / 2);
            } else {
                w[n] = 1 + weight(3 * n + 1);
            }
        }
        
        return w[n];
    }
    
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> v;
        for (int n = lo; n <= hi; n++) {
            v.push_back(make_pair(n, weight(n)));
        }
        
        sort(v.begin(), v.end(), [](const auto& p1, const auto& p2) {
            if (p1.second < p2.second) return true;
            if (p1.second > p2.second) return false;
            return p1.first < p2.first;
        });
        
        return v[k - 1].first;
    }
};
```

当然找第 `k` 小或许有更科学的算法，但是排序显然时间上也能过得去的！