### 解题思路
按规则逐条判断，9行+9列+9块


### 执行结果
![image.png](https://pic.leetcode-cn.com/9193909046d4efa42df3e2408a90f2a0c766efdbe7d9e628d33a3ae34639b281-image.png)


### 代码

```python3
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def isvaild9(lyst):
            nums = list(filter(lambda x:x != '.', lyst))
            return len(set(nums)) == len(nums)
        
        for row in board:#9行
            if not isvaild9(row):
                return False
        
        for column in zip(*board):#9列
            if not isvaild9(column):
                return False
        
        for row in range(3):#9块
            for column in range(3):
                tmp = [board[i][j] for i in range(row*3, row*3+3) for j in range(column*3, column*3+3)]
                if not isvaild9(tmp):
                    return False
        return True


```