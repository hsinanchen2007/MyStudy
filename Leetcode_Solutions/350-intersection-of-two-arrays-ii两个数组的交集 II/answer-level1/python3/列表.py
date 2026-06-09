### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        l = []
        for n1 in nums1:
            if n1 in nums2:
                nums2.remove(n1)
                l.append(n1)
        return l
```