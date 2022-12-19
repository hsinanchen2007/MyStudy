### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dict={}
        for i in nums:
            if i not in dict:
                dict[i]=1
            else:
                dict[i]=dict[i]+1
        longest=0
        temp=0
        for key in dict:
            if key+1 in dict:
                temp=dict[key]+dict[key+1]
                if temp>longest:
                    longest=temp
        return longest
```