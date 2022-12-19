```
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """

        res =[]
        if len(nums1)<len(nums2):
            nums3=nums1
            nums4 = nums2
        else:
            nums3 = nums2
            nums4 = nums1
        for _,item in enumerate(nums3):
            if item in nums4:
                ls.append(item)
                nums4.remove(item)
        return res
```
