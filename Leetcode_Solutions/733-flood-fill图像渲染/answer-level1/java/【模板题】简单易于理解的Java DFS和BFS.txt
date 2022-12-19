本题可以作为DFS和BFS的入门题，模板题。

这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！

**DFS模板**
```
dfs出口，不满足条件就退出

操作

递归，接着进一步DFS
```

**BFS模板**
```
条件判断（边界判断，其他要求的判断）

创建队列

在队列中加入第一个满足条件的元素

while(队列不为空) {
    取出队列头部元素
    操作
    根据头部元素，往队列中再次加入满足条件的元素
}
```

**详细代码**
DFS
```Java
private void dfs(int[][] image, int i, int j, int oldColor, int newColor) {
    int m = image.length, n = image[0].length;
    // dfs出口，不满足条件就退出
    if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != oldColor || image[i][j] == newColor) return;
    // 操作
    image[i][j] = newColor;
    // 递归，接着进一步DFS
    dfs(image, i-1, j, oldColor, newColor);
    dfs(image, i+1, j, oldColor, newColor);
    dfs(image, i, j-1, oldColor, newColor);
    dfs(image, i, j+1, oldColor, newColor);
}
```
BFS
```Java
private int[][] bfs(int[][] image, int sr, int sc, int newColor) {
    // 条件判断（边界判断，其他要求的判断）
    if (image == null || image.length == 0 || image[0].length == 0 || image[sr][sc] == newColor) return image;
    int m = image.length, n = image[0].length;
    // 创建队列
    Queue<int[]> queue = new LinkedList<>();
    int oldColor = image[sr][sc];
    // 在队列中加入第一个满足条件的元素
    queue.add(new int[]{sr, sc});
    while (!queue.isEmpty()) {
        // 取出队列头部元素
        int[] cur = queue.poll();
        int i = cur[0], j = cur[1];
        // 操作
        image[i][j] = newColor;
        // 根据头部元素，往队列中再次加入满足条件的元素
        if (i-1 >= 0 && image[i-1][j] == oldColor) queue.add(new int[] {i-1, j});
        if (i+1 < m && image[i+1][j] == oldColor) queue.add(new int[] {i+1, j});
        if (j-1 >= 0 && image[i][j-1] == oldColor) queue.add(new int[] {i, j-1});
        if (j+1 < n && image[i][j+1] == oldColor) queue.add(new int[] {i, j+1});
    }
    return image;
}
```