```
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        length = len(arr)
        dp = [1 for _ in range(length)]
        for i in range(1, length):
            dp[i] = dp[i - 1] + 1
            for j in range(i):
                if arr[j] > arr[i]:
                    dp[i] = min(dp[j:i])
                    break
        return dp[-1]
```
