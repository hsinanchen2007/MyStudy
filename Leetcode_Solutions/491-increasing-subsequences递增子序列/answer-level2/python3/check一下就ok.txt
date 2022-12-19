### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
   
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        def check(num):
            if len(num)<2:
                return False
            for i in range(len(num)-1):
                if num[i]>num[i+1]:
                    return False
            return True
        n=len(nums)
        select=[]
        for i in range(2,n+1):
            select+=list(itertools.combinations(nums,i))
        select=list(set(select))
        res=[]
        for s in select:
            if check(s):
                res.append(s)
        return res
```