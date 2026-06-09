```
class Solution(object):
    def wordPattern(self, pattern, strs):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        hashp = {}
        hashs = {}
        strlist = strs.split()
        if len(strlist) != len(pattern):
            return False
        for i in range(len(pattern)):
            if pattern[i] not in hashp and strlist[i] not in hashs:
                hashp[pattern[i]] = i
                hashs[strlist[i]] = i
            elif pattern[i]  in hashp and strlist[i]  in hashs:
                if hashp[pattern[i]] == hashs[strlist[i]]:
                    hashp[pattern[i]] = i
                    hashs[strlist[i]] = i
                else:
                    return False
            else:
                return False
        return True
```
