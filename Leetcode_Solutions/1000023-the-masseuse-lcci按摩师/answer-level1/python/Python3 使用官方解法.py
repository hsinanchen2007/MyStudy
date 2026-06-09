这题的提示是【递归】，没毛病。但是考虑到效率问题，用动态规划明显更合理。每个预约只有【接收】与【不接收】两个选项，所以可以考虑以该选项作为动态地规划的递推依据。

I: nums 为空，返回0；
II：nums 只有一个值，返回 nums[0]；
III：不妨将 nums 看作一个队列，那么随着新元素的加入，最长的总服务时长必定是 单调递增 的（即 非递减。这是数学上的叫法，区别于 严格单调递增）。
如果用 q[i] 来表示截至第 i 个元素的加入为止，按摩师的最长服务时间，则有以下递推关系式：
`q[i] = max(q[i-1], q[i-2]+nums[i])`
即，要么接收 nums[i]，那总服务时长是 q[i-2]+nums[i]；要么不接收 nums[i]，那总服务时长是 q[i-1]。

这里有个小 trick 可以合并以上三种情况，python3 代码如下：


```python
class Solution:
    def massage(self, nums: List[int]) -> int:
        # if len(nums) == 0:
        #     return 0

        # q0, q1 = 0, nums[0]
        # for num in nums[1:]:
        #     q0, q1 = q1, max(q0 + num, q1)

        # return q1

        q0, q1 = 0, 0
        for num in nums:
            q0, q1 = q1, max(q0 + num, q1)
        return q1
```

一个循环，显然时间复杂度 `O(n)`；
只引入 q0 q1 两个新变量，空间复杂度 `O(1)`。