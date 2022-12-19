### 解题思路
直接暴力解决，for循环，然后单独处理target大于列表最大元素的情况，搞定

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:return 0
        for i in range(0,len(nums)):
            if nums[len(nums)-1] < target:
                return len(nums)
                break
            elif nums[i] >= target:
                return i
                break
```