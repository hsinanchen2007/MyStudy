### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def combine(self, n, k):
        if k>n:
            return []
        res=[]
        nums=[i for i in range(1,n+1)]
        len_k=k
        index=0
        

        def loopk(k,path,nums):
            if not k:
                res.append(path)
                return 
            for i in range(len(nums)-k+1):
                if not path or nums[i]>path[-1]:
                    loopk(k-1,path+[nums[i]],nums[:i]+nums[i+1:])
        loopk(k,[],nums)
        return res
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
```