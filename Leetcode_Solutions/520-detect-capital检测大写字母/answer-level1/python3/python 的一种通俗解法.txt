两种情况

1.如果第一个字母是大写，后面的子串可以全为大写、全为小写、空（只有一个字符）
2.如果第一个字母是小写，后面的子串可以全为小写、空（只有一个字符）

```
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word[0].isupper():
            if word[1:].isupper() or word[1:].islower() or word[1:] == '':
                return True
            else:
                return False

        if word[0].islower():
            if word[1:].islower() or word[1:] == '':
                return True
            else:
                return False
```
