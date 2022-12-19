### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dic={}
        if k<0:
            return 0
        res=0
        for num in nums:
            dic[num]=dic.get(num,0)+1
        for num in nums:
            if dic.get(num-k,0)>0 and num-k!=num:
                res+=1
                dic[num-k]=0
            elif num-k==num and dic.get(num,0)>1:
                res+=1
                dic[num-k]=0
        return res
```