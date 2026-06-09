

### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        myset=set(nums1)
        list=[]
        for i in nums2:
            if i in myset:
                list.append(i)
                myset.remove(i)
        return list
```