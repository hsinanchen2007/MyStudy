### 解题思路
主要是先读懂题意，要解决两个问题：
1、形状；
- |/|/|/|
2、顺序；
- 1    7        13
  2  6 8     12 14
  3 5  9  11    15 
  4    10       16

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        list_row = []

        if numRows == 1:return s

        for i in range(0, min(len(s), numRows)):
            list_row.append([])

        # print(list_row[0].append(0))

        turnBool = False
        row_num = 0
        for i in range(0, len(s)):
            # l1 = list_row[row_num]
            # print(l1)
            # l1.append(s[i])
            # print(row_num)
            # print(turnBool)
            list_row[row_num].append(s[i])
            if row_num == 0:
                turnBool = not turnBool
            elif row_num == numRows-1:
                turnBool = not turnBool
            if turnBool:
                row_num += 1
            else:
                row_num += -1
        output = ''
        for i in range(0, len(list_row)):
            for j in range(0, len(list_row[i])):
                output += list_row[i][j]
        return output
                
```