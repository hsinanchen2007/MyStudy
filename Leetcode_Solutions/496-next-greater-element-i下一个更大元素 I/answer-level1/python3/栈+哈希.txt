class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if not nums2:
            return []
        d  = {}
        d[nums2[-1]] = -1
        ans = []
        stack = [nums2[-1]]
        for i in range(len(nums2) - 2, -1, -1):
            while stack and stack[-1] <= nums2[i]:
                stack.pop()
            if not stack:
                d[nums2[i]] = -1
            else:
                d[nums2[i]] = stack[-1]
            stack.append(nums2[i])
        for num in nums1:
            ans.append(d[num])
        return ans