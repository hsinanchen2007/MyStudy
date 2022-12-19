### 解题思路
连续做了几道回溯相关的题目，感觉这道还是相对比较麻烦的

题目要求说：相同的节点不能访问两次，所以得建立一个与`board`形状相同的矩阵`visit`来标记元素是否在当前回溯过程中被访问过，当前访问结束之后，还要记得把访问标记去掉。

首先在矩阵`board`中寻找与`word[0]`相同的元素所在的位置，作为其实索引，把这些位置存在列表`start`中
遍历`start`，在每一个可能的位置进行回溯，如果找到了符合要求的答案，直接返回`True`
在矩阵中，有四种运动方向：**向上、向下、向左、向右**

1. 在回溯函数中，首先判断输入的字符串是不是空字符串，如果是空字符串，说明原字符串的所有元素全都被正确匹配，返回`True`
2. 然后判断当前要判断的元素是否被访问过了，如果已经被访问过了，就没有必要回溯下去了，直接返回，即回溯的剪枝
3. 进行到这里，说明字符串不为空，并且当前位置的元素没有访问过。那么我们判断当前元素是否与输入字符串的首元素相同
- 如果相同：把`visit`的当前位置改为被访问状态，然后沿着四个可能的方向继续向下走，递归调用回溯函数之前要判断一下当前要往下走的路径是不是还在合法范围内`if 0 <= new_pair[0] < len(board) and 0 <= new_pair[1] < len(board[0]):`
- 如果不相同：剪枝
- 最后记得把`visit`置回


### 代码

```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board or not word:
            return False
        if not board[0]:
            return False
        visit = [[0 for i in range(len(board[0]))] for j in range(len(board))]
        def backtrack(pair, s):
            if not s:
                return True
            if visit[pair[0]][pair[1]] == 1:
                return
            if s[0] == board[pair[0]][pair[1]]:
                visit[pair[0]][pair[1]] = 1
                for f in turn:
                    if not s[1:]:
                        return True
                    new_pair = [pair[0]+f[0], pair[1]+f[1]]
                    if 0 <= new_pair[0] < len(board) and 0 <= new_pair[1] < len(board[0]):
                        if backtrack(new_pair, s[1:]):
                            return True
                visit[pair[0]][pair[1]] = 0

        start = []
        turn = [[1,0], [0,1], [-1,0], [0,-1]]
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == word[0]:
                    start.append([i, j])

        if not start:
            return False
        for sta in start:
            if backtrack(sta, word):
                return True
        return False
```