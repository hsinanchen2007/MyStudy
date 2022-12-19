### 解题思路
set函数可以直接获得不重复的部分

### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1 = set(nums1)
        nums2 = set(nums2)
        return nums1 & nums2

```