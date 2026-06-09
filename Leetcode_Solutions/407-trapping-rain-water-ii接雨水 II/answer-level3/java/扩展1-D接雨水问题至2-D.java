1-D的接雨水问题有一种解法是从左右两边的边界往中间不断进行收缩，收缩的过程中，对每个坐标（一维坐标）能接的雨水进行求解
```
public int trap(int[] height) {
    int left = 0, right = height.length-1;
    int leftMax = 0, rightMax = 0, res = 0;
    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] > leftMax) {
                leftMax = height[left];
            }
            else {
                res += leftMax - height[left];
            }
            left++;
        }
        else {
            if (height[right] > rightMax) {
                rightMax = height[right];
            }
            else {
                res += rightMax - height[right];
            }
            right--;
        }
    }
    return res;
}
```
2-D的接雨水问题的边界不再是线段的两个端点，而是矩形的一周，所以我们用优先队列维护所有边界点，收缩时，也不仅仅只有左右两个方向，而是上下左右四个方向，并且维护一个visit的数组，记录哪些坐标已经被访问过，不然会造成重复求解。
```
public int trapRainWater(int[][] heightMap) {
    if (heightMap == null || heightMap.length <= 2 || heightMap[0].length <= 2)
        return 0;
    PriorityQueue<Cell> queue = new PriorityQueue<>(Comparator.comparingInt((Cell cell) -> cell.height));
    int m = heightMap.length;
    int n = heightMap[0].length;
    boolean[][] visited = new boolean[m][n];
    for (int i = 0; i < m; i++) {
        visited[i][0] = visited[i][n-1] = true;
        queue.add(new Cell(i, 0, heightMap[i][0]));
        queue.add(new Cell(i, n-1, heightMap[i][n-1]));
    }
    for (int i = 1; i < n-1; i++) {
        visited[0][i] = visited[m-1][i] = true;
        queue.add(new Cell(0, i, heightMap[0][i]));
        queue.add(new Cell(m-1, i, heightMap[m-1][i]));
    }
    int result = 0;
    int[][] bounds = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!queue.isEmpty()) {
        Cell cell = queue.poll();
        for (int[] bound : bounds) {
            int row = cell.row + bound[0];
            int col = cell.col + bound[1];
            if (row >= 0 && row < m && col >= 0 && col < n && !visited[row][col]) {
                result += Math.max(0, cell.height - heightMap[row][col]);
                visited[row][col] = true;
                queue.add(new Cell(row, col, Math.max(cell.height, heightMap[row][col])));
            }
        }
    }
    return result;
}

private static class Cell {
    private int row;
    private int col;
    private int height;

    public Cell(int row, int col, int height) {
        this.row = row;
        this.col = col;
        this.height = height;
    }
}
```

