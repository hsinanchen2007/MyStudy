### 解题思路
1. 先用集合去重
2. 然后去交集
3. 然后把set类型转换为list

### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        intersect_set = set(nums1) & set(nums2)
        return list(intersect_set)
```