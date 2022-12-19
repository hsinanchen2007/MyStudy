    def generateMatrix(self, n: int) -> List[List[int]]:
        # 浅拷贝，不是真正意义的多维数组
        # res = [[0] * n] * n
        # 深拷贝
        res = [[0] * n for i in range(n)]
        left, up = 0, 0
        right, down = n - 1, n - 1
        num = 1
        while True:
            # 向右
            i = left
            while i <= right:
                res[up][i] = num
                i += 1
                num += 1
            # 重新定义上边界
            up += 1
            if up > down:
                break

            # 向下
            i = up
            while i <= down:
                res[i][right] = num
                i += 1
                num += 1
            # 重新定义右边界
            right -= 1
            if right < left:
                break

            # 向左
            i = right
            while i >= left:
                res[down][i] = num
                i -= 1
                num += 1
            # 重新定义下边界
            down -= 1
            if down < up:
                break

            # 向上
            i = down
            while i >= up:
                res[i][left] = num
                i -= 1
                num += 1
            # 重新定义左边界
            left += 1
            if left > right:
                break

        return res