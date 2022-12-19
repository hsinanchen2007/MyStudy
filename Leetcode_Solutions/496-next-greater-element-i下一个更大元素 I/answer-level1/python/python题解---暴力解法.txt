```
class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        result = []
        T = 1
        for i in nums1:
            num = nums2.index(i)
            for j in range(num,len(nums2)):
                if nums2[j] > i:
                    T = 0
                    result.append(nums2[j])
                    break
            if T:
                result.append(-1)

            T = 1

        return result
                  
```
