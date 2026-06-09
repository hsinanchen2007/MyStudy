### 解题思路
在数组两边都立一一个1
把每段包起来
然后使用k不停迭代

### 代码

```python3
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums.insert(0,1)
        nums+=[1]
        n=len(nums)
        dp=[[0]*n for _ in range(n)]
        # 上面的都是初始化
        for l in range(2,n+1) :
            for i in range(n-l) :
                j=i+l
                dp[i][j]=float("-inf")
                for k in range(i+1,j) :
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j])
        return dp[0][-1]

```