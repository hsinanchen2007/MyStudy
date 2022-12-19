```
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        len=m+n
        i=0
        for j in range(m,len):
            nums1[j]=nums2[i]
            i=i+1
        nums1.sort()
        return nums1
```

