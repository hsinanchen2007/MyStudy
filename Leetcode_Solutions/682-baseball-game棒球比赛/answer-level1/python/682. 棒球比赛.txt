```
# -*- coding: utf-8 -*

# 棒球比赛
# 栈
class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        L = []
        for val in ops:
            if val == 'C':
                L.pop()
            elif val == 'D':
                L.append(L[-1] * 2)
            elif val == '+':
                L.append(L[-1] + L[-2])
            else:
                L.append(int(val))
        return sum(L)

print Solution().calPoints(["5","-2","4","C","D","9","+","+"])

```
