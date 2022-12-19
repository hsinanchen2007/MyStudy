### 解题思路
此题目主要问题时解决第3个条件，也就是3*3小矩阵
可以定义2个变量，x = 3*(i//3) 和 y = 3*(i%3)，此时i为小矩阵的序号，共有9个
分别表示行和列，运用切片，将大矩阵分为小矩阵
如
  ["5","3","." ,".","7","." ,".",".","."],
  ["6",".","." ,"1","9","5" ,".",".","."],
  [".","9","8" ,".",".","." ,".","6","."],
    （1）         （2）          （3）

  ["8",".","." ,".","6","." ,".",".","3"],      
  ["4",".","." ,"8",".","3" ,".",".","1"], 
  ["7",".","." ,".","2","." ,".",".","6"],
    （4）          （5）          （6）

  [".","6","." ,".",".","." ,"2","8","."],
  [".",".","." ,"4","1","9" ,".",".","5"],
  [".",".","." ,".","8","." ,".","7","9"]
    （7）            （8）         （9）

### 代码

```python3
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:      
        for i in range(9):
            nums1,nums2,nums3 = {},{},{}
            for x in board[i]:
                if x not in nums1 or x == ".":
                    nums1[x] = True
                else:return False

            for y in board:
                if y[i] not in nums2 or y[i] == ".":
                    nums2[y[i]] = True
                else:return False

            for y in board[3*(i//3):3*(i//3)+3]:
                for x in y[3*(i%3):3*(i%3)+3]:
                    if x not in nums3 or x == ".":
                        nums3[x] = True
                    else:return False
        
        return True
        



            


```