### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        b1 =[]
        s1 =[]
        for i in nums:
            if i>=0:
                b1.append(i)
            else:
                s1.append(i)
        b1 =sorted(b1, reverse =True)
        s1 =sorted(s1)
        if len(b1)<1:
            return s1[0]*s1[1]*s1[2] 
        elif len(b1)<2:
            return s1[0]*s1[1]*b1[0]
        elif len(b1)<3:
            try:
                return s1[0]*s1[1]*b1[0]
            except:
                return s1[0]*b1[1]*b1[0]
        else:
            if len(s1)>=2:
                return max(s1[0]*s1[1]*b1[0],b1[0]*b1[1]*b1[2])
            return b1[0]*b1[1]*b1[2]
        
        

```