####  方法一：动态规划（使用三维数组）
**算法：**
定义 `dp[x][i][j]` 为子串 `S[i...j]` 拥有不同回文子字符串的答案，且 `S[i] == S[j] == 'a'+x`。由于字符串只包含四个字符 `a, b, c, d`，因此 `0 <= x < 4`。dp 的公式如下：
- 如果 `S[i] != 'a'+x`，则 `dp[x][i][j] = dp[x][i+1][j]`
- 如果 `S[j] != 'a'+x`，则 `dp[x][i][j] = dp[x][i][j-1]`
- 如果 `S[i] == S[j] == 'a'+x`，则 `dp[x][i][j] = 2 + dp[0][i+1][j-1] + dp[1][i+1][j-1] + dp[2][i+1][j-1] + dp[3][i+1][j-1]`。当第一个和最后一个字符相同时，我们需要计算子串 `S[i+1][j-1]` 中所有不同的回文（a、b、c、d 中的每一个）加上第一个和最后一个字符的两个回文。
设 `n` 为字符串 `S` 的长度，则最终的答案为 `dp[0][0][n-1] + dp[1][0][n-1] + dp[2][0][n-1] + dp[3][0][n-1]
mod 1000000007`


```Java [ ]
class Solution {
public:
  int countPalindromicSubsequences(string S) {
    int n = S.size();
    int mod = 1000000007;
    auto dp_ptr = new vector<vector<vector<int>>>(4, vector<vector<int>>(n, vector<int>(n)));
    auto& dp = *dp_ptr;

    for (int i = n-1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        for (int k = 0; k < 4; ++k) {
          char c = 'a' + k;
          if (j == i) {
            if (S[i] == c) dp[k][i][j] = 1;
            else dp[k][i][j] = 0;
          } else { // j > i
            if (S[i] != c) dp[k][i][j] = dp[k][i+1][j];
            else if (S[j] != c) dp[k][i][j] = dp[k][i][j-1];
            else { // S[i] == S[j] == c
              if (j == i+1) dp[k][i][j] = 2; // "aa" : {"a", "aa"}
              else { // length is > 2
                dp[k][i][j] = 2;
                for (int m = 0; m < 4; ++m) { // count each one within subwindows [i+1][j-1]
                  dp[k][i][j] += dp[m][i+1][j-1];
                  dp[k][i][j] %= mod;
                }
              }
            }
          }
        }
      }
    }

    int ans = 0;
    for (int k = 0; k < 4; ++k) {
      ans += dp[k][0][n-1];
      ans %= mod;
    }

    return ans;
  }
};
```

```Java [ ] 
class Solution {
  public int countPalindromicSubsequences(String S) {
    int n = S.length();
    int mod = 1000000007;
    int[][][] dp = new int[4][n][n];

    for (int i = n-1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        for (int k = 0; k < 4; ++k) {
          char c = (char) ('a' + k);
          if (j == i) {
            if (S.charAt(i) == c) dp[k][i][j] = 1;
            else dp[k][i][j] = 0;
          } else { // j > i
            if (S.charAt(i) != c) dp[k][i][j] = dp[k][i+1][j];
            else if (S.charAt(j) != c) dp[k][i][j] = dp[k][i][j-1];
            else { // S[i] == S[j] == c
              if (j == i+1) dp[k][i][j] = 2; // "aa" : {"a", "aa"}
              else { // length is > 2
                dp[k][i][j] = 2;
                for (int m = 0; m < 4; ++m) { // count each one within subwindows [i+1][j-1]
                  dp[k][i][j] += dp[m][i+1][j-1];
                  dp[k][i][j] %= mod;
                }
              }
            }
          }
        }
      }
    }

    int ans = 0;
    for (int k = 0; k < 4; ++k) {
      ans += dp[k][0][n-1];
      ans %= mod;
    }

    return ans;
  }
}
```

```Python [ ]
class Solution:
  def countPalindromicSubsequences(self, S):
    n = len(S)
    mod = 1000000007
    dp = [[[0 for _ in range(n)] for _ in range(n)] for _ in range(4)]

    for i in range(n-1, -1, -1):
      for j in range(i, n):
        for k in range(4):
          c = chr(ord('a') + k)
          if j == i:
            if S[i] == c: dp[k][i][j] = 1
            else: dp[k][i][j] = 0
          else: # j > i
            if S[i] != c: dp[k][i][j] = dp[k][i+1][j]
            elif S[j] != c: dp[k][i][j] = dp[k][i][j-1]
            else: # S[i] == S[j] == c
              if j == i+1: dp[k][i][j] = 2 # "aa" : {"a", "aa"}
              else: # length is > 2
                dp[k][i][j] = 2
                for m in range(4): # count each one within subwindows [i+1][j-1]
                  dp[k][i][j] += dp[m][i+1][j-1]
                  dp[k][i][j] %= mod

    ans = 0
    for k in range(4):
      ans += dp[k][0][n-1]
      ans %= mod

    return ans
```

**示例演练**
- 这是一个很难解决的问题且彻底理解它的解决办法也很有挑战性。理解上述方法的最好方法是演示一些简单的例子来帮助理解。
- 让我们先看看填写 dp 表时使用的策略，然后通过一个具体的示例来了解它是如何工作的。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20191101223712782.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTEzOTUwNQ==,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191101223738281.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTEzOTUwNQ==,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191101223748279.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTEzOTUwNQ==,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191101223757260.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTEzOTUwNQ==,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191101223806677.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTEzOTUwNQ==,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191101223817974.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTEzOTUwNQ==,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191101223827759.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTEzOTUwNQ==,size_16,color_FFFFFF,t_70)

**复杂度分析**

* 时间复杂度：$O(N^2)$ 其中 $N$ 是字符串 $S$ 的长度。填写 dp 表需要平方的时间
* 空间复杂度： $O(N^2)$ 其中 $N$ 是字符串 $S$ 的长度，相当于使用了常数个数的二维空间。

注意，我们上述分析中忽略了的常数因子 $4$。

**总结**
回过头来看，这个问题表明动态规划非常适合用来解决重叠的子问题。通过练习更多类似的问题，我们可以建立这种直觉。

####  方法二：动态规划（使用二维数组）
几乎每一个回文字符串都将采用这四种形式之一：`a_a`、`b_b`、`c_c` 或 `d_d`，其中 `_` 表示零个或多个字符的回文字符串。（其他回文字符串只有 `a`、`b`、`c`、`d` 和空字符串）

让我们试着数一数 `a_a` 形式的回文（其他形式是类似的）。我们应该取第一个和最后一个 `a`，然后计算所有可以在其间形成的回文字符串。

**算法：**
- 定义 `dp(i, j)` 是字符串 `T = S[i], S[i+1], ..., S[j]` 中的回文字符串个数（包括回文 `''`）。要在 `T` 中计算 `a_a` 形式的回文数，我们需要知道该字符串中 `'a'` 第一次和最后一次出现的位置。定义 `next[i][0]` 将是 `S[i:]` 中 `'a'` 的下一次出现的位置，`next[i][1]` 将是 `S[i:]` 中 `'b'` 下一次出现的位置，依此类推。
- 此外，我们还需要知道 `T` 中唯一字母的数目，才能计算出单个字母的回文数。我们可以用 `next` 得到的信息来推断它：如果 `next[i][0]` 在区间 `[i，j]` 中，那么 `'a'` 出现在 `T` 中，以此类推。
- 由于许多状态 `dp(i, j)` 不需要计算，最直接的方法是自顶向下变化的动态规划。

```Python [ ]
class Solution(object):
    def countPalindromicSubsequences(self, S):
        N = len(S)
        A = [ord(c) - ord('a') for c in S]
        prv = [None] * N
        nxt = [None] * N

        last = [None] * 4
        for i in xrange(N):
            last[A[i]] = i
            prv[i] = tuple(last)

        last = [None] * 4
        for i in xrange(N-1, -1, -1):
            last[A[i]] = i
            nxt[i] = tuple(last)

        MOD = 10**9 + 7
        memo = [[None] * N for _ in xrange(N)]
        def dp(i, j):
            if memo[i][j] is not None:
                return memo[i][j]
            ans = 1
            if i <= j:
                for x in xrange(4):
                    i0 = nxt[i][x]
                    j0 = prv[j][x]
                    if i <= i0 <= j:
                        ans += 1
                    if None < i0 < j0:
                        ans += dp(i0+1, j0-1)
            ans %= MOD
            memo[i][j] = ans
            return ans

        return dp(0, N-1) - 1
```

```Java [ ]
class Solution {
    int[][] memo, prv, nxt;
    byte[] A;
    int MOD = 1_000_000_007;

    public int countPalindromicSubsequences(String S) {
        int N = S.length();
        prv = new int[N][4];
        nxt = new int[N][4];
        memo = new int[N][N];
        for (int[] row: prv) Arrays.fill(row, -1);
        for (int[] row: nxt) Arrays.fill(row, -1);

        A = new byte[N];
        int ix = 0;
        for (char c: S.toCharArray()) {
            A[ix++] = (byte) (c - 'a');
        }

        int[] last = new int[4];
        Arrays.fill(last, -1);
        for (int i = 0; i < N; ++i) {
            last[A[i]] = i;
            for (int k = 0; k < 4; ++k)
                prv[i][k] = last[k];
        }

        Arrays.fill(last, -1);
        for (int i = N-1; i >= 0; --i) {
            last[A[i]] = i;
            for (int k = 0; k < 4; ++k)
                nxt[i][k] = last[k];
        }

        return dp(0, N-1) - 1;
    }

    public int dp(int i, int j) {
        if (memo[i][j] > 0) return memo[i][j];
        int ans = 1;
        if (i <= j) {
            for (int k = 0; k < 4; ++k) {
                int i0 = nxt[i][k];
                int j0 = prv[j][k];
                if (i <= i0 && i0 <= j) ans++;
                if (-1 < i0 && i0 < j0) ans += dp(i0 + 1, j0 - 1);
                if (ans >= MOD) ans -= MOD;
            }
        }
        memo[i][j] = ans;
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$ 其中 $N$ 是字符串 $S$ 的长度。我们对 `prv` 和 `nxt` 的计算是在 $O(N)$ 时间内完成的，其中 `dp` 有最多 $N^2$ 的状态，对每个状态的计算需要 $O(1)$ 的时间
* 空间复杂度：$O(N^2)$，`memo` 使用的空间。