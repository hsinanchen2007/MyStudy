### 解题思路
如果board为空或者board[0]为空，不用做任何修改，直接返回
创建一个与board纬度一样parent列表来存储每个节点的父节点，每个'O'位置的父节点初始化为自己的索引，每个'X'位置的父节点初始化为[-1,-1]
创建一个与board纬度一样rank列表来存储每个节点的父节点的高度，用来做路径压缩，初始值均为0


- 接下来是并查集的常规操作：
1. 定义find函数，用来返回当前节点的根节点

2. 定义union函数，用来合并两个输入节点

3. 定义union_find函数来做遍历board，两两合并节点


**合并节点之后，遍历board的最外层，如果遍历到'O'，就把当前这个'O'的根节点的父节点设为[-1, -1]。一圈操作下来之后，board中根节点不是[-1, -1]的节点就是被'X'围住的'O'区域**

### 代码

```python3
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        if not board[0]:
            return

        parent = [[[j, i] if board[j][i] == 'O' else [-1, -1] for i in range(len(board[0]))] for j in range(len(board))]
        rank = [[0 for i in range(len(board[0]))] for j in range(len(board))]

        def find(i, j):
            if parent[i][j] == [-1, -1]:
                return [-1, -1]
            if parent[i][j] == [i, j]:
                return [i, j]
            else:
                return find(parent[i][j][0], parent[i][j][1])

        def union(x, y, m, n):
            xyroot = find(x, y)
            mnroot = find(m, n)
            if board[x][y] != 'O' or board[m][n] != 'O':
                return
            if xyroot != mnroot:
                if rank[xyroot[0]][xyroot[1]] > rank[mnroot[0]][mnroot[1]]:
                    parent[mnroot[0]][mnroot[1]] = [xyroot[0], xyroot[1]]
                elif rank[xyroot[0]][xyroot[1]] < rank[mnroot[0]][mnroot[1]]:
                    parent[xyroot[0]][xyroot[1]] = [mnroot[0], mnroot[1]]
                else:
                    parent[xyroot[0]][xyroot[1]] = [mnroot[0], mnroot[1]]
                    rank[mnroot[0]][mnroot[1]] += 1

        def not_X(matricx):
            for i in matricx:
                if 'X' in i:
                    return True
            return False
        def union_find():
            if not not_X(board):
                return
            for i in range(len(board)):
                for j in range(len(board[0])):
                    if i == len(board)-1 and j == len(board[0])-1:
                        break
                    if i == len(board)-1:
                        union(i, j, i, j+1)
                        continue
                    if j == len(board[0])-1:

                        union(i, j, i+1, j)
                        continue
                    else:
                        union(i, j, i, j+1)
                        union(i, j, i+1, j)

            for i in range(len(board)):
                if board[i][0] == 'O':
                    this_root = find(i, 0)
                    parent[this_root[0]][this_root[1]] = [-1, -1]
                if board[i][-1] == 'O':
                    this_root = find(i, len(board[0])-1)
                    parent[this_root[0]][this_root[1]] = [-1, -1]
            for j in range(len(board[0])):
                if board[0][j] == 'O':
                    this_root = find(0, j)
                    parent[this_root[0]][this_root[1]] = [-1, -1]
                if board[-1][j] == 'O':
                    this_root = find(len(board)-1, j)
                    parent[this_root[0]][this_root[1]] = [-1, -1]
            for i in range(len(board)):
                for j in range(len(board[0])):
                    if find(i, j) != [-1, -1]:
                        board[i][j] = 'X'

        union_find()
```