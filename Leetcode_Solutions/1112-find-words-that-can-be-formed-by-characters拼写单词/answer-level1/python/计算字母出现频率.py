### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        dict_chars = {i:chars.count(i) for i in chars}
        for word in words:
            learnWord = True
            for c in word:
                if c not in dict_chars or word.count(c) > dict_chars[c]:
                    learnWord = False
                    break
            ans = ans+len(word) if learnWord else ans
        return ans
```