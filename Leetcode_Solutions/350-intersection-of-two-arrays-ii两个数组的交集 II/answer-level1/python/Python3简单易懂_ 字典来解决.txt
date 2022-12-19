### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d = {}
        for e in nums1:
            d[e] = d.get(e, 0) + 1
        res = []
        for e in nums2:
            if d.get(e, 0) > 0:
                d[e] -= 1
                res.append(e)
        return res
            
```