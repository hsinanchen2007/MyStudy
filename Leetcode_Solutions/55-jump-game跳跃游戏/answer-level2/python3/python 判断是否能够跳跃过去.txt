### 解题思路
判断当前值是否为0，以及历史最大值是否能够跳跃过去。

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:

        if not nums:
            return False

        if len(nums)==1:
            return True

        max_dist = 0

        for i, c in enumerate(nums[:-1]):
            max_dist = max(max_dist, i+c)

            if max_dist<=i and c==0: # 当前值为0，历史最大值跳不过去
                return False

        return max_dist>=len(nums[:-1])
```