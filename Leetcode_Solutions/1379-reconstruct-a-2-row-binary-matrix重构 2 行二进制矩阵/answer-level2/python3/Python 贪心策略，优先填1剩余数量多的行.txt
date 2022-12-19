![image.png](https://pic.leetcode-cn.com/7df194ef62e1b4922463356cc89246342897c1c894c0f9374c0c5d64f4833e49-image.png)


```
'''
首先有解的前提是colsum中1的总数和upper+lower相等
从左到右依次扫描colsum，lower, upper分别为两行剩余要填写的1的数量
两个数组填写对应数值即可, 当colsum数值为1时候，优先
选填剩余1数量多的一行，colsum数值为0或者2，不用考虑，肯定两行都填0或者都填1
'''

from typing import List
class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        if sum(colsum) != upper + lower:
            return []

        n = len(colsum)
        ans = [[0 for _ in range(n)] for _ in range(2)]

        for i, val in enumerate(colsum):
            if val == 2:
                ans[0][i] = ans[1][i] = 1
                upper -= 1
                lower -= 1

                if upper < 0 or lower < 0:
                    return []

            elif val == 1:
                if upper > lower:
                    upper -= 1
                    ans[0][i] = 1
                    ans[1][i] = 0
                else:
                    lower -= 1
                    ans[1][i] = 1
                    ans[0][i] = 0
        return ans
```
