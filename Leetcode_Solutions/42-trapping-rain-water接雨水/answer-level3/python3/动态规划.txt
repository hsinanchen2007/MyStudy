当前存储水量与之前的关系，分为三种情况。请见代码
```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        lens = len(height)
        if lens<2:
            return(0)

        top = 0
        dp = [0]*lens

        for i in range(1,lens):
            if height[i]>height[top]:
                dp[i] = dp[top] + (i-top-1)*height[top] - sum(height[top+1:i])
                top = i
            else:
                if height[i]<=height[i-1]:
                    dp[i]=dp[i-1]
                else:
                    for k in range(i-1,-1,-1):
                        if height[k]>=height[i]:
                            dp[i] = dp[k] + (i-k-1)*height[i] - sum(height[k+1:i])
                            break

        return(dp[-1])
```

