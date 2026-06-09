### 解题思路
参考的他人的解法，这个解法的关键是：
判断当前值是否为正，若正，继续加，否，从新开始更替。
每次都比较一下上次的最大值和当前值的大小。
### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_,cur_ = nums[0],nums[0]
        for n in nums[1:]:
            cur_ = cur_ + n if cur_ >0 else n
            max_ = max_ if max_ > cur_ else cur_ 
        return max_
```