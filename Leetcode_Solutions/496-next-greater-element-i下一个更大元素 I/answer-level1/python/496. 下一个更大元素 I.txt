例子说明的有误导

```
class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        L = []
        nums2_len = len(nums2) - 1
        for val1 in nums1:
            default = -1
            for val2 in nums2[nums2.index(val1):]:
                if val2 > val1:
                    default = val2
                    break
            L.append(default)
        return L

```
