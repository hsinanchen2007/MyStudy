maxSize没有用，长串重复那肯定较短字串一定也重复。
然后与187,DNA那题类似。


```
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:       
        c = collections.Counter([s[j:j+minSize] for j in range(len(s) - minSize + 1) if len(set(s[j:j+minSize])) <= maxLetters])      
        return max(c.values()) if c else 0
```
