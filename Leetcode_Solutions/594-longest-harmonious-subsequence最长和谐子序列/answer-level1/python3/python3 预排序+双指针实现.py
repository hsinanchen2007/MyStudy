### 解题思路
首先将原数组排序，得到递增数组；
然后遍历一遍数组，利用双指针实现类似滑动窗口的功能

时间复杂度：O(nlog(n))
空间复杂度：O(n)

### 代码

```python3
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        nums.sort()
        left=0
        res=0
        for right in range(len(nums)):
            while nums[right]-nums[left]>1:
                left+=1
            if nums[right]-nums[left]==1:
                res=max(res,right-left+1)
        return res
```