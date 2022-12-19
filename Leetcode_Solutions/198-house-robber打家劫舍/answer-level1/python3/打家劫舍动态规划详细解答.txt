### 动态规划
basic base: 
- len(nums) == 1: return nums[0]
- len(nums) == 2: return max(nums[0], nums[1])
状态转移方程怎么推(刚才自己想的方法, 交流指正)
- 对于第 n 个房子来说,有偷和不偷两种状态,
    - 如果偷, 则不能偷第 n-1 个,所以其状态只和 前 n-2 个 以及它本身有关;
    - 如果不偷, 则其状态只和前 n-1 个房子有关
    所以, 到第 n 个房子的最大收益为 两种状态的最大值 即 max(dp[n-2]+ nums[i], dp[n-1])
代码用 pre_max, cur_max 优化后如下; pre_max 代表到 n-2 的最大收益, cur_max 代表到 n-1 最大收益
### 代码

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums: return 0
        pre_max = 0
        cur_max = nums[0]
        for i in range(1, len(nums)):
            temp =cur_max
            cur_max = max(pre_max+nums[i], cur_max)
            pre_max = temp
        return cur_max
```