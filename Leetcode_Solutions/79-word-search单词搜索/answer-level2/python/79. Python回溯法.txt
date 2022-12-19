### 解题思路
这是一道经典的回溯法习题，这道题要回溯的状态有两个：一个是当前已经匹配的路径，另一个是已匹配的路径对应在访问矩阵里面的值，当我们的路径回溯到上一个状态时，对应的矩阵也应该回溯。
对于矩阵的使用有两种方法：一种是定义成局部变量，另一种是作为参数传入递归函数中。对于作为参数传入递归函数中，这时不需要做额外处理，因为底层会保存之前矩阵的状态，但是如果作为局部变量使用（比如下面的实现），就需要在当前状态查找失败之后，手动将该节点访问状态置为0 。

### 代码

```python
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        len_1 = len(board)
        len_2 = len(board[0])
        len_s = len(word)
        direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        mem = [[0] * len_2 for _ in range(len_1)]
        def get_res(x, y, ind):
            if ind == len_s:
                return True
            if x < 0 or x >= len_1 or y < 0 or y >= len_2 or mem[x][y] or board[x][y] != word[ind]:
                return False
            mem[x][y] = 1
            for (i, j) in direction:
                if get_res(x + i, y + j, ind + 1):
                    return True
            mem[x][y] = 0 # 若查找失败，则将当前访问状态手动置为0
            return False
        for x in range(len_1):
            for y in range(len_2):
                if get_res(x, y, 0):
                    return True
        return False
```