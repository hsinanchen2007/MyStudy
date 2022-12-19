class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        # 减去交集剩下的部分=s3=s1-s2
        s1, s2 = set(nums1), set(nums2)
        s3 = s1 - s2
        return list(s1-s3)