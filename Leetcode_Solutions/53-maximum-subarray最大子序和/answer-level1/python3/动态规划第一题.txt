### 解题思路
这里Max的设置很重要不能是0，因为可能是负数
可以是负无穷或者第一个数
Sum很巧妙，有个置零的过程，但他是单独的与nums[i]分离了出来

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0
        Max = nums[0]
        Sum = 0
        i = 0
        while i < len(nums):
            Sum += nums[i]
            Max = max(Sum, Max)
            if Sum <= 0:
                Sum = 0
            i += 1
        return Max
            


```
### 解题思路
别人的简单方法
但是这样做改变了原列表

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            if nums[i-1] > 0:
                nums[i] += nums[i-1]
        return max(nums)
            
```
