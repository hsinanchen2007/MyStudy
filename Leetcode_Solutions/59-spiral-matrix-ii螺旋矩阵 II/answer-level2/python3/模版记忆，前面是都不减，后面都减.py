### 解题思路

```
col_begin, row_begin = 0, 0
col_end, row_end = n, n
```
四个for循环，
开始两个loop，range（0，n）==》（0，n-1）
后面两个loop，range（n-1，-1，-1）==》（n-1，0）

```
for i in range(col_begin, col_end):
    res[row_begin][i] = counter
    counter += 1
row_begin += 1

for i in range(row_begin, row_end):
    res[i][col_end-1] = counter
    counter += 1
col_end -= 1

# if row_begin <= row_end:
for i in range(col_end-1,col_begin-1,-1):
    res[row_end-1][i] = counter
    counter += 1
row_end -= 1

# if col_end <= col_begin:
for i in range(row_end-1,row_begin-1,-1):
    res[i][col_begin] = counter
    counter += 1
col_begin += 1
```
### 代码

```python3
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:

        res = [[0]*n for _ in range(n)]
        col_begin, row_begin = 0, 0
        col_end, row_end = n, n
        counter = 1
        # while col_begin <= col_end and row_begin <= row_end:
        while counter <= n**2:
            
            for i in range(col_begin, col_end):
                res[row_begin][i] = counter
                counter += 1
            row_begin += 1

            for i in range(row_begin, row_end):
                res[i][col_end-1] = counter
                counter += 1
            col_end -= 1

            # if row_begin <= row_end:
            for i in range(col_end-1,col_begin-1,-1):
                res[row_end-1][i] = counter
                counter += 1
            row_end -= 1

            # if col_end <= col_begin:
            for i in range(row_end-1,row_begin-1,-1):
                res[i][col_begin] = counter
                counter += 1
            col_begin += 1

        return res
```