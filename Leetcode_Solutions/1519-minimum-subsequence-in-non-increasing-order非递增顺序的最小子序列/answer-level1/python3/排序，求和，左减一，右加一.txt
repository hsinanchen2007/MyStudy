```
class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
    #先排序，设第i个元素左边（包括i）求和为sum_L,右边为sum_R,根据题意，i逐渐右移，
    #每移一位sum_L加1，sum_R减1，直到某一个i时sum_L>sum_R，程序结束
        if len(nums) == 1:
            return nums
        else:
            r = sorted(nums)[::-1]
            sum_L, sum_R = 0, sum(r)
            for i in range(len(r)):
                sum_L += r[i]
                sum_R -= r[i]
                if sum_L > sum_R:
                    return r[:i+1]
```
