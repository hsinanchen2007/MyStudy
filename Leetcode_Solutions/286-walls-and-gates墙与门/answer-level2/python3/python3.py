    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        INF = 2147483647
        if not rooms:
            return
        row, col, dis = len(rooms), len(rooms[0]), 0
        res = []
        for i in range(row):
            for j in range(col):
                if rooms[i][j] == 0:
                    res.append([i, j, 0])
        while res:
            i, j, dis = res.pop(0)
            left = j - 1
            right = j + 1
            up = i - 1
            down = i + 1
            if left >= 0 and rooms[i][left] == INF:
                rooms[i][left] = dis + 1
                res.append([i, left, dis + 1])
            if right < col and rooms[i][right] == INF:
                rooms[i][right] = dis + 1
                res.append([i, right, dis + 1])
            if up >= 0 and rooms[up][j] == INF:
                rooms[up][j] = dis + 1
                res.append([up, j, dis + 1])
            if down < row and rooms[down][j] == INF:
                rooms[down][j] = dis + 1
                res.append([down, j, dis + 1])