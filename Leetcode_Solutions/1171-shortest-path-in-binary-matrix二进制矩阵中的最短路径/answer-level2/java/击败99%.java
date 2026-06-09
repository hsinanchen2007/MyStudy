### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        // 几种特殊情况
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0){
            return -1;
        }   
        if(n == 1){
            return 1;
        }

        // 按广度搜索,最先到达的路径即为最短的路径
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        // 改动0为1，表示已经遍历过了
        grid[0][0] = 1;
        // 路径
        int pathLen = 0;
        // 可以往八个方向移动,放到二维数组里
        int[][] direction = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        while(!queue.isEmpty()){
            // 把同一层的一起释放掉，一起释放的路径相同
            pathLen++;
            int size = queue.size();
            while(size-- > 0){
                int[] point = queue.poll();
                for(int[] d : direction){
                    int x = point[0] + d[0];
                    int y = point[1] + d[1];
                    if(x == n-1 && y == n-1){
                        return pathLen + 1;
                    }
                    if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0){
                        queue.offer(new int[]{x, y});
                        grid[x][y] = 1;
                    }
                }
            }
        }
        return -1;       
    }
}
```