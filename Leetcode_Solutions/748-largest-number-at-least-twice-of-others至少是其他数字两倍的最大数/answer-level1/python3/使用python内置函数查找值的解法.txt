### 解题思路
其实为了避免找错第二大的元素，还是直接把最小值找出来为妙。不选择排序算法，因为我这样遍历三遍还是O(n)的时间复杂度，数据多了先排序再找大概率是要更慢的。
比较值得一提的是这个`max(iterable, *, default=object, key=func)`的用法。

### 代码

```python3
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return -1
        if len(nums) == 1:
            return 0 if nums[0] != 0 else -1
        
        first_index = max(list(range(len(nums))), key=lambda i: nums[i]) #找到最大值的索引
        second_index = min(list(range(len(nums))), key=lambda i: nums[i]) #找到最小值的索引
        biggest = nums[first_index]
        if biggest < nums[second_index] * 2:
            return -1
        for i in range(len(nums)):
            if nums[i] > nums[second_index] and nums[i] < biggest:
                second_index = i
        return first_index if biggest >= 2 * nums[second_index] else - 1
```