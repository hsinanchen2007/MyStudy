用栈的思想去解决：
把找到为‘1’的元素四周放到栈里面，并把在一个岛里面的置为同样的数字
1	1	0	0	0
1	1	0	0	0
0	0	1	0	0
0	0	0	1	1
////////变成/////////

1	1	0	0	0
1	1	0	0	0
0	0	2	0	0
0	0	0	3	3


```
class Solution:
    def numIslands(self, grid) -> int:
        count = 1
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    # 找到一个为1的数字后，设置一个栈
                    stack = []
                    stack.append([i, j])
                    while stack:
                        # ele_x,ele_y是栈顶对应的位置
                        ele = stack.pop(0)
                        ele_x, ele_y = ele[0], ele[1]
                        if grid[ele_x][ele_y] != '1':
                            continue
                        grid[ele_x][ele_y] = count
                        if ele_y + 1 < len(grid[0]):
                            if grid[ele_x][ele_y + 1] == '1':
                                stack.append([ele_x, ele_y + 1])
                        if ele_x + 1 < len(grid):
                            if grid[ele_x + 1][ele_y] == '1':
                                stack.append([ele_x + 1, ele_y])
                        if ele_x - 1 > -1:
                            if grid[ele_x - 1][ele_y] == '1':
                                stack.append([ele_x - 1, ele_y])
                        if ele_y - 1 > -1:
                            if grid[ele_x][ele_y - 1] == '1':
                                stack.append([ele_x, ele_y - 1])
                    count += 1
        return count - 1
```
