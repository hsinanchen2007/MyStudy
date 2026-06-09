class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        from collections import Counter
        nums1_dict = Counter(nums1)
        res = []
        for num in nums2:
            if nums1_dict[num] > 0:
                # 说明找到了一个元素即在num1也在nums2
                res.append(num)
                nums1_dict[num] -= 1
        return res        