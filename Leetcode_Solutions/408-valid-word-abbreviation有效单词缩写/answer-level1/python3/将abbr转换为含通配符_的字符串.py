```
这个题不是很简单，边界很多；还是转换比较简单一些；
class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        abbr += '#'
        b = ""
        num = 0
        for i in range(len(abbr)):
            if abbr[i] == '0' and num == 0:
                return False
            if abbr[i].isdigit():
                num = num * 10 + int(abbr[i])
            else:
                if num > len(word):
                    return False
                b += num * '*' + abbr[i]
                num = 0
        b = b[:len(b) - 1]
        if len(word) != len(b):
            return False
        for i in range(len(word)):
            if word[i] ！= b[i] and b[i] == '*'
                return False
        return True
```
