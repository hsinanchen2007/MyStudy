```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        avg=len(nums)/2
        count={}

        for i in nums:
            if i in count:
                count[i]+=1
            else:
                count[i]=1
            if count[i]>avg:
                return i
```
