### 解题思路
BFS 解法，BFS 的套路就是通过队列保存未访问的节点，然后从队列取节点，搜索其四个方向，再将满足条件的节点加入队列。
这个题目跟普通 BFS 不太一样的是，它找的是 BFS 多少层，所以先把所有的第一层元素加进来（即所有陆地），然后一层一层遍历。
蒟蒻的思路~~

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int[][] directions = new int[][]{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int rows = grid.length;
        int cols = grid[0].length;
        
        Queue<int[]> queue = new LinkedList<>();
        // 先把所有的陆地加进队列
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1){
                    queue.add(new int[]{i, j});
                }
            }
        }
        if (queue.isEmpty() || queue.size() == rows * cols) return -1; // 所有都是海洋 或者都是陆地

        int count = -1; // 遍历的层数，因为第一次遍历陆地的时候是不算距离的，这边从-1开始
        while (!queue.isEmpty()){
            count++; // 开始遍历第一层
            int layer = queue.size(); // 第一层要遍历的节点数
            for (int i = 0; i < layer; i++) {
                int[] top = queue.poll();
                int x = top[0];
                int y = top[1];
                // 从该节点进行广搜
                for (int k = 0; k < 4; k++) {
                    int newX = x + directions[k][0];
                    int newY = y + directions[k][1];
                    // 判断搜索到的节点是否有效并且是海洋
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 0){
                        grid[newX][newY] = -1; // 这块海洋已经访问过了
                        queue.add(new int[]{newX, newY});
                    }
                }
            }
        }
        return count;
    }
}
```