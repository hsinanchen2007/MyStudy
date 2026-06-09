* what is underlying
    * 引理1：如果能跳到位置`i`，那么一定能跳到前面的任意位置。
    * 引理2：如果不能跳到位置`i`，那么一定不能跳到后面的任意位置。
* 动态规划
    * 对于位置`i`，如果存在`0<=j<i`，使得`nums[j]+j>=i`，说明从位置`j`可以跳到位置`i`上，那么我们就接着看`i+1`。如果不存在这样的`j`，根据引理2，直接返回`False`。

```python []
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        flag = False
        for i in range(1, len(nums)):
            flag = False
            for j in range(i-1,-1,-1):
                if (nums[j] + j >= i):
                    flag = True
                    break
            if(not flag):
                return False
        return True
```