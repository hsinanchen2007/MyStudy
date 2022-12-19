### 解题思路
本质：排序
快排、分治、插排、计数等等，无数种排序
申请指针保存当前变量，就能满足一次遍历，常数空间

### 代码

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort()
```