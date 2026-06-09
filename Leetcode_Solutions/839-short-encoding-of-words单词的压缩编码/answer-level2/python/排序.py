### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = sorted(words, key=lambda i: len(i), reverse=True)
        s = ''
        for i in words:
            if i+'#' in s:
                continue
            s += i+'#'
        return len(s)
```