```
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        import re
        licensePlate = licensePlate.lower()
        r = list(''.join(re.split(r'[^a-z]', licensePlate)))
        print(r)
        min_l = '0'*16
        for i in range(len(words)):
            a = list(words[i])
            print(a)
            try:
                for j in r:
                    a.remove(j)
            except:
                continue
            if len(words[i]) < len(min_l):
                min_l = words[i]
        return min_l
```
