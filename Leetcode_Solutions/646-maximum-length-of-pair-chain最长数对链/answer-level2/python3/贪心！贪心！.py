如果想让更多的pair上链，需要链上的最后一个数尽可能地小，才能腾出更多的space给后面可能的pair
```
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x:x[1])
        res=1
        cur=pairs[0][1]
        for i in range(1,len(pairs)):
            if pairs[i][0]>cur:
                res+=1
                cur=pairs[i][1]
        return res
            
```
