### 解题思路
python3, 位运算加速， 52ms击败97.86%, 内存击败99.23%
每次找一行中可以放的位置，用三个n位二进制数分别表示对于当前行：
1. col: 哪些列由于列重复不可用
2. r_aix: 哪些列由于斜向↘对角线重复不可用
3. l_aix: 哪些列由于斜向↙对角线重复不可用

三个值按位取或，为0的地方为当前行可以尝试的列下标

小坑： l_aix由于一直在左移变大，要保证l_aix的位数小于等于 n

### 代码

```python3
'''
Thoughts:
    l_aix always shift left, it may exceed 0b1111
'''


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        results = []

        col = 0
        r_aix = 0
        l_aix = 0

        def dfs(cols, cur_line, col, r_aix, l_aix):
            cur_cols = cols.copy()
            if cur_line == n:
                cur_result = [["." for _ in range(n)] for _ in range(n)]
                print(cur_cols)
                for i in range(n):
                    cur_result[i][n - 1 - cols[i]] = 'Q'
                results.append(["".join(line) for line in cur_result])
                return
            
            valid = (col | r_aix | l_aix) ^ ((0b1 << n) - 1)

            cur_col = 0
            while(valid):
                if (valid & 0b1):
                    cur_cols.append(cur_col)
                    dfs(cur_cols ,cur_line+1, col|(0b1 << cur_col), (r_aix|(0b1 << cur_col)) >> 1, ((l_aix|(0b1 << cur_col)) << 1) & ((0b1 << n) - 1) )
                    cur_cols.pop()
                valid = valid >> 1
                cur_col += 1
        
        dfs([], 0, col, r_aix, l_aix)

        return results
```