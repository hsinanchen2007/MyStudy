### 解题思路
遍历三次，分别找出第一大，第二大，第三大的数
如果找不出三个，就返回最大的

### 代码

```python
class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=[]
        for i in range(3):
            tmp=nums[0]
            for j in nums:
                if tmp in res:
                    tmp=j
                if j not in res and j >tmp:
                    tmp=j
            if tmp not in res:
                res.append(tmp)
        if len(res)>2:
            return min(res)
        return max(res)
            
        
                
```