我是用递归做的 貌似时间和空间都不是很优 但能通过
```
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        k = 1
        l = len(arr)
        def switch(list1,list2):
            for i in list1:
                for j in list2:
                    if i>j:
                        return False
            return True
        while (not switch(arr[:k],arr[k:])) and k<l:
            k +=1
        if k>0 and k<l:
            return self.maxChunksToSorted(arr[:k])+self.maxChunksToSorted(arr[k:])
        else:
            return 1
```
