题目意思：grid为n*n矩阵，grid中的row和col对应着三维空间中的x，y
	# 俯视，与z轴无关，基于grid中的值无关，遍历grid中的非零值
	# 正视，与y轴无关，x轴最大值相加
	# 右视，与x轴无关，y轴最大值相加

    def projectionArea(self, grid: List[List[int]]) -> int:
        result = 0
        for i, row in enumerate(grid):
            # 正视图
            result += max(row)
            max_col = 0
            for j, col in enumerate(row):
                # 俯视图
                if col:
                    result += 1
                # 侧视图
                max_col = max(max_col, grid[j][i])
            result += max_col
        return result