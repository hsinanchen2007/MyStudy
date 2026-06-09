```
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        a = [i for i in set(arr) if i == arr.count(i)]
        return max(a) if a != [] else -1
```

整个数一遍，找最大值，没有返回-1
