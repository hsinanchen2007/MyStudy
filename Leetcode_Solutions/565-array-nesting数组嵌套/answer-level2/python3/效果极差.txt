
依次把每一个元素作为第一个去寻找。
记录每次寻找访问过的数据
如果某个元素在其中，则这个元素开头的序列必然是之前序列的子序列，可以不算，continue到下一次循环


```python []
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        finalres = set()
        havedown = set()
        for i in range(len(nums)):
            res = set()
            if nums[i] in havedown:
                continue
            while nums[i] not in res:
                res.add(nums[i])
                i=nums[i]
            havedown = havedown | res
            if len(res) > len(finalres):
                finalres = res
        
        return len(finalres)
```
