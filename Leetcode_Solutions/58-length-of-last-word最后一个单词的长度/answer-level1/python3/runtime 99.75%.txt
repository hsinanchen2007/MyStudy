
从后往前，当找到第二个‘ ’时，返回现在已经计数的长度。

```
class Solution(object):
    @classmethod
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0

        iii = len(s)-1

        find_non_kong = False if s[iii] == ' ' else True
        find_last_length = 0

        while iii >= 0:
            if s[iii] == ' ':
                if find_non_kong:
                    return find_last_length
                else:
                    iii -= 1
                    continue

            find_non_kong = True
            find_last_length += 1
            iii -= 1
        return find_last_length
```
