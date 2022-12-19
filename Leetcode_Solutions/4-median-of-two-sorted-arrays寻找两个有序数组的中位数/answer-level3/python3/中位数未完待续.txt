```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
#         本题看到复杂度log直接想到二分法，但是具体怎么分不知道，然后总想着合并两个数组，但是合并的话无论怎么合并不可能达到要求的复杂度，所以最后想不出看题解，给出了思路，用中位数的特点， 总是分成两部分，所以只需判断两个数组的切分点是否满足要求即可。切分的时候又min（m,n）种切法， 对这些切法进行二分遍历就可以。代码不是我写的，现在还屡不明白这个关系。
        n1 = len(nums1)
        n2 = len(nums2)
        if n1 > n2:
            return self.findMedianSortedArrays(nums2,nums1)
        k = (n1 + n2 + 1)//2
        left = 0
        right = n1
        while left < right :
            m1 = left +(right - left)//2
            m2 = k - m1
            if nums1[m1] < nums2[m2-1]:
                left = m1 + 1
            else:
                right = m1
        m1 = left
        m2 = k - m1 
        c1 = max(nums1[m1-1] if m1 > 0 else float("-inf"), nums2[m2-1] if m2 > 0 else float("-inf") )
        if (n1 + n2) % 2 == 1:
            return c1
        c2 = min(nums1[m1] if m1 < n1 else float("inf"), nums2[m2] if m2 <n2 else float("inf"))
        return (c1 + c2) / 2x
```
