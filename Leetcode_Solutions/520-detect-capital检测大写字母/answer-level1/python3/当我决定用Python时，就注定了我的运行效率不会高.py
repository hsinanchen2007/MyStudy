### 解题思路
执行用时 :
40 ms
, 在所有 Python3 提交中击败了
56.74%
的用户
内存消耗 :
13.2 MB
, 在所有 Python3 提交中击败了
53.59%
的用户

### 代码

```python3
import functools
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        temp_word=word.lower()
        temp1=0
        temp2=0
        for e1 in temp_word:
            temp1+=ord(e1)
        for e1 in word:
            temp2+=ord(e1)
        if temp1==temp2:
            return True
        elif temp2+len(word)*32==temp1:
            return True
        else:
            if ord(word[0].upper())==ord(word[0]) and temp_word[1:]==word[1:]:
                return True
        return False
```