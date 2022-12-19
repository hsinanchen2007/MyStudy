### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = sorted(words, key=lambda i:len(i), reverse=True)
        S = ''
        for word in words:
            if word+'#' not in S:
                S+= word+'#'
        return len(S)
```