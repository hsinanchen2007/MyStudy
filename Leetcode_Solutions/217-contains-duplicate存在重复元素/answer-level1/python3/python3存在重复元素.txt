```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dic={}
        for num in nums:
            if dic.get(num):
                return True
            else:
                dic[num]=1
        return False
```
