### 解题思路
合并数组再排序之后直接返回结果

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        new_ = nums1+nums2
        new_.sort()
        l = len(new_)
        if l%2:
            return float(new_[int((l+1)/2)-1]) 
        else:
            return 1/2*float((new_[int(l/2)]+new_[int((l/2))-1]))
```