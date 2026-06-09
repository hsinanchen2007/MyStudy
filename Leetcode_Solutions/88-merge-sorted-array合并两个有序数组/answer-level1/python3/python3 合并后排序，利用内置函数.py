### 解题思路
利用python内置函数实现两个有序数组合并排序：
del list[n] 删除多余元素 
list.extend(list2) 将 list2 合并到 list 中
list.sort() 对 list 排序，sort排序为永久性排序

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        del nums1[m:]
        nums1.extend(nums2)
        nums1.sort()
```