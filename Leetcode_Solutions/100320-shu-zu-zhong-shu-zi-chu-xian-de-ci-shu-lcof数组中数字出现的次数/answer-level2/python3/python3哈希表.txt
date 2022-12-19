```
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        res=[]
        hash={}
        for num in nums:
            hash[num]=hash[num]+1 if hash.get(num) else 1
        for s in nums:
            if hash[num]==1:
                res.append(num)
        return res
```
