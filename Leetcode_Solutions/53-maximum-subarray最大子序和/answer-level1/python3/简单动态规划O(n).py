```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        '''
        思路：
        最大连续子序列一定是以某个元素结尾的，那么我们就思考以nums中每个元素结尾的
        连续子序列其最大和是多少。
        status数组存以nums[i]结尾的子序列的最大和，那么当思考nums[i+1]结尾的子序列
        的最大和时，显然只要考虑两种情况，（1）是与以nums[i]结尾的最大子序列结合？
        （2）还是以自己nums[i+1]为子序列？
        '''
        status = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i]+status[i-1] > nums[i]:
                status.append(nums[i]+status[i-1])
            else:
                status.append(nums[i])
        return max(status)
```
