巧用python内置的Counter返回字典，记录L,U,R,D出现的次数。比较左右和上下的值即可
```
from collections import Counter
class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        l = Counter(moves)
        if l['U'] == l['D'] and l['L'] == l['R']:
            return True
        else:
            return False
```



