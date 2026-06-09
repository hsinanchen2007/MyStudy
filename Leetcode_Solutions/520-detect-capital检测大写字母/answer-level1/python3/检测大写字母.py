### 解题思路
调用库函数

### 代码

```python3
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.islower() or word.isupper():
            return True
        elif word[0].isupper() and word[1:].islower():  # 等价于：word.istitle()
            return True
        else:
            return False
```