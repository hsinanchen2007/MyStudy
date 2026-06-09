class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.append(nums2.pop())
        nums1.sort()
        length=len(nums1)
        if length%2==0:
            return (nums1[length//2]+nums1[length//2-1])/2.0
        if length%2!=0:
            return nums1[int(length//2)]
