```
class Solution(object):
    def spiralOrder(self, matrix):
        if not matrix:
            return []
        ans = []
        # 真·顺时针，（0，1）表示行号增加0，列号增加1
        d, d_num = [[0, 1], [1, 0], [0, -1], [-1, 0]], 0
        row, col = len(matrix), len(matrix[0])
        # 新增壁垒
        visited = [[False]*col for i in range(row)]
        # 当前位置
        cur_x, cur_y = 0, 0
        for _ in range(row*col):
            # 访问尚未访问过的点
            if not visited[cur_x][cur_y]:
                ans.append(matrix[cur_x][cur_y])
                visited[cur_x][cur_y] = True
            
            # 碰壁则顺时针旋转一个方向
            if (cur_x + d[d_num][0]>=row) or (cur_x + d[d_num][0]<0) or (cur_y + d[d_num][1]>=col) or (cur_y + d[d_num][1]<0) or visited[cur_x+d[d_num][0]][cur_y+d[d_num][1]]:
                d_num = (d_num + 1)%4

            cur_x += d[d_num][0]
            cur_y += d[d_num][1]
        return ans
            
```
