## 思路:

使用 `itertools`的`zip_longest`简化代码，三行即可。

## 代码:

```python
class Solution:
    def validWordSquare(self, words: List[str]) -> bool:
        for  idx, val in enumerate(itertools.zip_longest(*words, fillvalue="")):
            if words[idx] != "".join(val): return False
        return True
```

