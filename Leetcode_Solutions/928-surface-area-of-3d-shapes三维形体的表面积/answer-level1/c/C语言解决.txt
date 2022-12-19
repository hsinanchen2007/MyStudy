### 解题思路
1. 所有立方体表面积之和 - 上下重合面积之和 - 前后左右重合面积之和
2. 详见代码注释

### 代码

```c
// 所有立方体表面积之和 - 上下重合面积之和 - 前后左右重合面积之和

bool isInArea(int x, int y, int size)
{
    return x >= 0 && x < size && y >= 0 && y < size;
}

int AREA[4][2] = {{0, 1},
                  {1, 0},
                  {0, -1},
                  {-1, 0}};


int surfaceArea(int** grid, int gridSize, int* gridColSize)
{
    if (grid == NULL || gridSize == 0 || gridColSize == NULL) {
        return 0;
    }

    // 1.求所有立方体表面积之和
    int allArea = 0;
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            count += grid[i][j];
        }
    }
    allArea = count * 6;

    // 2. 求上下重合面积之和
    int sidesArea = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j] > 1) {
                sidesArea += (grid[i][j] - 1) * 2;
            }
        }
    }

    // 3. 求前后左右重合面积之和
    int surroundArea = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j] == 0) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int newX = i + AREA[k][0];
                int newY = j + AREA[k][1];
                if (isInArea(newX, newY, gridSize)) {
                    if (grid[newX][newY] >= grid[i][j]) {
                        surroundArea += grid[i][j];
                    } else {
                        surroundArea += grid[newX][newY];
                    }
                }
            }
        }
    }

    return allArea - sidesArea - surroundArea;    
}
```