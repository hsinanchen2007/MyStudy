### 解题思路
做完这道题我觉得可能对回溯算法有了比较清晰的认识，之前我一直不理解什么是回溯，因为本来递归算法就要保存函数之前的状态，那么在返回之前的状态时这难道不是回溯吗？做完这道题我觉得回溯算法应该是有显式的状态保存，比如这道题设置的flag二维数组用来保存`board[x][y]`是否到达过，这道题回溯操作很简单只有一行，已经在代码中标注，这里需要注意的是，由于递归的存在虽然在当前(x, y)位置只对这一个位置的flag清零，但是由于是递归操作，之前进行的深度遍历所标注的flag都会被清零。

### 代码

```python
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        len1 = len(board)
        len2 = len(board[0])
        flag = [[0] * len2 for _ in range(len1)]
        def get_res(x, y, word):
            if word == '':
                return True
            if x < 0 or y < 0 or x >= len1 or y >= len2 or flag[x][y] or word[0] != board[x][y]:
                return False
            flag[x][y] = 1
            subword = word[1:]
            for i, j in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                if get_res(x + i, y + j, subword):
                    return True
            flag[x][y] = 0 # 回溯
            
        for i in range(len1):
            for j in range(len2):
                if board[i][j] == word[0]:
                    res = get_res(i, j, word)
                    if res:
                        return True
        return False
```