这道题目的优势在于:
 1. 一定可以跳到最后
 2. 每个位置的跳跃的范围为当前位置到最远距离

所以
1. 我们可以用递归的方法,从后往前跳
2. 如果目标是跳到某个位置,则从最远距离大于该位置的那些位置中贪婪得选择最靠前的就好.


```
class Solution:
    def jump(self, nums: List[int]) -> int:
        length = len(nums) - 1
        
        # 每个位置可以到达的最远位置
        # 按照最远位置降序排列
        ranges = [(i, i+nums[i]) for i in range(length)]
        ranges = sorted(ranges, key=lambda x:x[1], reverse=True)
        
        # 跳的步数
        n = 0
        
        # 从列表最后往前跳
        # pointer记录当前所在的index
        pointer = length
        
        # 直到跳回开头
        # 否则一直跳跃
        while pointer > 0:
            tmp_index = pointer
            for i, x in enumerate(ranges):
                if x[1] >= pointer:
                    tmp_index = min(tmp_index, x[0])
                else:
                    ranges = ranges[i:]
                    break
            pointer = tmp_index
            n += 1
        return n
```
