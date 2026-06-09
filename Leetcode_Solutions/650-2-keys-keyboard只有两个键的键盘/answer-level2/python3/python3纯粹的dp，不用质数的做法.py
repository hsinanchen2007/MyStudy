```
class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0
        dp = [[n]*n for _ in range(n)]
        #dp[i][j] 记事本上有i+1个A，粘贴板上有j+1个A
        dp[0][0] = 1
        for i in range(1,n):
            for j in range(i):
                dp[i][j] = dp[i-j-1][j] + 1
            dp[i][i] = min(dp[i]) + 1
        return dp[-1][-1] -1
```

友情提示：该算法运气好可以过，，，运气不好就会差几个用例，，，不过dp的思想在这里，哈哈
![截图.PNG](https://pic.leetcode-cn.com/7b3d407947a1f0555468b145f481ce0ff9030074f12070ebfa79bf7f695cdf7f-%E6%88%AA%E5%9B%BE.PNG)


