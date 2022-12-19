### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if r*c!=len(nums)*len(nums[0]):
            return nums
        
        res=[]
        tmp=[]
        index=0
        for i in nums:
            for j in i:
                tmp.append(j)
                index+=1
                if index%c==0:
                    res.append(tmp)
                    tmp=[]
        return res
        
        
```