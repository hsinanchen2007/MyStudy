思路:遍历nums2，将nums2中的元素依次覆盖nums1后面的0，然后将nums1排序
```
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        j = -1
        for i in range(len(nums2)):
            nums1[j] = nums2[i]
            j -=1

        nums1.sort()
```
