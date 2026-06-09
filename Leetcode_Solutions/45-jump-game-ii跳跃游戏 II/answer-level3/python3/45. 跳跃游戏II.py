### 解题思路
这是我第一次刷到的贪心算法，没看题解前打算用dp做，不过时间复杂度为O(N^2)。本题贪心策略是在当前元素跳跃范围内，找到能跳的最远的元素作为下一次跳跃点。下面代码主要考虑到几个边界情况，一，只有一个元素，step=0；二，多个元素，但第一个元素就能跳到终点,step+1；三，在够得着的元素中，可以直接经过它跳到终点，step+2。

### 代码

```python3
class Solution:
    def jump(self, nums: List[int]) -> int:
        step = 0
        i = 0
        if i==len(nums)-1:
            return step
        while i<len(nums):
            max_jump = -1
            jump_start = i
            if i+nums[i]>=len(nums)-1:
                return step+1
            for j in range(i+1,i+nums[i]+1): #贪心策略，每次挑选能够着里面挑的最远的点作为下次跳跃点
                if j+nums[j]>max_jump:
                    jump_start = j
                    max_jump = j+nums[j]
                if j+nums[j]>=len(nums)-1:
                    return step+2
            step += 1 
            i = jump_start
        return step
```