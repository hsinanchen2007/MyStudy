```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res=[]

        def backtrack(i,tmp):
            if len(tmp)==len(nums):
                res.append(tmp)
                return
            for j in range(len(nums)):
                if nums[j] in tmp:
                    continue
                backtrack(j,tmp+[nums[j]])
        backtrack(0,[])  
        return res
                

```

