C艹: 4ms 8.7MB

Swift: 28ms 21.2MB

### 解题思路
看起来就需要遍历, 从左往右选择`K`个区间的时候, 每次计算都需要用到上一次选择都结果, 那么就是动态规划了

设第$k$个选择第区间为$[st, ed]$, 输入数组的长度为$len$

得到状态转移方程

$$
\left\{\begin{aligned}

dp[k][ed] &= max\{v_i | i \in [st, ed] \} \\
vi &= dp[k-1][i-1] + avg\{[i, ed] \} \\
st &\geq k \\
ed &= len - K + k

\end{aligned}\right.
$$

当然了, 上面的表达式只为说明思路

具体实现时需要对下标`+1`或`-1`

### 代码

```cpp
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        double dp[105][105];
        memset(dp, 0, sizeof dp);
        
        int sum = 0, cnt = 0, len = (int)A.size() - K + 1;
        for (int i = 0; i < len; ++i) {
            sum += A[i];
            dp[0][i] = (double)sum/++cnt;
        }
        
        for (int ik = 1; ik < K; ++ik) {
            len = (int)A.size() - K + ik + 1;
            for (int st = ik; st < len; ++st) {
                sum = cnt = 0;
                for (int ed = st; ed < len; ++ed) {
                    sum += A[ed];
                    auto avg = (double)sum/++cnt;
                    dp[ik][ed] = max(dp[ik][ed], dp[ik-1][st-1] + avg);
                }
            }
        }
        
        return dp[K-1][A.size()-1];
    }
};
```

```swift
class Solution {
    func largestSumOfAverages(_ A: [Int], _ K: Int) -> Double {
        var dp = Array.init(repeating: Array.init(repeating: 0.0, count: A.count), count: K)
        
        var sum = 0
        var cnt = 0
        var len = A.count - K + 0 + 1
        for i in 0..<len {
            sum += A[i]
            cnt += 1
            dp[0][i] = Double(sum)/Double(cnt)
        }
        
        for ik in 1..<K {
            len = A.count - K + ik + 1
            for st in ik..<len {// [st, ed]
                sum = 0
                cnt = 0
                for ed in st..<len {
                    sum += A[ed]
                    cnt += 1
                    let avg = Double(sum)/Double(cnt)
                    dp[ik][ed] = max(dp[ik][ed], dp[ik-1][st-1] + avg)
                }
            }
        }
        
        return dp[K - 1][A.count - 1]
    }
}
```