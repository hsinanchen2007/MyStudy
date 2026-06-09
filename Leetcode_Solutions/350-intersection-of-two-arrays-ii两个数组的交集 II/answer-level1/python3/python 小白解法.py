```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        len_nums1 = len(nums1)
        len_nums2 = len(nums2)
        list1 = []
        if len_nums1 > len_nums2:
            for i in nums2:
                try:
                    nums1.remove(i)
                    list1.append(i)
                except:
                    continue
            return list1
        else:
            for i in nums1:
                try:
                    nums2.remove(i)
                    list1.append(i)
                except:
                    continue
            return list1

    
```
