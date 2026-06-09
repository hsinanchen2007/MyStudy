1. 因为行号与列号必须不同，所以我们只用记录其中一个即可，另一个随之确定，我们选择记录列号。
2. queen_str 每个位置的值表示当前放置的列号，index默认表示当前行号。
3. 检测是否冲突的条件为 不在同一列，并且不在对角线上。不在同一列好判断，对角线上的逻辑判断为 abs(当前行 - 当前列) = abs(想要放置的行 - 想要放置的列)
```
# @lc code=start
from typing import List
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        queen_str = ''
        def conflict(queen_str, corrent_queen):
            flag = False
            for index in range(len(queen_str)):
                # 如果当前打算放置的位置与已有位置处于同一列，则冲突
                if abs(corrent_queen - int(queen_str[index])) == 0:
                    flag = True
                    break
                # 如果当前位置与打算放置的位置处于对角线，则冲突
                # 处于对角线 即 abs(当前行 - 当前列) = abs(想要放置的行 - 想要放置的列)
                elif abs(corrent_queen - int(queen_str[index])) == len(queen_str) - index:
                    flag = True
                    break
            return flag
        
        def get_matrix(queen_str):
            # 通过已经有的放置行列数 获得解法矩阵
            matrix = [['.' for _ in range(n)] for _ in range(n)]
            for i, j in enumerate(queen_str):
                matrix[i][int(j)] = 'Q'
            return [''.join(x) for x in matrix]

        def back(queen_str):
            if len(queen_str) == n:
                ans.append(get_matrix(queen_str))
                return
            # 每一次对可能放置的列n行len(queen_str)进行检查，无冲突的话进行回溯
            for index in range(n):
                if not conflict(queen_str, index):
                    # ===============================
                    # 注意注释里面的错误写法
                    # 这是回溯法的精髓
                    # queen_str = queen_str + str(index)
                    # back(queen_str)
                    # ===============================
                    back(queen_str + str(index))
        back(queen_str)
        return ans 
# @lc code=end
Solution().solveNQueens(4)
```
