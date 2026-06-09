本题和[ GT 考试](https://www.luogu.com.cn/problem/P3193)一题十分相似，但是数据限制上有很大的差别。

相似的地方在于，两题都用了 KMP 算法构造失配转移的 `next` 数组，基本的 DP 设定也都是用 $f(i, j)$ 表示使用完前 $i$ 个字符，匹配到禁止串（这里是 `evil`）的前 $j$ 个字符的方案数目。

但不同的地方在于 GT 考试这题没有限定上下界，而本题设定了上下界。方便起见，先把上下界转换为单独的上界，即设 $g(s)$ 为所有长度和 $s$ 相同且字典序 $\le s$ 的“好字符串”。那么本题的答案就是 $g(s_2) - g(s_1) + check$，如果 $s_1$ 是“好字符串”那么 $check=1$，反之 $check=0$。

然后考虑处理 $g(s)$。这里可以套用数位 DP 的技巧（我猜这个是数位 DP 的技巧，因为我没怎么做过数位 DP），用一个指示位 $k$ 标记前 $i$ 个字符有没有卡到上界（即和 $s$ 的前 $i$ 位相同）。设 $k=1$ 表示卡到了。

为什么要考虑卡到了这个问题？因为转移的时候，$k=0$ 可以从 $k=0$ 或 $1$ 的状态转移而来，但 $k=1$ 的状态只能从 $k=1$ 的转移而来。

由上面的讨论，设 $f(i, j, k)$ 为使用完前 $i$ 个字符，匹配到禁止串（这里是 `evil`）的前 $j$ 个字符，且是否卡到上界的状态为 $k$ 的方案数目。初始状态为 $f(0, 0, 1) = 1$。

具体的转移方程还依赖于辅助数组 $fd(j, c)$，表示匹配完了 `evil` 的前 $j$ 个字符，再来一个新的字符 $c$，最多能匹配到 `evil` 的前多少个字符。有了这个数组，我们就可以对于 $f(i-1, j, k)$ 枚举 $c$，从而转移到 $f(i, fd(j, c), k')$ 上。（当然，这一部分的理解也可以参照 GT 考试一题）

最后有 $g(s) = \sum_{i=0}^{l - 1} f(n, i, 0) + f(n, i, 1)$，这里 $l$ 表示 `evil` 的长度。

总的时间复杂度为 $O(26 n l)$。

```cpp
const int M = 1000000007;
class Solution {
    int nxt[55];
    int f[505][55][2];
    int fd[55][27];
    int subp(int n, string& s, string& e){
        memset(f, 0, sizeof(f));
        int l = e.length();
        f[0][0][1] = 1;
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < 26; ++j){
                for (int t = 0; t < l; ++t){
                    f[i][fd[t][j]][0] = (f[i][fd[t][j]][0] + f[i - 1][t][0]) % M;
                    if (j < s[i - 1] - 'a')
                        f[i][fd[t][j]][0] = (f[i][fd[t][j]][0] + f[i - 1][t][1]) % M;
                    else if (j == s[i - 1] - 'a')
                        f[i][fd[t][j]][1] = (f[i][fd[t][j]][1] + f[i - 1][t][1]) % M;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < l; ++j){
            res = (res + f[n][j][0]) % M;
            res = (res + f[n][j][1]) % M;
        }
        return res;
    }
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        nxt[0] = -1;
        int l = evil.size();
        // 构造 next 数组
        for (int j = -1, i = 1; i < l; ++i){
            while (j > -1 && evil[i] != evil[j + 1])
                j = nxt[j];
            if (evil[i] == evil[j + 1])
                nxt[i] = ++j;
            else nxt[i] = -1;
        }
        // 计算失配转移
        for (int i = -1; i < l - 1; ++i){
            for (int j = 0; j < 26; ++j){
                if (evil[i + 1] - 'a' == j)
                    fd[i + 1][j] = i + 1 + 1;
                else {
                    if (i == -1) fd[0][j] = 0;
                    else fd[i + 1][j] = fd[nxt[i] + 1][j];
                }
            }
        }
        int res1 = subp(n, s2, evil), res2 = subp(n, s1, evil);
        int ans = (res1 + M - res2) % M;
        // 补一个 check
        if (s1.find(evil) == string::npos) 
            ans = (ans + 1) % M;
        return ans;
    }
};
```