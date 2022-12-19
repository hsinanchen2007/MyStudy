class Solution:
    def nextGreaterElement(self, nums1, nums2):
        if not nums1: return []
        if not nums2: return [-1 for i in range(len(nums1))]
        d = {}
        for i, v in enumerate(nums1):
            d[v] = i
        sta = []
        res = [-1 for i in range(len(nums1))]
        for i, v in enumerate(nums2):
            n = len(sta) - 1
            while n >= 0:
                if v > sta[n]:
                    res[d[sta[n]]] = v
                    del sta[n]
                n -= 1
            if v in d.keys():
                sta.append(v)
        return res
s = Solution()
print(s.nextGreaterElement(nums1 = [2,4], nums2 = [1,2,3,4]))