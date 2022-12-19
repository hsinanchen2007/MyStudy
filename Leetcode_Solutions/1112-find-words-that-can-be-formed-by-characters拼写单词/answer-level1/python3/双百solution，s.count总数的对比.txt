### 解题思路

```
for w in words:
    for i in w:
        if w.count(i)<=chars.count(i):
            indcator = True
        else:
            indcator = False
            break
    if indcator == True:
        res += len(w)
return res
```

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        res = 0

        for w in words:
            for i in w:
                if w.count(i)<=chars.count(i):
                    indcator = True
                else:
                    indcator = False
                    break
            if indcator == True:
                res += len(w)
        return res
        
        
                    
```