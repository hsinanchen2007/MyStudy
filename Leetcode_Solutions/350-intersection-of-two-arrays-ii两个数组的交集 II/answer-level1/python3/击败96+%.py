### 解题思路
此处撰写解题思路
要熟练运用collection.Counter模块啊！

### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return sorted((collections.Counter(nums2)&collections.Counter(nums1)).elements())

```