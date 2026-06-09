```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        if target<2:
            return [[]]
        i=0
        res=[]
        searchRange=[n+1 for n in range(target//2+1)]
        length=target//2+1
        sums=0
        tempList=[]
        for i in range(length):
            sums=searchRange[i]
            tempList=[searchRange[i]]
            for j in range(i+1,length):
                tempList+=[searchRange[j]]
                sums+=searchRange[j]
                if sums==target:
                    res.append(tempList)
                    break
                if sums>target:
                    break
        return res  
```
