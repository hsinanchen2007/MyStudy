### 解题思路
此处撰写解题思路
执行用时 :
332 ms
, 在所有 Python 提交中击败了
100.00%
的用户
内存消耗 :
11.8 MB
, 在所有 Python 提交中击败了
100.00%
的用户
### 代码
这道题的思路就是如果你不知道怎么算 那你们就从1,2,3自己试试算一算 然后想一想
把所有可能的剪法都写出来 然后找到乘积最大值 
比如4 可以分解成2,2 1,3 不用再往下拆了 
3又可以分解成1,2， 1,1,1 n=3的时候最大值是2 

```python
class Solution(object):
    def cuttingRope(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 2:
            return 1
        if n == 3:
            return 2
        dp = [0]*(n+1)
        dp[2] = 2
        dp[3] = 3
        for j in range(4, n+1):
            for i in range(2, j/2+1):
                dp[j] = max(dp[i]*dp[j-i], dp[j])
        return dp[n] % 1000000007

```