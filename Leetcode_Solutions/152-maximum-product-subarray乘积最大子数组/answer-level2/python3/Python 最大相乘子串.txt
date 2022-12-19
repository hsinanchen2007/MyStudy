### 解题思路
动态规划
寻找包含每个元素子串的最大值与最小值

### 代码

```python3
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        length = len(nums)
        dp = []
        if length == 0:
            return 0
        if length == 1:
            return nums[0]
        minnum = nums[0]
        maxnum = nums[0]
        res = nums[0] 
        for i in range(1,length):
            if nums[i]<0:
                minnum,maxnum = maxnum,minnum
            minnum = min(minnum*nums[i],nums[i])
            maxnum = max(maxnum*nums[i],nums[i])
            res = max(res,maxnum)
        return res



            
```