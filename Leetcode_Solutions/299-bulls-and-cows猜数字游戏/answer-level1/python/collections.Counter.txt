
### 代码
```python
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        from collections import Counter
        d1, d2 = Counter(secret), Counter(guess)
        A, B =0, sum([min(d1[x], d2[x]) for x in d1 if x in d2])
        for i in range(len(guess)):
            if secret[i]==guess[i]: A, B = A+1, B-1
        return str(A)+'A'+str(B)+'B'    
```