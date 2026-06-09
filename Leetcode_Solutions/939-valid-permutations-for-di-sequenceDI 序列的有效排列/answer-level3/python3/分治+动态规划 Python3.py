**思路：**

1. 分治算法+区间动态规划

   区间动态规划，令 `f(i,j)` 表示 `j−i+1` 个数的排列，满足区间 `S(i,j−1)` 的方案数；

   我们每次枚举最大数字的位置，其中可以放在区间开头，放在区间末尾，或者放在区间中某个位置；

   放在区间开头时，若 `S(i) == 'D'`，则我们转移 `f(i,j) += f(i+1,j)`；

   放在区间末尾时，若 `S(j - 1) == 'I'`，则我们转移 `f(i,j) += f(i,j−1)`；

   否则，枚举位置 `k in [i+1,j−1]`，将区间分为两部分，若`S(k - 1) == 'I'` 并且 `S(k) == 'D'`，则 根据乘法原理和组合数计算，转移 `f(i,j) += C(len−1,k−i) ∗ f(i,k−1) ∗ f(k+1,j)`，其中 `C(len−1,k−i)` 为组合数，这里代表从 `len−1` 个数中选择 `k−i` 个数的方案数。

2. 顺序动态规划+状态压缩

   `dp[i][j]`代表符合`DI`规则的前`i`个位置的由`j`结尾的数组的数目，那么可以求得递推公式：

   `DI`字符串在`i`位置是`'D'`：`dp[i][j] += dp[i-1][k] for k >= j`

   `DI`字符串在`i`位置是`'I'`：`dp[i][j] += dp[i-1][k] for k < j`

   由递推公式可以看出我们需要的是`dp[i][0],dp[i][1],...,dp[i][j]`的和，因此我们改变`dp[i][j]`的意义，`dp[i][j]`此时代表前述的和，做到这一点只需要在代码中添加`dp[i][j]+=dp[i][j-1]`

时间复杂度$O(N^2)$

空间复杂度$O(N^2)$

**代码：**

区间动态规划

```python
class Solution:
    def __init__(self):
        self.memo = {'':1, 'D':1, 'I':1} # 记忆化
    def numPermsDISequence(self, S):
        """
        :type S: str
        :rtype: int
        """
        # 分治 + 动态规划
        # time complexity: O(n^2)
        n = len(S)
        if S in self.memo:
            return self.memo[S]
        CONST = 10**9 + 7
        ans = 0
        if S[0] == "D": # 最大数出现在最左端
            ans += self.numPermsDISequence(S[1:])
        if S[-1] == "I": # 最大数出现在最右端
            ans += self.numPermsDISequence(S[:-1])
        comb = 1 # 组合数
        for i in range(n-1):
            comb = comb*(n-i)//(i+1)
            if S[i:i+2] == "ID": # 最大数出现在中间
                temp1, temp2 = S[:i], S[i+2:]
                ans += self.numPermsDISequence(temp1)*self.numPermsDISequence(temp2)*comb
                ans %= CONST
        self.memo[S] = ans
        return ans
```

顺序动态规划

```python
class Solution:
    def numPermsDISequence(self, S):
        """
        :type S: str
        :rtype: int
        """
        mod = 10 ** 9 + 7
        n = len(S)
        dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            for j in range(i + 1):
                if S[i - 1] == 'D':
                    for k in range(j, i + 1):
                        # here start from j, regard as swap value j with i, then shift all values no larger than j
                        dp[i][j] += dp[i - 1][k]
                        dp[i][j] %= mod
                else:
                    for k in range(0, j):
                        dp[i][j] += dp[i - 1][k]
                        dp[i][j] %= mod
        #print(dp)
        return sum(dp[n]) % mod
```

状态压缩写法

```python
class Solution:
    def numPermsDISequence(self, S):
        """
        :type S: str
        :rtype: int
        """
        dp = [1] * (len(S) + 1)
        for c in S:
            if c == "I":
                dp = dp[:-1]
                for i in range(1, len(dp)):
                    dp[i] += dp[i - 1]
            else:
                dp = dp[1:]
                for i in range(len(dp) - 1)[::-1]:
                    dp[i] += dp[i + 1]
        return dp[0] % (10**9 + 7)
```