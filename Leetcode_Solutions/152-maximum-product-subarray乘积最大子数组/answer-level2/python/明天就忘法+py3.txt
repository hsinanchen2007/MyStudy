### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        n=len(nums)
        mins=maxs=1
        ans=float("-inf")
        for i in range(n):
            # 当遍历到元素是负数时，最大值和最小值相反
            if nums[i]<0:
                maxs,mins=mins,maxs
            maxs=max(maxs*nums[i],nums[i])
            mins=min(mins*nums[i],nums[i])
            ans=max(ans,maxs)
        return ans
```