### 解题思路
没啥思路，看完题就写了

### 代码

```python
class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_num=0
        res=0
        for i in nums:
            if i==1:
                res+=1
                if res>max_num:
                    max_num=res
            else:
                res=0
        return max_num
```