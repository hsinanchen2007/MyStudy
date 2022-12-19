- 核心想法：将环展开成链。即将问题转化为我们熟悉的情形，```from rob() to line_rob()```
- 主要思路：既然要展开成链的形式，那```rob()```问题等价于4个种情形下的```line_rob()```问题。其实就是给```line_rob()```加上一些提前的设定。即为：
```
[rob, ... , rob](非法), [rob, ... , not rob], [not rob, ... , rob], [not rob, ... , not rob]
```
- 唯一的trick：```[not rob, ... , rob], [not rob, ... , not rob]``` 这两种情况等价于```line_rob(nums[1:])```
- 剩下的看代码大家肯定能懂了
```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]

        def line_rob(nums):
            dp = [[0 for __ in range(2)] for _ in range(len(nums))]
            dp[0][1] = nums[0]
            for i, num in enumerate(nums):
                if i == 0:
                    continue
                dp[i][0] = max(dp[i-1][0], dp[i-1][1])
                dp[i][1] = dp[i-1][0] + num
            if dp[-1][0] >= dp[-1][1]:
                return dp[-1][0], dp[-1][1], False
            else:
                return dp[-1][0], dp[-1][1], True

        not_rob_last, rob_last, rob_last_flag = line_rob(nums) # 我们不知道头有没有被偷
        if not rob_last_flag: # 如果尾不偷，那不用管头有没有被偷
            return not_rob_last
        else:
            not_rob_start_not_rob_last, not_rob_start_rob_last, rob_last_flag = line_rob(nums[1:])
            if not_rob_start_rob_last == rob_last: # 合法的，那这个自然是结果了。
                return rob_last
            else: # 此时，我们可以确认 rob_start_rob_last = rob_last，即rob_last的值是头尾都偷的，所以要被舍弃
                return max(not_rob_last, not_rob_start_not_rob_last, not_rob_start_rob_last)
```