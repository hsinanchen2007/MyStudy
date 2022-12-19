
### 代码

```python3
class Solution:
    def freqAlphabets(self, s: str) -> str:
        for count in range(0,17):
            s=s.replace(str(count+10)+'#',chr(count+ord('j')))
        
        for count in range(0,9):
            s=s.replace(str(count+1),chr(count+ord('a')))
        
        return s
        
```