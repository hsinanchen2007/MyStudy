

benefit[i] 表示选择当前i位置的元素
```
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) <= 2:
            return max(nums)
        # 每个题 要先自己想 然后实在想不出来  在看答案!
        # 不能接受相邻的预约
        benefit = [0] * len(nums)
        # benefit[i] 表示选择i位置的预约的最大数值
        benefit[0] = nums[0]
        benefit[1] = nums[1]
        for i in range(2, len(benefit)):
            benefit[i] = max(benefit[0:i - 1]) + nums[i]
        # print(benefit)
        return max(benefit[-1], benefit[-2])

```
