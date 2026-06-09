```
from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        c = Counter(s)
        count=0
        find=False
        for i in c.values():
            if i%2==0:
                count+=i
            else:
                find=True
                count+=i-1
        
        return count if not find else count+1

```
