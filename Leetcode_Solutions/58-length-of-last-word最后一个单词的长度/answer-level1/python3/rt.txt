```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s or not s.strip(): return 0
        count, flag = 0, 0
        for i in s[::-1]:
            if i == ' ':
                if not flag:
                    continue
                break
            count += 1
            flag = 1
        return count

```
