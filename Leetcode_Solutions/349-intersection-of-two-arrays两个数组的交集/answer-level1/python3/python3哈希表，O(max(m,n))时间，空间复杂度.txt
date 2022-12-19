### 解题思路
写完发现都是集合，为什么我第一反应就哈希表...

### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        hax1 =  {}
        hax2 = {}
        for i in nums1:
            hax1[i] = 1
        for i in nums2:
            hax2[i] = 1            
        for i in hax2.keys():
            if i in hax1:
                res.append(i)
        return res
```