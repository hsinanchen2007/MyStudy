### 解题思路
刚开始BF一波，比较慢，开始优化
我已经在保存之前的max反复使用了
还是很慢，不知道还有哪儿可以优化
心累

### 代码

```python
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        if len(nums) == 0: return
        if k==1:return nums
        left, right, res = 0, k-1, []
        Max=max(nums[0:k])
        index=nums[0:k].index(Max)
        while right < len(nums):
            if index >=left:
                Max=max(Max,nums[right])
            else:
                Max=max(nums[left:right+1])
            index = nums[left:right + 1].index(Max)
            res.append(Max)
            left += 1
            right += 1
        return res
```