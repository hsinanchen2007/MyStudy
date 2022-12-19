```
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        i, j, e1, e2 = 0, 0, len(nums1), len(nums2)
        lst = []
        while i < e1 and j < e2:
            if nums1[i] < nums2[j]:
                lst.append(nums1[i])
                i += 1
            else:
                lst.append(nums2[j])
                j += 1
        while i < e1:
            lst.append(nums1[i])
            i += 1
        while j < e2:
            lst.append(nums2[j])
            j += 1
        value, mod = divmod(len(lst), 2)
        if mod == 0:
            return float(lst[value - 1] + lst[value]) / 2
        else:
            return lst[value]
```
