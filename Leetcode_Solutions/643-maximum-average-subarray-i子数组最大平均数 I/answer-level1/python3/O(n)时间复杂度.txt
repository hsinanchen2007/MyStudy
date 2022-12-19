### 解题思路
空间复杂度还可以优化！

### 代码
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        size=len(nums)
        if size<=0 or size<k:
            return 0

        dp=[0]*size
        i=0
        dp[k-1]=sum(nums[:k])
        j=k
        while j<size:
            dp[j]=dp[j-1]-nums[i]+nums[j]
            j+=1
            i+=1
        return max(dp[k-1:])/k
```