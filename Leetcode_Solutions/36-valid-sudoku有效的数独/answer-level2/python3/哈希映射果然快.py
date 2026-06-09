

# 法一：列表
```
 class Solution:  # 248ms
     def isValidSudoku(self, board: List[List[str]]) -> bool:
         row = len(board)
         column = len(board[0])
         box = [[], [], []]
         count = 0
         for i in range(row):  # 遍历行
             row_ = []
             row_temp = []
             column_ = [] 
             temp_len = 0
             if i > 0 and i % 3 == 0:  # 第4、7行,清空box
                 box = [[], [], []]
             for j in range(column):  # 遍历列  
                 if board[i][j] == '.' and (j+1) % 3 != 0:
                     pass
                 else:
                     if board[i][j] == '.':
                         pass
                     else: 
                         if board[i][j] not in row_:
                             row_.append(board[i][j])
                             row_temp.append(board[i][j])
                         else:
                             return False
                        
                     if (j+1) % 3 == 0:
                         if count == 3:
                             count = 0
                         temp_len = len(row_temp) - temp_len
                         if not temp_len:
                             temp_len = len(row_temp)
                             count += 1
                         else:
                             row_temp = row_temp[-temp_len:]
                             box[count] += row_temp
                             count += 1
                    
                 if board[j][i] == '.':
                     continue
                 elif board[j][i] not in column_:
                     column_.append(board[j][i])
                 else:
                     return False
             if [b for b in box if len(b) != len(set(b))]:  # 判断
                 return False
         return True
```


# 法二：字典(哈希映射)

```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        dict_row = [{} for _ in range(9)]
        dict_col = [{} for _ in range(9)]
        dict_box = [{} for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    dict_row[i][board[i][j]] = dict_row[i].get(board[i][j], 0) + 1
                    col_index = (i // 3) * 3 + j // 3  # 对应实线框内的9个区域
                    dict_box[col_index][board[i][j]] = dict_box[col_index].get(board[i][j], 0) + 1
                    if dict_row[i][board[i][j]] > 1 or dict_box[col_index][board[i][j]] > 1:
                        return False
                if board[j][i] != '.':
                    dict_col[i][board[j][i]] = dict_col[i].get(board[j][i], 0) + 1
                    if dict_col[i][board[j][i]] > 1:
                        return False
        return True
```
