### 解题思路
使用bfs进行层序遍历，同时对所有陆地遍历，遍历过的海洋将值变更为2防止再次遍历
### 代码

```java
class Solution {
    
    public int maxDistance(int[][] grid) {
        int n = grid.length;
        if(n <= 1) return -1;
        int[][] directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        Queue<int[]> queue = new LinkedList<>();
        //首先将所有陆地都放进队列，进行层序遍历
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    queue.offer(new int[]{i,j});
                }
            }
        }
        //全是陆地或者海洋返回-1
        if(queue.size() == 0 || queue.size() == n*n){
            return -1;
        }

        int len = -1;
        while(!queue.isEmpty()){
            int size = queue.size();
            while(size-- > 0){
                int[] cur = queue.poll();
                int x = cur[0];
                int y = cur[1];
                
                for(int[] direction : directions){
                    int x1 = x + direction[0];
                    int y1 = y + direction[1];
                    //只要是海洋就放入队列,为了防止重复，将值变更为2
                    if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < n 
                    && grid[x1][y1] == 0){
                        grid[x1][y1] = 2;
                        queue.add(new int[]{x1, y1});
                    }
                    
                }
            }
            len++;
        }
        //遍历结束，所有的海洋都变为2
        return len;
    }

}
```