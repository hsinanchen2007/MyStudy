### 解题思路
python 集合基本操作

### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        #集合，第一就想到不重复性，唯一性
        #所以第一步去重
        set_nums1 = set(nums1)
        set_nums2 = set(nums2)
        return set_nums1&set_nums2
```