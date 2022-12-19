```python
class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        # n houses, can be painted with one of the k colors
        # cost of each color is different.
        # no two adjacent houses have the same color.
        # Time complexity: O(NK)
        # Space complexity: O(K)    
        if costs == []: return 0
        row, col = len(costs), len(costs[0])
        dp = costs[0][:]
        for i in range(1, row):
            firVal, secVal = float('inf'), float('inf')
            for j in range(col):
                if dp[j] < firVal:
                    firVal, secVal = dp[j], firVal
                elif dp[j] < secVal:
                    secVal = dp[j]
            for j in range(col):
                if dp[j] != firVal: dp[j] = costs[i][j] + firVal
                else: dp[j] = costs[i][j] +  secVal
        return min(dp)	
```