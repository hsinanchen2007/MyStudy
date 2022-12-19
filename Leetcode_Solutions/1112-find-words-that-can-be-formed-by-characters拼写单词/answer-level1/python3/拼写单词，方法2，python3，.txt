### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        chars_dict = collections.Counter(chars)
        res = 0
        for w in words:
            w_dict = collections.Counter(w)
            if all([w_dict[i] <= chars_dict[i] for i in w_dict]):
                res += len(w)
        return res
```