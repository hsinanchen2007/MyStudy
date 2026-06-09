### 解题思路
注意：第一次MaxPos=2并不是真的跳到了2，MaxPos和上一个end位置之间的所有可能的MaxPos都被计算了，最后跳的位置还是可能的最长的值。非常的Pythonic！

### 代码

```python
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        end=0
        MaxPos=0
        steps=0                     
        for i in range(len(nums)-1):
            MaxPos=max(MaxPos,i+nums[i])
            if(i==end):
                end=MaxPos
                steps+=1
        return steps
```