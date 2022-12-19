### 解题思路
第一眼想用递归,后来一看还要取余感觉不对,数肯定很大

### 代码

```python
class Solution(object):
    def numRollsToTarget(self, d, f, target):
        """
        :type d: int
        :type f: int
        :type target: int
        :rtype: int
        """
        #一共的情况这么多,普通递归很有可能超时
        #尝试动态规划,知道前n-1个骰子,判断第n个骰子
        #dp[i][j]表示i个骰子凑 j的和的情况个数
        #dp[i][j]=(dp[i-1][j-1] +dp[i-1][j-2]+.....+dp[i-1][j-f])=  sum(dp[i-1][j-f:j])
        dp=[[0 for _ in range(target+1)] for _ in range(d)]
        dp[0][1:f+1]=[1 for i in range(1,f+1)]
        for i in range(1,d):
            for j in range(target+1):#j=1...6
                dp[i][j]=sum(dp[i-1][max(j-f,0):min(j,target+1)])
        # for i in dp:
        #     print i
        return dp[d-1][target]%(10**9+7)

```