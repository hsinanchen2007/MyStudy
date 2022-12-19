和丑数II一题的做法一样（丑数II地址：https://leetcode-cn.com/problems/ugly-number-ii/）
具体的可以看原作者

作者：powcai
链接：https://leetcode-cn.com/problems/ugly-number-ii/solution/dui-he-dong-tai-gui-hua-by-powcai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```
class Solution:
    def getKthMagicNumber(self, k: int) -> int:
        dp = [0] * k
        dp[0] = 1
        l_3 = 0
        l_5 = 0
        l_7 = 0
        for i in range(1, k):
            dp[i] = min(3 * dp[l_3], 5 * dp[l_5], 7 * dp[l_7])
            if dp[i] >= 3 * dp[l_3]:
                l_3 += 1
            if dp[i] >= 5 * dp[l_5]:
                l_5 += 1
            if dp[i] >= 7 * dp[l_7]:
                l_7 += 1
        return dp[-1]
```
