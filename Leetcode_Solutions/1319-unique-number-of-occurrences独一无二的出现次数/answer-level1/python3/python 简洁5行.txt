先对数组元素计数，然后判段计算值是不是都唯一
```
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        counter={}
        for n in arr:
            counter[n]=counter.get(n,0)+1
        counts=list(counter.values())
        return len(counts)==len(set(counts))
```


