```
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d = dict()
        for idx, val in enumerate(nums2):
            d[val] = idx
        
        res = []
        for item in nums1:
            index = d[item]
            for elem in nums2[index:]:
                if elem > item:
                    res.append(elem)
                    break
                elif elem == nums2[-1]:
                    res.append(-1)
        return res
```
