分析:涉及两个有序数组合并,设置i和j双指针,分别从两个数组的尾部向头部移动,并判断A[i]和B[j]的大小关系,从而保证最终数组有序,同时每次index从尾部向头部移动。
```python []
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        pos = m + n -1
        i = m -1
        j = n -1
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[pos] = nums1[i]
                pos -= 1
                i -= 1
            else:
                nums1[pos] = nums2[j]
                pos -= 1
                j -= 1
            
        while i >= 0:
            return
                
        while j >= 0:
            nums1[pos] = nums2[j]
            pos -= 1
            j -= 1