```
# -*- coding: utf-8 -*

class Solution(object):
    def removeDuplicates(self, S):
        """
        :type S: str
        :rtype: str
        """
        L = []
        for v in S:
            if L and v == L[-1]:
                L.pop()
            else:
                L.append(v)
        return ''.join(L)

```
