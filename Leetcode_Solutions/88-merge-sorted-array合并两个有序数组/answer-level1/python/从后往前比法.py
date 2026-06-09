class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        max_index = len(nums1) - 1
        for i in range(len(nums2)-1, -1, -1):
            while max_index >= 0:
                if max_index - i - 1 >= 0 and nums2[i] <= nums1[max_index - i - 1]:
                    nums1[max_index] = nums1[max_index - i - 1]
                    nums1[max_index - i - 1] = 0
                    max_index -= 1
                else:
                    nums1[max_index] = nums2[i]
                    max_index -= 1
                    break
        return nums1