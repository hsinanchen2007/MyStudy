### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/63036c137c4dd2b44caaf983cb11731301fc98dffb5801986218b176e1f41d09-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```python3
class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        res = []
        x, y = king[0], king[1]

        for i in range(x + 1, 8):
            if [i, y] in queens:
                res.append([i, y]); break

        for i in range(x - 1, -1, -1):
            if [i, y] in queens:
                res.append([i, y]); break

        for j in range(y + 1, 8):
            if [x, j] in queens:
                res.append([x, j]); break

        for j in range(y - 1, -1, -1):
            if [x, j] in queens:
                res.append([x, j]); break

        i, j = x + 1, y + 1
        while i >= 0 and i < 8 and j >= 0 and j < 8:
            if [i, j] in queens:
                res.append([i, j]); break
            i, j = i + 1, j + 1

        i, j = x - 1, y + 1
        while i >= 0 and i < 8 and j >= 0 and j < 8:
            if [i, j] in queens:
                res.append([i, j]); break
            i, j = i - 1, j + 1
            
        i, j = x + 1, y - 1
        while i >= 0 and i < 8 and j >= 0 and j < 8:
            if [i, j] in queens:
                res.append([i, j]); break
            i, j = i + 1, j - 1 

        i, j = x - 1, y - 1
        while i >= 0 and i < 8 and j >= 0 and j < 8:
            if [i, j] in queens:
                res.append([i, j]); break
            i, j = i - 1, j - 1

        return res

```