**菜鸟第一次写题解，写的不好勿喷！！！**
由于之前做过[编辑距离](https://leetcode-cn.com/problems/distinct-subsequences/submissions/)这道题目，所以感觉也差不多，理解了编辑距离那道题，这道题也应该很好理解。
我没有那些大神们直接写出dp状态的定义，然后写代码，我是先画dp表格然后找到规律，在设计出dp方程的。
First：
-->审题
画出来dp表，手残式一步步填数据
![image.png](https://pic.leetcode-cn.com/b46ca4a4a4bcc08c90775ab0bf4c13e895b387874bbfd5f4c3efb4b4db82a6eb-image.png)
一步步找dp[i][j]、dp[i-1][j]、dp[i][j-1]、dp[i-1][j-1]之间的关系。
发现当s[i-1]=t[j-1]时，dp[i][j]=dp[i][j-1]+dp[i-1][j-1]，
**特别注意i=1时**，只有dp[i][j]=dp[i][j-1]+dp[i-1][j-1]这个方程才是最正确的，如果看i为其他值，很容易推导出错的dp方程,我就推导出dp[i][j]=max(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])+1
当s[i-1]!=t[j-1]时，很明显看出dp[i][j]=dp[i][j-1]。
Second：
-->总结dp方程并初始化数据
```
        row, col = len(t), len(s)
        dp = [[1] * (col + 1)] + [[0] * (col + 1) for _ in range(row)]
```
Finally:
-->写完整代码
```
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        '''
        dp[i][j]= dp[i][j-1] + dp[i - 1][j - 1] 
        '''
        row, col = len(t), len(s)
        dp = [[1] * (col + 1)] + [[0] * (col + 1) for _ in range(row)]

        for i in range(1, row + 1):
            for j in range(1, col + 1):
                if t[i - 1] == s[j - 1]:
                    dp[i][j] = dp[i][j-1] + dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i][j-1]
        return dp[-1][-1]
```
然后答案就成功了，AC！
![image.png](https://pic.leetcode-cn.com/29b5dcdd9f617164d46d1d00df695ba953d31323f471b3ce15f831883ae0d8eb-image.png)
