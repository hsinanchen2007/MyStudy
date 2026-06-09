## 堆(两个数组必须有序)
```
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        import heapq
        nums1[0:m+n] = list(heapq.merge(nums1[0:m], nums2))
```
## sorted
```
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1[0:m+n] = sorted(nums2 + nums1[0:m])
```
## 归并排序的merge
```
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i, j = m-1, n-1
        while (i >= 0 and j >= 0):
            if nums1[i] < nums2[j]:
                nums1[i+j+1] = nums2[j]
                j -= 1
            else:
                nums1[i+j+1] = nums1[i]
                i -= 1
        if j >= 0:
            nums1[0:j+1] = nums2[0:j+1]
```