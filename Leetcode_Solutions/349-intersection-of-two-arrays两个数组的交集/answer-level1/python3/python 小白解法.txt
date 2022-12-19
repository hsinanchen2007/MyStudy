```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        list1 = []
        if len(nums1)>len(nums2):
            for i in nums2:
                try:
                    nums1.remove(i)
                    list1.append(i)
                except:
                    continue
            return set(list1)
        else:
            for i in nums1:
                try:
                    nums2.remove(i)
                    list1.append(i)
                except:
                    continue
            return set(list1)
```
