### 方法一：回溯
首先，我们考虑只有 `'.'` 的情况。这种情况会很简单：我们只需要从左到右依次判断 `s[i]` 和 `p[i]` 是否匹配。

```python
def isMatch(self,s:str, p:str) -> bool:
    if not p: return not s # 边界条件

    first_match = s and p[0] in {s[0],'.'} # 比较第一个字符是否匹配

    return first_match and self.isMatch(s[1:], p[1:])
```
如果有星号，它会出现在 `p[1]` 的位置，这时有两种情况：
- 星号代表匹配 0 个前面的元素。如 `'##'` 和 `a*##`，这时我们直接忽略 p 的 `a*`，比较 `##` 和 `##`；
- 星号代表匹配一个或多个前面的元素。如 `aaab` 和 `a*b`，这时我们将忽略 s 的第一个元素，比较 `aab` 和 `a*b`。
  
以上任一情况忽略掉元素进行比较时，剩下的如果匹配，我们认为 s 和 p 是匹配的。
### 代码
感谢 [@wulinlw](/u/wulinlw/) 对代码提出的修改建议~
```python []
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p: return not s
        # 第一个字母是否匹配
        first_match = bool(s and p[0] in {s[0],'.'})
        # 如果 p 第二个字母是 *
        if len(p) >= 2 and p[1] == "*":
            return self.isMatch(s, p[2:]) or \
            first_match and self.isMatch(s[1:], p)
        else:
            return first_match and self.isMatch(s[1:], p[1:])
```

### 方法二：动态规划
#### 状态

很容易想到，`dp[i][j]` 表示的状态是 s 的前 i 项和 p 的前 j 项是否匹配。
#### 转移方程
现在如果已知了 `dp[i-1][j-1]` 的状态，我们该如何确定 `dp[i][j]` 的状态呢？我们可以分三种情况讨论，其中，前两种情况考虑了所有能匹配的情况，剩下的就是不能匹配的情况了：

1. `s[i] == p[j] or p[j] == '.'`：比如 ab**b** 和 ab**b**，或者 ab**b** 和 ab. ，很容易得到 `dp[i][j] = dp[i-1][j-1] = True`。因为 ab 和 ab 是匹配的，如果后面分别加一个 b，或者 s 加一个 b 而 p 加一个 . ，仍然是匹配的。

2. `p[j] == '*'`：当 `p[j]` 为星号时，由于星号与前面的字符相关，因此我们比较星号前面的字符 `p[j-1]` 和 `s[i]` 的关系。根据星号前面的字符与 `s[i]` 是否相等，又可分为以下两种情况：

    - `p[j-1] != s[i]`：如果星号前一个字符匹配不上，星号匹配了 0 次，应忽略这两个字符，看 `p[j-2]` 和 `s[i]` 是否匹配。 这时 `dp[i][j] = dp[i][j-2]`。
    
    - `p[j-1] == s[i] or p[j-1] == '.'`:星号前面的字符可以与 `s[i]` 匹配，这种情况下，星号可能匹配了前面的字符的 0 个，也可能匹配了前面字符的多个，当匹配 0 个时，如 a**b** 和 ab**b***，或者 a**b** 和 ab.* ，这时我们需要去掉 p 中的 `b*` 或 `.*` 后进行比较，即 `dp[i][j] = dp[i][j-2]`；当匹配多个时，如 abb**b** 和 a**b***，或者 abb**b** 和 a.*，我们需要将 `s[i]` 前面的与 p 重新比较，即 `dp[i][j] = dp[i-1][j]`
3. 其他情况：以上两种情况把能匹配的都考虑全面了，所以其他情况为不匹配，即 `dp[i][j] = False`

#### 将以上进行归纳得到状态转移方程

$$dp(i)(j)=
\begin{cases}
dp(i-1)(j-1), & \text{s(i) = p(j) or p(j) = .}\\
dp(i)(j-2),& \text{p(j) = *, p(j-1) != s(i)}\\
dp(i-1)(j)or dp(i)(j-2),& \text{p(j) = *, p(j-1)=s(i) or p(j-1) = .}\\
False& \text{$else$}
\end{cases}$$

### 代码
```python []
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # 边界条件，考虑 s 或 p 分别为空的情况
        if not p: return not s
        if not s and len(p) == 1: return False

        m, n = len(s) + 1, len(p) + 1
        dp = [[False for _ in range(n)] for _ in range(m)]
        # 初始状态
        dp[0][0] = True
        dp[0][1] = False

        for c in range(2, n):
            j = c - 1
            if p[j] == '*':
                dp[0][c] = dp[0][c - 2]
        
        for r in range(1,m):
            i = r - 1
            for c in range(1, n):
                j = c - 1
                if s[i] == p[j] or p[j] == '.':
                    dp[r][c] = dp[r - 1][c - 1]
                elif p[j] == '*':       # ‘*’前面的字符匹配s[i] 或者为'.'
                    if p[j - 1] == s[i] or p[j - 1] == '.':
                        dp[r][c] = dp[r - 1][c] or dp[r][c - 2]
                    else:                       # ‘*’匹配了0次前面的字符
                        dp[r][c] = dp[r][c - 2] 
                else:
                    dp[r][c] = False
        return dp[m - 1][n - 1]
```