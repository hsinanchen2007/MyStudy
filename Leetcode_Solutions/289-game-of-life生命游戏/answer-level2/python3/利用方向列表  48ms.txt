```
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def next_state(i, j):
            # 当前状态
            cur_state = board[i][j]
            # 初始化存活个数为0
            live_count = 0            
            for k in range(8):
                nx = i + lx[k]
                ny = j + ly[k]

                if 0<=nx<m and 0<=ny<n:
                    live_count += board[nx][ny]
            
            # print(i, j, cur_state, live_count)

            # 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡
            if cur_state == 1 and live_count < 2:
                return 0

            # 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活
            if cur_state == 1 and 2 <= live_count <= 3:
                return 1

            # 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡
            if cur_state == 1 and live_count > 3:
                return 0

            # 如果死细胞周围正好有三个活细胞，则该位置死细胞复活
            if cur_state == 0 and live_count == 3:
                return 1

            return 0

        m = len(board)
        n = len(board[0])
        dic = dict()
        # 方向, 左上，上，右上，右，右下，下，左下，左
        lx = [-1, -1, -1, 0, 1, 1, 1, 0]
        ly = [-1, 0, 1, 1, 1, 0, -1, -1]
        for i in range(m):
            for j in range(n):
                nxt_state = next_state(i, j)
                dic[(i, j)] = nxt_state

        # 更新细胞状态
        for key,val in dic.items():
            board[key[0]][key[1]] = val
```
