滑动窗口

```
from collections import Counter
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        start = 0
        end = 0
        need_win = Counter(s1)
        lookup = Counter()
        count = 0
        while end < len(s2):
            //如果s2中字符不在S1中,计数器清零，start指针和End指针同步
            if s2[end] not in need_win.keys():
                lookup.clear()
                count = 0
                start = end + 1
            else:
                lookup[s2[end]] += 1
                count += 1
            end = end + 1
            while count == len(s1):
                while all(map(lambda x:lookup[x] >= need_win[x], need_win.keys())):
                    if end - start == len(s1):
                        return True
                    break
                lookup[s2[start]] -= 1
                start = start + 1
                count -= 1
        return False
```
