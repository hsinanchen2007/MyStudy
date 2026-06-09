### 解题思路
很容易想到这道题目要用并查集的方法，但难点在于如何构建这个并查集。

直接枚举数值对至少是$O(n^2)$的复杂度，显然不行。注意到所有数都不超过$100000$，这意味着我们可以在$\sqrt{100000}$的时间内枚举每个数的因数。

我们构建一个大小为$100000+n$的并查集，前$100000$个节点代表$1...100000$之间的每一个正整数，后面$n$个节点代表数组中的元素。

我们枚举数组中的每一个数，将其与所有非1（一定要记得排除1，因为1是所有数的因子，如果不排除1，所有数都会相连）的因子相连。

连接完毕后，我们遍历并查集后$n$个节点，统计它们对应的连通块内属于数组节点的个数。所得到的最大值即为本题的答案。

总时间复杂度$O(n\sqrt{m}\alpha(n\sqrt{m}))$，其中$m=100000$为数值上界，$\alpha(n)$为Ackerman函数的反函数，是采用了路径压缩和按秩合并两种优化后的并查集操作的时间复杂度，可以近似认为等于1。

### 代码

```cpp
#define MAXN 100000

class Solution {
    vector<int> f, s;
    
    int find(int a) {
        if (f[a] == a) return a;
        return f[a] = find(f[a]);
    }
    
    void connect(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa != fb) {
            if (s[fa] >= s[fb]) {
                f[fb] = fa;
                s[fa] += s[fb];
            } else {
                f[fa] = fb;
                s[fb] += s[fa];
            }
        }
    }
public:
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        f = vector<int>(MAXN + n + 1);
        s = vector<int>(MAXN + n + 1, 1);
        for (int i = 1; i <= MAXN + n; ++i)
            f[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j * j <= A[i]; ++j) {
                if (A[i] % j == 0) {
                    if (j != 1)
                        connect(MAXN + i + 1, j);
                    connect(MAXN + i + 1, A[i] / j);
                }
            }
        }
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i = MAXN + 1; i <= MAXN + n; ++i)
            ans = max(ans, ++cnt[find(i)]);            
        return ans;
    }
};
```