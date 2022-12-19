主要分为三个步骤：
1. 找出第一行、最后一行、第一列、最后一列中值为'O'的坐标，然后将其放到stack里面；
2. 使用BFS或DFS将联通的'O'全部都标记为已访问的状态。
3. 遍历整个数组，将值为'O'且没有被访问过的坐标值改为'X'。
至此，已经解决完。大概用时200ms,消耗内存14.6M。
一个小的优化就是最后遍历的时候不用遍历四周的边界？这个可能没什么用，求大佬的优化方法。
```
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if board == []:
            return
        rows = len(board) # 行数
        columns = len(board[0]) # 列数
        stack = list() # 深度遍历
        visited = [[False for column in columns] for columns in board]
        # 1. 先将第一行和最后一行值为'O'的坐标存放在stack里
        for column in range(columns):
            if board[0][column] == 'O': # 第一行
                stack.append([0, column])
                visited[0][column] = True
            if board[rows - 1][column] == 'O': # 最后一行
                stack.append([rows - 1, column])
                visited[rows - 1][column] = True
                
        # 2. 再将第一列和最后一列值为'O'的坐标存放在stack里
        for row in range(rows):
            if board[row][0] == 'O': # 第一列
                stack.append([row, 0])
                visited[row][0] = True
            if board[row][columns - 1] == 'O': # 最后一列
                stack.append([row, columns - 1])
                visited[row][columns - 1] = True

        while stack != []: # 进行广度优先遍历
            [a, b] = stack.pop()
            if a - 1 >= 0 and visited[a - 1][b] == False and board[a - 1][b] == 'O': # 向上检索
                stack.append([a - 1, b])
                visited[a - 1][b] = True
            if a + 1 < rows and visited[a + 1][b] == False and board[a + 1][b] == 'O': # 向下检索
                stack.append([a + 1, b])
                visited[a + 1][b] = True
            if b - 1 >= 0 and visited[a][b - 1] == False and board[a][b - 1] == 'O': # 向左检索
                stack.append([a, b - 1])
                visited[a][b - 1] = True
            if b + 1 < columns and visited[a][b + 1] == False and board[a][b + 1] == 'O': # 向右检索
                stack.append([a, b + 1])
                visited[a][b + 1] = True
        
        for row in range(rows):
            for column in range(columns):
                if board[row][column] == 'O' and visited[row][column] == False:
                    board[row][column] = 'X'
```
