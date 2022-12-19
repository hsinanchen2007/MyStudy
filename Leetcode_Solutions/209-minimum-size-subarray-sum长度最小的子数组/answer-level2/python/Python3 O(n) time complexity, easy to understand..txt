```python3
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        if sum(nums) < s:
            return 0
        n = len(nums)
        l = r = 0
        sum_tmp = 0
        res = []
        for i in range(n):
            sum_tmp += nums[i]
            r = i
            if sum_tmp >= s:
                res.append(r-l+1)
            while sum_tmp >= s:
                for j in range(l,i+1):
                    sum_tmp -= nums[j]
                    if sum_tmp < s:
                        l = j+1
                        break
                    else:
                        l = j+1
                        res.append(r-l+1)
        return min(res)