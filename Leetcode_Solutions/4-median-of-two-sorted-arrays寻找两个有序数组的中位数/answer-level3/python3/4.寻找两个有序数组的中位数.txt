```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        sum_list = nums1 + nums2
        sum_list.sort()
        
        len_list = len(sum_list)
        middle_index = int(len_list/2)
        
        middle_num = (sum_list[middle_index-1] + sum_list[middle_index])/2 if len_list%2==0 else sum_list[middle_index]

        return middle_num
```
