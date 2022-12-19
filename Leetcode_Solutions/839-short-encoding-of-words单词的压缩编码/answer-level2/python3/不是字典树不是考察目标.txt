### 解题思路
不是字典树，后面再试试字典树

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        result = set(words)
        for word in words:
            for i in range(1, len(word)):
                result.discard(word[i:])
        return len("#".join(result) + "#")
```