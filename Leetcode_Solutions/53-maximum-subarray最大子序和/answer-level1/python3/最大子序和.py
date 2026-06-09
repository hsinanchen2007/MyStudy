设A[1...n]的最大子数组为A[i...j]，那么A[i...j]为A从i起始的子数组中和最大的那个。并且可得：
（1）A[i+1...j] 和>= 0。否则A[i]为A从i起始的子数组中和最大的那个。
（2）A[i+1...j]为A从i+1起始的子数组中和最大的那个。
考虑令一个变量i从n到1遍历，寻找A从i起始的子数组中和最大的那个，那么它或者包含A从i+1起始的子数组中和最大的那个，或者为A[i]。

```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        length = len(nums)
        
        # 定义两个数组end, sum，长度同nums。
        # 考虑数组nums中以第i个元素起始的所有子数组，哪个和最大。
        # 这个子数组的末尾元素在sums中的下标保存在end[i]，这个和保存在sum[i]。
        end = [0 for _ in nums]
        sum = [0 for _ in nums]
        
        end[length - 1] = length - 1
        sum[length - 1] = nums[length - 1]
        max_i = length - 1
        max_sum = sum[max_i]
        
        # 令i从length - 2遍历到1，更新end, sum。
        for i in reversed(range(length - 1)):
            if sum[i+1] >= 0:
                sum[i] = nums[i] + sum[i+1]
                end[i] = end[i+1]
            else:
                sum[i] = nums[i]
                end[i] = i
            if sum[i] > max_sum:
                max_i = i
                max_sum = sum[i]
        return max_sum
```