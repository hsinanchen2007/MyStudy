### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMin(self, nums: List[int]) -> int:
        len_nums = len(nums)
        # 递归出口
        if len_nums <= 2:
            return min(nums)
        mid = len_nums // 2
        # 旋转点小于mid，最小值必然落在mid左侧
        if nums[mid] < nums[len_nums-1]:
            return self.findMin(nums[:mid+1])
        # 旋转点>=mid，最小值必然落在mid上或者mid右侧
        else:
            return self.findMin(nums[mid:])
```