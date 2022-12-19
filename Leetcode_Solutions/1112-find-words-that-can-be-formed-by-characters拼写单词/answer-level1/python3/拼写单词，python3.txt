### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        res = 0
        for w in words:
            char_list = list(chars)
            flag = False
            for x in w:
                if x in char_list:
                    char_list.remove(x)
                else:
                    flag = True
                    break
            if not flag:
                res += len(w)
        return res
```