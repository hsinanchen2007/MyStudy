```
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        for i in range(len(s)):
            if s[i] != ' ':
                count = 1 if s[i-1] == ' ' else count + 1
        return count
```
记录每一个单词的长度，遇到新的单词时重置。（好像比较慢）