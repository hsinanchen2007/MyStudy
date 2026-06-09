### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:

    def totalNQueens(self, n: int) -> List[List[str]]:
        self.res = 0

        def checkChessBoard(r: int, c: int, col: List[int]):
            for i in range(r):
                if col[i] == c or abs(col[i] - c) == abs(i - r):
                    return False
            return True

            pass

        def dfsChessBoard(r: int, path: List[str], col: List[int]):
            if r == n:
               
                self.res += 1
                col = [0] * 100
                return

            for i in range(n):
                if checkChessBoard(r, i, col) is True:
                    tmp_path = '.' * i + 'Q' + '.' * (n - i - 1)

                    col[r] = i
                    dfsChessBoard(r + 1, path + [tmp_path], col)

                    pass

        dfsChessBoard(0, [], [0] * 100)

        return self.res

```