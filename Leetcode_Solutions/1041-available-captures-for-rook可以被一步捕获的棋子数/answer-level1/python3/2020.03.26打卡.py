### 解题思路
行列分开考虑。

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        n = 0
        import numpy
        for i in board:
            if 'R' in i: ans1 = i.copy()
        while '.' in ans1:
            ans1.remove('.')
        str1 = ''.join(ans1)
        if 'pR' in str1: n += 1
        if 'Rp' in str1: n += 1
        t_board = numpy.transpose(board).tolist()
        for j in t_board:
            if 'R' in j: ans2 = j
        while '.' in ans2:
            ans2.remove('.')
        str2 = ''.join(ans2)
        if 'pR' in str2: n += 1
        if 'Rp' in str2: n += 1
        return n
        



            
```