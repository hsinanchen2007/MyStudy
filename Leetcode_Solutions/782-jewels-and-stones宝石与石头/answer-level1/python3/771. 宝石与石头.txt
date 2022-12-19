1. 直接循环
```
# -*- coding: utf-8 -*

class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        sum = 0
        for j in J:
            for s in S:
                if j == s:
                    sum = sum + 1
        return sum

```

2. 简化
```
# -*- coding: utf-8 -*

class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        return sum(S.count(J_data) for J_data in J)

```
