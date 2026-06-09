### 解题思路
这题与之前的跳跃游戏II思路一致，都是在当前元素够得着的地方找到下一个跳的最远的元素，只不过这里有元素值为0的情况，可能一直不跳，这种情况就是元素值为0且不是最后一个元素，会返回False。

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        i=0
        while i<len(nums):
            next_jump = i+nums[i]
            if next_jump>=len(nums)-1:
                return True
            elif next_jump<len(nums)-1 and nums[i]==0:
                return False
            tmp = i
            # 查看够得着的元素，哪个能跳得更远
            for j in range(i+1,i+nums[i]+1):
                if j+nums[j]>=next_jump:
                    tmp=j
                    next_jump=j+nums[j]
            i=tmp
```