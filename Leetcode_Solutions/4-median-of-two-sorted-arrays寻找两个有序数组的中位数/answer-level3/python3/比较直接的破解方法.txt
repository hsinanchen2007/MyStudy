class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        l=nums1+nums2
        l.sort()
        if len(l)%2==0:
            return (l[int(len(l)/2)]+l[int(len(l)/2-1)])/2
        else:
            return l[int((len(l)-1)/2)]