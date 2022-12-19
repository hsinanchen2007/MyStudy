# 5371. 找到所有好字符串
可以使用动态规划 + 容斥原理来解决该题。
首先处理特殊数据，如果 s1 > s2 ，直接返回 0 。

然后用容斥原理简化一下问题:
设函数 f(s, evil) 可以计算出字典序不超过 s 且不包含 evil 的字符串的数量。另设置一个变量 cnt，当 s1 包含 evil时， cnt = 0, 否则 cnt = 1。那么最终答案为 f(s2, evil) - f(s1, evil) + cnt。
设置 cnt 的目的是：当 f(s1, evil) 返回的数量中包含 s1 本身时，需要避免 s1 被容斥排除掉。

用动态规划来实现 f(s, evil)。动态规划数组dp[i][j][k]。第一维度表示拼接过程中，当前字符串的长度，第二维度表示拼接过程中，当前字符串是否与 s 的等长前缀相同。 j = 1 表示相同，j = 0 表示不相同。第三维度表示当前字符串的后缀与 evil 的前缀的重叠长度。
当 i = 0时，显然有 dp[0][1][0] = 1，对于其他 dp[0][x][y] 均为 0。
接下来枚举下一个拼接的字符 c ，根据题意计算出从当前状态 dp[i][j][k] 后拼接 c 后转移到 ni,nj,nk。状态转移策略参考代码注释。
f(s, evil)的返回结果记为 dp[n][0][m]，dp[n][1][m]的累加和，m∈[0,evil.size()]。

```cpp
const int64_t MOD = 1000000007;
inline void add(int64_t &a, int64_t b) {
    a += b;
    if(a >= MOD) {
        a %= MOD;
    }
}
class Solution {
public:
    void get(const string &s, const string &evil, int n, int64_t &sum, int64_t &part) {
        int64_t dp[501][2][51] = {0};
        int m = evil.size();
        dp[0][1][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < m; k++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        int ni = i+1, nj = -1, nk = -1;
                        if(j == 1) {
                            if(c > s[i]) {
                                //当前字符串与s前缀相同，
                                // 所以不能拼接更大的 c。
                                break;
                            }
                            if(c == s[i]) {
                                //拼接完后仍与s前缀相同，
                                //所以 nj = 1。
                                nj = 1;
                            } else { 
                                //拼接完后小于s前缀，
                                //所以 nj = 0。
                                nj = 0;
                            }
                        } else {
                            //已经比s前缀小了，
                            //无论拼接什么字符，仍然是小。
                            nj = 0;
                        }
                        if(c == evil[k]) {
                            //已经重叠了k个字符，
                            //且 c 与 evil的第k+1字符相等，
                            //所以 nk = k+1
                            nk = k+1;
                        } else {
                            //尝试寻找最大的与evil的重叠长度
                            nk = 0;
                            for(int p = 0; p <= k; p++) {
                                int len = (k-p);
                                if(evil[len] != c) { continue; }
                                bool flag = true;
                                for(int q = 0; q < len; q++) {
                                    if(evil[q] != evil[q+p]) { flag = false; break; }
                                }
                                if(flag) { nk = len+1; break;}
                            }
                        }
                        //nk == m 时，说明当前字符串已经包含了 evil
                        //所以不能记入总数。
                        if(nk == m) {
                            continue;
                        }
                        add(dp[ni][nj][nk], dp[i][j][k]);
                    }
                }
            }
        }
		sum = 0, part = 0;
        for(int i = 0; i < m; i++) {
            add(sum, dp[n][0][i]);
            add(sum, dp[n][1][i]);
            add(part, dp[n][1][i]);
        }
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        if (s1 > s2) {
            return 0;
        }
        int64_t sum1, part1;
        int64_t sum2, part2;
        get(s1, evil, n, sum1, part1);
        get(s2, evil, n, sum2, part2);
        return (sum2+part1-sum1+MOD)%MOD;
    }
};
```

# 扫码关注，快乐加倍
![在这里插入图片描述](https://pic.leetcode-cn.com/6fada1c7d8b8afdc203786cf52a178bdb388edfaa210554d36031b7569b130c8.jpg)