![image.png](https://pic.leetcode-cn.com/a870735564b4b1a6e452785283a1ddeefa809ea7d7ca98df58e13f7677a6722f-image.png)

就是得注意临时字典必须要用.copy()来复制，否则会一直修改原字典
```
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        words.sort(key=len)
        licensePlate=licensePlate.lower()
        d=collections.defaultdict(int)
        for c in licensePlate:
            if c.isalpha():
                d[c]+=1
        for s in words:
            t=d.copy()
            for c in s:
                if c in t:
                    t[c]-=1
                    if t[c]==0:
                        t.pop(c)
            if not t:
                return s
```
