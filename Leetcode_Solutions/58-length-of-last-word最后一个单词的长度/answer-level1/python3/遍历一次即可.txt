```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        s = s.strip()
        for i in s:
            if i == ' ':
                count = 0
            else:
                count+=1
        return count
```
要先把最后边的空格去掉
