```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2)
        temp = nums1
        temp.sort()
        if len(temp) % 2 == 0:
            mid = (temp[len(temp) // 2 - 1] + temp[len(temp) // 2]) / 2
        else:
            mid = temp[len(temp) // 2]

        return mid
```



