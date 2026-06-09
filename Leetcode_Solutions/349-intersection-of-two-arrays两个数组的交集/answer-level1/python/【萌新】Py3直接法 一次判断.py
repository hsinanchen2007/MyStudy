### 解题思路
遍历列表1 如果在列表2中且不在新列表中就加入新列表

### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res=[]
        for i in nums1:
            if i in nums2 and i not in res:
                res.append(i)
        
        return res
```