```python
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        dic = collections.defaultdict(int)
        res = []
        for i in range(10, len(s) + 1):
            st = s[i-10:i] 
            dic[st] += 1
            if dic[st] == 2: res.append(st)
        return res
```