class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        nums1 = 0
        nums2 = 0
        for i in range(len(A)-1):
            if A[i] < A[i+1]:
                nums1 += 1
            elif A[i] > A[i+1]:
                nums2 += 1
            else:
                nums1 += 1
                nums2 += 1
        return (nums1 == (len(A) - 1) or nums2 == (len(A) - 1))