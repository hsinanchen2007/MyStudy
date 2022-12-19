
### 代码

```python3
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) == 0:
            return True
        if len(magazine) == 0:
            return False
        a = [i for i in ransomNote]
        b = [i for i in magazine]
        i = 0
        while i < len(a):
            if a[i] in b:
                b.remove(a[i])
                i += 1
            else:
                return False
        return True
            
```