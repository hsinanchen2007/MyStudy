### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key=lambda x: len(x), reverse=True)
        ans = ""
        for word in words:
            if word+'#' not in ans:
                ans += word + '#'

        return len(ans)
```