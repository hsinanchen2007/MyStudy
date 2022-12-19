### 解题思路
jump如果大于目前最大的范围，或者到达最远的是最后的一个元素

### 代码

```python
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        index=[]
        for i,value in enumerate(nums):
            index.append(i+value)
        jump=0
        max_index=index[0]
        while(jump<len(index) and jump<=max_index):
            if(max_index<index[jump]):
                max_index=index[jump]
            jump+=1
        if(jump==len(index)):
            return True
        return False

```