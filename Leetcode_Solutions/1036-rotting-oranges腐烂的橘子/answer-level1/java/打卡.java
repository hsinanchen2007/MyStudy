### 解题思路
方法：多源广度优先搜索

思路：首先把所有腐烂的橘子加入队列中，作为第一层，然后进行广度优先搜索。最后检查是否还有未腐烂的橘子，如果有返回-1，如果没有返回时间。

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<int[]> q = new LinkedList<>();
        int count = 0;
        int M = grid.length;
        int N = grid[0].length;
        for(int i = 0;i<M;++i){
            for(int j = 0;j<N;++j){
                if(grid[i][j]==1)
                    count++;
                if(grid[i][j]==2)
                    q.add(new int[]{i,j});
            }
        }
        int time=0;
        while(!q.isEmpty()&&count!=0){
            time++;
            int n = q.size();
            for(int k=0;k<n;++k){
                int[] arr = q.poll();
                int r = arr[0];
                int c = arr[1];

                if(c-1>=0&&grid[r][c-1]==1){
                    count--;
                    grid[r][c-1]=2;
                    q.add(new int[]{r,c-1});
                }
                if(r-1>=0&&grid[r-1][c]==1){
                    count--;
                    grid[r-1][c]=2;
                    q.add(new int[]{r-1,c});
                }
                if(r+1<M&&grid[r+1][c]==1){
                    count--;
                    grid[r+1][c]=2;
                    q.add(new int[]{r+1,c});
                }
                if(c+1<N&&grid[r][c+1]==1){
                    count--;
                    grid[r][c+1]=2;
                    q.add(new int[]{r,c+1});
                }    
            }

        }
        if(count>0)
            return -1;
        else
            return time;
    }
}
```