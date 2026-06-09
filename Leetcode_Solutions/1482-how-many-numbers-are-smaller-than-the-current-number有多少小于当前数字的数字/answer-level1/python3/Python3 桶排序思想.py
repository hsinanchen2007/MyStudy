看到提示中对数组中数的范围限制就很容易想到桶排序了。
```
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        bulk=[0]*101
        for i in nums:
            bulk[i]+=1
        res=[]
        for j in nums:
            res.append(sum(bulk[:j]))
        return res
```
