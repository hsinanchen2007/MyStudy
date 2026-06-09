![image.png](https://pic.leetcode-cn.com/c767602d486d1fc8b871016d44322ac34acf852801265c4c1d31f10d5a0f1015-image.png)


```
'''
从king位置往8个方向找第一个queen位置即可
'''

from typing import List
class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        pos = [[0 for _ in range(8)] for _ in range(8)]

        for i, j in queens:
            pos[i][j] = 1

        direc = [(0, 1), (1, 0), (1, 1), (0, -1), (-1, 0), (-1, 1), (1, -1), (-1, -1)]
        ans = []
        for move in direc:
            i, j = king

            flag = False
            while i >= 0 and i < 8 and j >= 0 and j < 8:
                if pos[i][j] == 1:
                    flag = True
                    break

                i, j = i + move[0], j + move[1]

            if flag:
                ans.append([i, j])

        return ans
```
