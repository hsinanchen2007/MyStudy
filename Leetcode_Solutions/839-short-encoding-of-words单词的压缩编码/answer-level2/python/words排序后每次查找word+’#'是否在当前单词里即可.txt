### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        if words == []:return 0
        words.sort(key = lambda x: len(x), reverse=True)
        ans = ''
        for i in words:
            ans = ans + i + '#' if i + '#' not in ans else ans
        return len(ans)

```