### 解题思路
二分法，如果需要使用二分法，必须有一个单调递增或者单调递减的序列。
很显然dp是这么一序列,dp[i]表示长度为i+1的子序列的最后一个数字大小
对于数组中的每一个num我们需要在dp中找到第一个大于它的数字的位置（即所有大于它的数字中，最小的那个）
然后更新它。如果之前没有出现过大于它的数字，那么res+1

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n=len(nums)
        res=0
        dp=[0]*n
        for num in nums:
            i,j=0,res
            while i<j:
                mid=(i+j)//2
                if dp[mid]>=num:
                    j=mid
                else:
                    i=mid+1
            dp[i]=num
            if res==j:
                res+=1
        return res


```