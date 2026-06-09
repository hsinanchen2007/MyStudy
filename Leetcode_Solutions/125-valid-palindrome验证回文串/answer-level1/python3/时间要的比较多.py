```
import string
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = ''.join(c for c in s if c not in string.punctuation)
        s = s.replace(' ', '')
        s = s.lower()
        s_list = list(s)
        m = len(s_list)
        
        for i in range(len(s_list)/2):
            if s_list[i] != s_list[m-1-i] :
                return False
            else:
                continue
        return True
                
        
```

        
                
        