### 代码

```python3
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        fina=[]
        finded=[]
        for i in arr:
            if i not in finded:
                finded.append(i)
                jige=arr.count(i)
                if jige in fina:
                    return False
                fina.append(jige)
        return True
```