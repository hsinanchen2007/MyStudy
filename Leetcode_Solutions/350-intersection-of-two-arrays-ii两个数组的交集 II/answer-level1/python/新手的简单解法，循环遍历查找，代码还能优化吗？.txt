class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        l1=len(nums1)
        l2=len(nums2)
        solution=[]
        if l1>l2:
            nums3=nums1
            nums1=nums2
            nums2=nums3
        for num in nums1:
            if num in nums2:
                solution.append(num)
                nums2.remove(num)  
        return solution