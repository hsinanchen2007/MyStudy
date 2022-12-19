### 解题思路
直接把两个列表合并，然后排序，取中间值

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        num3=nums1+nums2
        num3.sort()
        l=len(num3)
        i=l//2
        if(l%2==0):
            return (num3[i]+num3[i-1])/2
        else:
            return num3[i]
```