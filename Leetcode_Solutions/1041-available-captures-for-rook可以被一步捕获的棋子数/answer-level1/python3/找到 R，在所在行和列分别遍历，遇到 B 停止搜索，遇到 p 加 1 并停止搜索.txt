### 解题思路
1， 找到 R 所在坐标 i，j，往四个方向搜索
2， 在 i 行 和 j 列分别遍历， 从 [i][j] --> [i][0], 从 [i][j] --> [i][lj], 从 [i][j] --> [0][j]，从 [i][j] --> [li][j]
3， 遇到 B 停止搜索，遇到 p 加 1 并停止搜索

```python3
        0, j
        |
        |
i,0 <-- i, j --> i, lj
        |
        |
        li, j

```

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        if not board:
            return 0

        li = len(board)
        if li == 0:
            return 0
        lj = len(board[0])
        if lj == 0:
            return 0
        
        r_location_i = 0
        r_location_j = 0

        i = 0
        while i < li:
            j = 0
            while j < lj:
                if board[i][j] == 'R':
                    r_location_i = i
                    r_location_j = j
                    i = li
                    j = lj
                j += 1
            i += 1
        
        rev = 0
        # 往左边寻找
        tj = r_location_j - 1
        while tj >= 0:
            if board[r_location_i][tj] == 'B':
                break
            if board[r_location_i][tj] == 'p':
                rev += 1
                break
            tj -= 1
        # 往右边寻找
        tj = r_location_j +1
        while tj < lj:
            if board[r_location_i][tj] == 'B':
                break
            if board[r_location_i][tj] == 'p':
                rev += 1
                break
            tj += 1
        # 往上边寻找
        ti = r_location_i - 1
        while ti >= 0:
            if board[ti][r_location_j] == 'B':
                break
            if board[ti][r_location_j] == 'p':
                rev += 1
                break
            ti -= 1
        # 往下边寻找
        ti = r_location_i + 1
        while ti < li:
            if board[ti][r_location_j] == 'B':
                break
            if board[ti][r_location_j] == 'p':
                rev += 1
                break
            ti += 1
        
        return rev
        


```