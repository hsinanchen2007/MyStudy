```python []
from typing import List

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        quickSort(nums, 0, len(nums) - 1)
        return nums

def quickSort(nums: List[int], start: int, end: int):
    """经典快排
    核心思想：
    接受一个数组，挑一个数(pivot)，然后把比它小的那一摊数放在它的左边，把比它大的那一摊数放在它的右边，
    然后再对这个数左右两摊数递归的执行快排过程，直到子数组只剩一个数为止

    算法描述：
    挖坑填数，左边出现了一个坑，要从右边找到一个比基准小的数填入
    这样右边出现了一个坑，需要从左边找到一个比基准大的数填入...
    直到左右哨兵碰面

    Args:
        start include
        end include
    """

    # 递归调用的结束条件，返回
    if start >= end:
        return

    # 这里有两重含义：
    # 1）选取了基准（第一个元素）
    # 2）出现了第一个坑（把基准挖出来，而且这个坑是第一个位置）
    pivot = nums[start]

    # 左右两个哨兵分别往中间迫近，直到碰面，那么这个位置就是基准的坑了
    # 挖坑填数的过程需要不断地切换左右哨兵，所以这里以左右各一次的操作为一次循环
    left = start
    right = end
    while left < right:
        # 第一个坑在起始位置（左边），所以要从右边开始找
        while left < right and nums[right] >= pivot:
            right -= 1
        nums[left] = nums[right]

        while left < right and nums[left] <= pivot:
            left += 1
        nums[right] = nums[left]

    # 把基准填入坑中，再对基准两边的数组排序
    nums[left] = pivot
    quickSort(nums, start, left - 1)
    quickSort(nums, right + 1, end)    
    return
```
