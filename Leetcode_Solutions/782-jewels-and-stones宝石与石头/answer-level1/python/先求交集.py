
1. 先求S与J是否存在交集

2. 如果没有直接返回0

3. 如果进行一个遍历累加操作

复杂度 O（n）
```
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        tmp = set(J).intersection(set(S))
        res = 0
        if len(tmp) != 0:
            for i in S:
                if i in tmp:
                    res += 1;
            return res
        else:
            return 0
```
