### 解题思路
犯规地用了python三个库函数~

### 代码

```python3
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return word.isupper() or word.islower() or word.istitle()
```