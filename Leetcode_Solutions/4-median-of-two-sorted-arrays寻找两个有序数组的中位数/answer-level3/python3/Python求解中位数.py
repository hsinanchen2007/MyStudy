class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n = len(nums1)
        m = len(nums2)
        left = (n + m + 1) // 2
        right = (n + m + 2) // 2
        return (self.getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + self.getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) / 2
    def getKth(self, nums1: List[int], start1: int, end1: int, nums2: List[int], start2: int, end2: int, k: int) -> int:
        len1 = end1 - start1 + 1
        len2 = end2 - start2 + 1
        #让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1 
        if len1 > len2:
            return self.getKth(nums2, start2, end2, nums1, start1, end1, k)
        #这里判断nums1数组是否为空，为空时直接取nums2数组即可
        if len1 == 0:
            return nums2[start2 + k - 1]
        if k == 1:
            return min(nums1[start1],nums2[start2])
        #为什么要减一？是因为在数组中索引是以0开始的
        i = start1 + min(len1, k // 2) - 1
        j = start2 + min(len2, k // 2) - 1
        #谁小抛弃谁的那一部分
        if nums1[i] > nums2[j]:
            #这个时候统一都降一个维度，求两个数组的第（k-抛弃的那部分的长度）
            return self.getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1))
        else:
            return self.getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1))