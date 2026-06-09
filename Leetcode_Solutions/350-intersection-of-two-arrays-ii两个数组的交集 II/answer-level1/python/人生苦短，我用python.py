解法：
直接使用遍历list的方法实现：
`class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        res = []
        k = 0
        for value in nums1:
            if value in nums2:
                res.append(value)
                nums2.remove(value)
        return res`