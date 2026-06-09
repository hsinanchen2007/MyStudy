### 解题思路
count的妙用
### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        for word in words:
            for char in set(word):
                if word.count(char) <= chars.count(char):
                    vaild = True
                else:
                    vaild = False
                    break
            if vaild:
                ans +=len(word)
        return ans
        
```