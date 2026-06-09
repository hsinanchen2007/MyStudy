### 解题思路

### 代码

```python3
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        dico = collections.Counter(arr)
        dicov = [i for i in dico.values()]
        co = collections.Counter(dicov)
        cov = [j for j in co.values()]
        return True if set(cov) == {1} else False
```