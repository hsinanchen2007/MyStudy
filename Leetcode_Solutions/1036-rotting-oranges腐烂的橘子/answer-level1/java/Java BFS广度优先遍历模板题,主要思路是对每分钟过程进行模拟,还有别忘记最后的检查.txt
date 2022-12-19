### 解题思路

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        
        int minute = 0;
        LinkedList<int[]> queue = new LinkedList<>();
        // 将腐烂的橘子先放入队列 
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==2) queue.add(new int[]{i,j});
            }
        }
        // 对腐烂的橘子进行广度优先遍历
        int[][] steps = new int[][]{{0,1},{1,0},{0,-1},{-1,0}};
        while(queue.size()!=0){
            int count = queue.size();
            while(count>0){
                int[] temp = queue.pollFirst();
                count--;
                for(int[] step:steps){
                    int x = temp[0]+step[0];
                    int y = temp[1]+step[1];
                    if(x<0||x>=grid.length||y<0||y>=grid[0].length||grid[x][y]!=1){
                        continue;
                    }
                    grid[x][y] = 2;
                    queue.add(new int[]{x,y});
                }
            }
            if(queue.size()!=0) minute++;
        }
        //检查是否存在未被腐烂的橘子
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return minute;
    }
}
```