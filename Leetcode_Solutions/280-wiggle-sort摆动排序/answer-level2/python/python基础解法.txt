### 解题思路
1. 一次遍历，交换元素
2. 暴力法，先排序后交换元素

### 代码

```python3
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # for i in range(len(nums)-1):
        #     if i % 2 == 0 and nums[i] > nums[i+1]:
        #         nums[i], nums[i+1] = nums[i+1], nums[i]
        #     if i % 2 == 1 and nums[i] < nums[i+1]:
        #         nums[i], nums[i+1] = nums[i+1], nums[i]
        nums.sort()
        for i in range(1,len(nums)- 1, 2):
            nums[i], nums[i+1] = nums[i+1], nums[i]
```