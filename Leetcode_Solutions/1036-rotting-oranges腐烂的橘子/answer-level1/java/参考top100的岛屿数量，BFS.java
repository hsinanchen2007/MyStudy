### 解题思路
参考top100的岛屿数量，BFS
### 代码

```java
class Solution {

    public int orangesRotting(int[][] grid) {
        int minute = 0;
        int rows = grid.length;
        int columns = grid[0].length;
        int[][] direct = new int[][]{{0,1},{1,0},{0,-1},{-1,0}};
        Queue<int[]> queue = new LinkedList<>();
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]==2){
                    queue.offer(new int[]{i,j});
                }
            }
        }
        while(!queue.isEmpty()){
            int len = queue.size();
            for(int i=0;i<len;i++){
                int[] temp = queue.poll();
                int cur_row = temp[0];
                int cur_col = temp[1];
                for(int j=0;j<direct.length;j++){
                    int new_cow = cur_row+direct[j][0];
                    int new_col = cur_col+direct[j][1];
                    if(new_cow<rows&&new_col<columns&&new_cow>=0&&new_col>=0){
                        if(grid[new_cow][new_col]==1){
                            grid[new_cow][new_col] = 2;
                            queue.offer(new int[]{new_cow,new_col});
                        }
                        
                    }
                }
            }
            if(!queue.isEmpty()) minute++;
        }
        for(int i=0;i<rows;i++){
            boolean flag = false;
            for(int j=0;j<columns;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minute;
    }
}
```