```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []

        for i in range(len(nums1)):
            for j in range(len(nums2)):
                if(nums1[i] == nums2[j]):
                    result.append(nums2[j])
                    nums2 = nums2[:j]+nums2[j+1:]
                    break
        return result
```
