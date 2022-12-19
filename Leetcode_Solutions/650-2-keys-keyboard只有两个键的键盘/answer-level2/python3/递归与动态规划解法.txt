# 解法一：暴力递归模拟
每一步可以选择是否copy_all，如果不选择copy_all，那么就只能粘贴上一次复制的结果。

```
class Solution1:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0

        self.minmun = 1 << 31
        def dfs(i, op, clipboard_len):
            if i > n:
                return
            elif i == n:
                self.minmun = min(self.minmun, op)
            else:
                # 不进行复制，粘贴上次结果
                dfs(i+clipboard_len, op + 1, clipboard_len)
                # 先copy_all再进行粘贴
                dfs(i+i, op + 2, i)
        
        dfs(1, 1, 1)
        return self.minmun
```

# 解法二：动态规划 （类素数筛法的思想）
注意到递归的过程中，本质上就是不同的clipboard_len递增后的结果，而dp[i]会取决于dp[j] (j < i)的最小值，也就符合动态规划中最优子结构的特性。

dp[i] = min(dp[i-clipboard_len] + 1) + 1  --> clipboard_len < i && i % clipboard_len == 0  

解释：min(dp[i-clipboard_len] + 1 <粘贴操作>) + 1 <初始的复制操作>

i % clipboard_len == 0 的要求是因为一旦选定clipboard_len，那么每次粘贴都会增加clipboard_len的长度，即 clipboard_len * n = i

时间复杂度O(n²)，空间复杂度O(n)

```
class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0

        dp = [i for i in range(n+1)]
        
        for i in range(1, n+1):
            base_op = dp[i] + 1 # 将i复制，以dp[i]为操作基数
            j = i + i
            while j <= n:
                base_op += 1
                dp[j] = min(dp[j], base_op)
                j += i

        # print(dp)
        return dp[-1]
```