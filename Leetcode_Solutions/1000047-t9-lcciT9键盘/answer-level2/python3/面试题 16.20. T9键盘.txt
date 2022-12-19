### 解题思路

正则映射替换。

### 代码

```python []
class Solution:
    def getValidT9Words(self, num: str, words: List[str]) -> List[str]:
        d = {'a': '2', 'b': '2', 'c': '2', 'd': '3', 'e': '3', 'f': '3', 'g': '4', 'h': '4', 'i': '4', 'j': '5', 'k': '5', 'l': '5', 'm': '6', 'n': '6', 'o': '6', 'p': '7', 'q': '7', 'r': '7', 's': '7', 't': '8', 'u': '8', 'v': '8', 'w': '9', 'x': '9', 'y': '9', 'z': '9'}
        return (w for w in words if re.sub('([a-z])', lambda r: d[r.group(0)], w) == num)
```