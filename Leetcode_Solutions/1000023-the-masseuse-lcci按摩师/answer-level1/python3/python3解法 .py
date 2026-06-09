

```
执行结果：
通过
显示详情
执行用时 :28 ms, 在所有 Python3 提交中击败了97.92% 的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了100.00%的用户
```
动态规划做法：
dp(i)=max(dp(i-2)+n,dp(i-1))
最后返回nums数组里的最后一个数即可
```
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums: return 0
        if len(nums)<3: return max(nums)
        nums[1] = max(nums[0],nums[1])
        for i in range(2,len(nums)):
            nums[i] = max(nums[i-2]+nums[i],nums[i-1])
        return nums[-1] 
```
