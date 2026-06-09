很简单，不多说了吧，上代码
```
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        myList=[]
        for i in range((int)(len(nums)/2)):
            for j in range(nums[2*i]):
                myList.append(nums[2*i+1])
        return myList
                
```
