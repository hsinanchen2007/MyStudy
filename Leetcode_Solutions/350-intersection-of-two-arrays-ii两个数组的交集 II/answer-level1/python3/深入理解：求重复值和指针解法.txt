思路1：数组的交集，也就是找出重复的值。对于重复值的问题，进而可以理解为相等值的问题，即在两个数据结构中有相同值，那么就要作比较，于是想到使用哈希表。（这里可以先将小数组存入哈希表，可以节省空间）

思路2：如果是已经排序的数组，那么可以使用双指针。同样可以达成比较相等值的目的。

以下为思路2code：



```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        i, j = 0, 0
        ls = []
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                i += 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                ls.append(nums1[i])
                i += 1
                j += 1
        return ls
```
