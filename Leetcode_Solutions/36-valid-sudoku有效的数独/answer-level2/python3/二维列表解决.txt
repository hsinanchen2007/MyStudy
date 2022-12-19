### 解题思路
构建三个二维列表储存有效数字，利用二重循环进行遍历并储存在相应的行，列列表里，用in判断重复即可

### 代码

```python3
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        hang_dic=[[]for i in range(9)]
        lie_dic=[[]for j in range(9)]#也可以构建一个9*9的列表
        kuai_dic=[[]for e in range(9)]
        for i in range (9):
            for j in range(9):
                num=board[i][j]
                kuai=i//3*3+j//3
                if num!='.':
                    num=int(num)
                    if num not in hang_dic[i]:
                        hang_dic[i].append(num)
                    else:
                        return False
                    if num not in lie_dic[j]:
                        lie_dic[j].append(num)
                    else:
                        return False
                    if num not in kuai_dic[kuai]:
                        kuai_dic[kuai].append(num)
                    else:
                        return False
        return True
                
                       
```