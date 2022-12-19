
两个指针i for word, j for abbr
逐个比对字符，
- 如果abbr[j:]以数字开头，取出这个数字count，i = i+count
- 如果不是，那么检查i,j位置的字符是否相等，不相等就返回false

最后需要检查i和j是否都到达结尾

```
class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        count = i = j = 0
        while i < len(word) and j < len(abbr):
            while j < len(abbr) and abbr[j].isdigit():
                if abbr[j] == '0' and count == 0:
                    return False
                count = count*10 + int(abbr[j])
                j += 1
            
            if count > 0:
                i += count
                count = 0
            elif word[i] == abbr[j]:
                i += 1
                j += 1
            else:
                return False
        return count == len(word)-i and j == len(abbr)
```