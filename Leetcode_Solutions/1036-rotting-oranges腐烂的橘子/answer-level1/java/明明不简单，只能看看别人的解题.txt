### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        if(grid.length == 0 || grid[0].length == 0) return 0;
        int[] dir = {-1, 1, 0, 0};
        int[] cur = {0, 0, -1, 1};
        int fresh = 0;
        Deque<int[]> queue = new ArrayDeque<>(); 
        //把坏的橘子放入队列，开始遍历
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 2){
                    queue.offer(new int[] {i,j});
                    //如果队列的容量已满，offer()返回false
                }
            }
        }
        //bfs求最短路径
        while(!queue.isEmpty()){
            int size = queue.size();
            for(int i = 0; i < size; i++){
                int[] temp = queue.poll();
                for(int j = 0; j < dir.length; j++){
                    int x = temp[0] + dir[j];
                    int y = temp[1] + cur[j];
                    if(x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && grid[x][y] == 1){
                        grid[x][y] = 2;
                        queue.offer(new int[] {x,y});
                    }
                }
            }
            if(!queue.isEmpty()){
                fresh++;
            }
        }
        //遍历矩阵，判断是否还有未被感染的
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return fresh;
    }
}
```