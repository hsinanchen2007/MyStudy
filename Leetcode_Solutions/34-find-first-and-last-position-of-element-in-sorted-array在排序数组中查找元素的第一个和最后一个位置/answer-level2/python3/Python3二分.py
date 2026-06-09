### 解题思路
logn的基本都是二分法
注意相等的时候，前半部分有，后半部分也可能有，都要递归
### 代码

```python3
class Solution:
    def searchRange(self, nums, target):
        if nums == [] or target is None:
            return [-1, -1]
        length = len(nums)
        # 要求logn就意味着二分，加上是个升序
        # 有可能中间的前后也都有
        self.index_low = length
        self.index_high = -1

        def helper(low, high):
            if nums[low] <= target <= nums[high]:
                if target == nums[low] and low < self.index_low:
                    self.index_low = low
                if target == nums[high] and high > self.index_high:
                    self.index_high = high
                if low == high:
                    return
                mid = int((high + low) / 2)
                if target > nums[mid]:
                    helper(mid + 1, high)
                elif target < nums[mid]:
                    helper(low, mid - 1)
                else:
                    helper(low, mid)
                    helper(mid + 1, high)

        helper(0, length - 1)
        if self.index_low == length:
            return [-1,-1]
        else:
            return [self.index_low, self.index_high]
```