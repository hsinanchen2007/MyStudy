class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        for i in arr:
            nums1 = arr.count(i)
            nums2 = len(arr) + 1
            per = nums1 / nums2
            if per > 0.25:
                return i