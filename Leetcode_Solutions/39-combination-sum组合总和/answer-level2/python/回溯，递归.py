
```python []
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res=[]
        for num in candidates:
            if target-num==0:
                res+=[[num]]
            if target-num<0:
                continue
            for l in self.combinationSum(candidates, target - num):
                demo=[num]+l
                demo=sorted(demo)
                if demo not in res:
                    res.append(demo)
        return res
```

