class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if nums == []:
            return(0)
        ans = []
        ln = len(nums)
        for a in range(ln):
            ans.append(1)
            for b in range(a):
                if nums[b] < nums[a] and ans[b] >= ans[a]:
                    ans[a] = ans[b] + 1
        return(max(ans))