### 解题思路
因为列表中只差0-n中的一个元素，所以直接排序后一一对比索引和数值。


### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums)):
            if nums[i]!=i:
                return i
        return len(nums)
```