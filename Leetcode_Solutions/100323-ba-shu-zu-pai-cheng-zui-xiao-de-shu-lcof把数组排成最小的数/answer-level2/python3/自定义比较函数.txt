```
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        from functools import cmp_to_key
        def compare(a,b):
            if a+b < b+a: return -1
            elif a+b > b+a: return 1
            else: return 0
        nums = [str(item) for item in nums]
        nums.sort(key=cmp_to_key(compare))
        res = ''
        for item in nums:
            res +=str(item) 
        return res 
```
