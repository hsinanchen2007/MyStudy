dp[i][0]  表示i节点没有删除过节点的最大值
dp[i][1]  表示i节点删除过过节点的最大值

递归公式
dp[i][0] = max( arr[i], dp[i-1][0] + arr[i])  #没删除过的，是arr[i]或者 dp[i-1][0]+arr[i] 取大值
dp[i][1]=max(dp[i-1][0],dp[i-1][1]+arr[i])   #删除过的dp[i-1]加上本身 和  没有删除过的p[i-1]删除dp[i] 取大值

先求解出每个节点的最大值，在返回其中最大的
O(n)




```
class Solution(object):
    def maximumSum(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        res=arr[0]
        l=len(arr)
        dp= [[0 for i in range(2)] for i in range(l)] 
        #dp[i] 代表i为结尾的子数组
        dp[0][0]=arr[0]  # di[i][0]  没有删除过的
        dp[0][1]=0       # dp[i][1]  删除过的元素的
        for i in range(1,l):
            dp[i][0] = max( arr[i], dp[i-1][0] + arr[i])  #没删除过的，是arr[i]或者 dp[i-1][0]+arr[i] 取大值
            #删除过的分2种，dp[i-1]删除过加上本身 和 没有删除过删除自身  
            dp[i][1]=max(dp[i-1][0],dp[i-1][1]+arr[i])
            #最大值赋值给res
            res=max(res,dp[i][0],dp[i][1])
        return res
```

                   