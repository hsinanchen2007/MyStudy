### 解题思路
此处撰写解题思路
1.去重
2.求交集
### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1_set=set(nums1)
        nums2_set=set(nums2)
        return list(nums1_set&nums2_set)
```