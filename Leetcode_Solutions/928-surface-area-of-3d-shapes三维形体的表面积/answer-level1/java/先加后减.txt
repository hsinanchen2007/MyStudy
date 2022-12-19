```Java
public int surfaceArea(int[][] grid) {
    int n = grid.length, area = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int level = grid[i][j];
            if (level > 0) {
                area += 4 * level + 2;
                if (i > 0) {
                    area -= Math.min(level, grid[i-1][j]) * 2;
                }
                if (j > 0) {
                    area -= Math.min(level, grid[i][j -1]) * 2;
                }
            }
        }
    }

    return area;
}
```
