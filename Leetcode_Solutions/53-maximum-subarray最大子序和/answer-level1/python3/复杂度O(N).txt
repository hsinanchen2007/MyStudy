### 解题思路
先取出一个中最大的
然后从第一个挨个往后加，若和小于0则重置sum为0

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maximum = nums[0]
        for item in nums:
            if item>maximum:
                maximum=item
        sumup = 0

        for i in range(len(nums)):
            sumup+=nums[i]
            if sumup<0:
                sumup=0
            elif sumup>maximum:
                maximum=sumup
        return maximum
```