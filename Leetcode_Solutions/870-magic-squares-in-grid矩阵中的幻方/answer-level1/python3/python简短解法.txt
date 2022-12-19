```
def numMagicSquaresInside(self, grid):
	def isMagic(i, j):
		s = "".join(str(grid[i + x // 3][j + x % 3]) for x in [0, 1, 2, 5, 8, 7, 6, 3])
		return grid[i][j] % 2 == 0 and (s in "43816729" * 2 or s in "43816729"[::-1] * 2)
	return sum(isMagic(i, j) for i in range(len(grid) - 2) for j in range(len(grid[0]) - 2) if grid[i + 1][j + 1] == 5)
```
