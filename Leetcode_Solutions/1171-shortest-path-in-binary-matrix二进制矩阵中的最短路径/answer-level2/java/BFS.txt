### 解题思路
走过的路线进行标记，每次探索8个方向。

### 代码

```java
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int len = grid.length;
        if (grid[0][0] == 1 || grid[len-1][len-1] == 1)
            return -1;
        if (len == 1 && grid[0][0] != 0)
            return -1;
        int[][] vector = new int[][]{{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        Queue<int[]> queue = new LinkedList<>();
        int[][] visited = new int[len][len];
        queue.add(new int[]{0,0});
        visited[0][0] = 1;
        int cnt = 1;
        while (!queue.isEmpty()){
            int size = queue.size();
            while (size-- != 0){
                int[] temp = queue.poll();
                if (temp[0] == len-1 && temp[1] == len-1)
                    return cnt;
                for (int[] ints : vector) {
                    int r = temp[0] + ints[0];
                    int c = temp[1] + ints[1];
                    if (r >= 0 && r < len && c >= 0 && c < len && visited[r][c] == 0){
                        if (grid[r][c] == 0){
                            queue.add(new int[]{r,c});
                            visited[r][c] = 1;
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
}
```