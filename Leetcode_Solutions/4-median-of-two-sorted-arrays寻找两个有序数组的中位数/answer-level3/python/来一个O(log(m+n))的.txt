```class Solution(object):
    def medofArray(self,array):
        return (array[len(array)/2] + array[(len(array)-1)/2])/2.0
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1)==0:
            return self.medofArray(nums2)
        elif len(nums2)==0:
            return self.medofArray(nums1)
        n = len(nums1)
        m = len(nums2)
        if n>m:
            return self.findMedianSortedArrays(nums2, nums1)
        L1,L2,R1,R2,c1,c2,lo=0,0,0,0,0,0,0
        hi = 2*n#因为虚拟加了#
        while lo<=hi:
            c1 = (lo+hi)/2
            c2 = m+n-c1#因为虚拟数组的中位数就是m+n
            if c1 == 0:
                L1 = -999999
            else:
                L1 = nums1[(c1-1)/2]
            if c1 == 2*n:
                R1 = 999999
            else:
                R1 = nums1[c1/2]
            if c2 == 0:
                L2 = -999999
            else:
                L2 = nums2[(c2-1)/2]
            if c2 == 2*m:
                R2 = 999999
            else:
                R2 = nums2[c2/2]
            if L1>R2:
                hi = c1 - 1
            elif L2>R1:
                lo = c1 + 1
            else:
                break
        return (max(L1,L2)+min(R1,R2))/2.0
```         
            
                
        