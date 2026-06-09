
代码块
```class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        hashmap = collections.Counter(list(s))
        for i in list(t):
            if i in hashmap and hashmap[i] > 0:
                hashmap[i] -= 1
            else:
                return i```
