### 解题思路
我们每次加一个数的时候。如果这个数大于序列和且序列和是负数，那么我们的序列从新的这个数开始算。如果不是，我们讲这个数加到序列值中。

比较麻烦的地方是新加的这个数可能使序列和减小，所以我们创建一个list，第一位放最大序列和，第二位放当前序列和，这样通过比较输出最大序列和就可以。

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        lens = len(nums)
        opt_max = [nums[0] for _ in range(2)]
        for i in range(lens):
            if i == 0:
                continue
            if opt_max[1] < nums[i] and opt_max[1] < 0:
                opt_max[1] = nums[i]
            else:
                opt_max[1] += nums[i]
            if opt_max[0] < opt_max[1]:
                opt_max[0] = opt_max[1]
        return opt_max[0] 

```