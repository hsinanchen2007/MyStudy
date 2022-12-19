### 解题思路
* 此题相当于起点为腐烂的橘子，遍历完新鲜的橘子的最短路径的问题
* 首先将腐烂的橘子全部放到队列中，再进行BFS
* 最后需要判断是否还存在新鲜的橘子，若存在，返回-1，若不存在，返回时间
### 代码

```java
class Solution {
    final int[][] direction = {{1,0},{0,1},{0,-1},{-1,0}}; 
    public int orangesRotting(int[][] grid) {
        int minute = 0;
        int m = grid.length;
        int n = grid[0].length;
        Queue<Pair<Integer,Integer>> que = new LinkedList<>();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    que.offer(new Pair<>(i,j));
                }
            }
        }

        while(!que.isEmpty()){
            int size = que.size();
            
            while(size-- > 0){
                Pair<Integer,Integer> pair = que.poll();
                int x = pair.getKey();
                int y = pair.getValue();
                for(int[] d : direction){
                    int x1 = x + d[0];
                    int y1 = y + d[1];
                    if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid[x1][y1] == 1){
                        grid[x1][y1] = 2;
                        que.offer(new Pair<>(x1,y1));
                    }
                }
            }
            if(!que.isEmpty()){
                minute++;
            }
            
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minute;
    }
}
```