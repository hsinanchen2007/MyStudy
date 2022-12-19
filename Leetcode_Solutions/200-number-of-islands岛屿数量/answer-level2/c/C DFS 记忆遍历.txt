```
void wallk(int row, int col, char **grid, int rowMax, int colMax)
{
	int offset[5] = { -1, 0, 1, 0, -1 };

	if (grid[row][col] == '0') {
		return;
	}

        grid[row][col] = '0';

	for (int j = 0; j < 4; j++) {
        if (row + offset[j] >= rowMax || row + offset[j] < 0 || 
            col + offset[j + 1] < 0 || col + offset[j + 1] >= colMax) {
            continue;
        }

           wallk(row + offset[j], col + offset[j + 1], grid, rowMax, colMax);
	}

	return;
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
	int rowMax;
	int colMax;
	int i;
	int j;
	int islandCount = 0;

	if (grid == NULL || gridSize == 0) {
		return 0;
	}

	rowMax = gridSize;
	colMax = gridColSize[0];
	for (i = 0; i < rowMax; i++) {
		for (j = 0; j < colMax; j++) {
			if (grid[i][j] == '0') {
				continue;
			}
			islandCount++;
			wallk(i, j, grid, rowMax, colMax);
		}
	}
	return islandCount;
}

```
