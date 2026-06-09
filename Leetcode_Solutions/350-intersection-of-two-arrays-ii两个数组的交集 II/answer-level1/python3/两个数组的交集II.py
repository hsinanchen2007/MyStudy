class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        jiao = []
        for i in set(nums1):
            if i in nums2:
                num = min(nums2.count(i),nums1.count(i))
                for j in range(num):
                    jiao.append(i)
        return jiao