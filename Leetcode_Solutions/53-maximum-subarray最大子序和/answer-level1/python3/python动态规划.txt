```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        result_sum = nums[0]
        sonNum_sum = 0  # 记录子数组的和
        for num in nums:
            if sonNum_sum > 0:  # 如果目前的子数组和sonNum_sum大于0，则加上当前num
                sonNum_sum += num
            else:  # 如果目前的子数组和sonNum_sum小于等于0，则子数组重新从num开始
                sonNum_sum = num
            result_sum = max(sonNum_sum, result_sum)  # 子数组中每添加一个num就要和上一次的结果进行比较
        return result_sum
```
