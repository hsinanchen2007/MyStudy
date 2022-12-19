### 解题思路


### 代码

```java
class Solution {

    public int orangesRotting(int[][] grid) {
        Queue<int[]> has = new LinkedList<>();

        int count = 0; //表示新鲜橘子的数量

        int r = grid.length;    //行
        int c = grid[0].length; //列

        //遍历整个网格，统计新鲜橘子的数量并且将腐烂的橘子加入到队列中作为BFS的起点
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(grid[i][j] == 1) {
                    count++;
                } else if (grid[i][j] == 2) {
                    has.add(new int[]{i,j});
                }
            }
        }
        int times = 0;
        while(count > 0 && !has.isEmpty()) {
            times++;

            int n = has.size();

            //System.out.println(times + ":" + n);
            
            for (int i = 0; i < n; i++) {
                int[] temp = has.poll();
                int x = temp[0];
                int y = temp[1];
                    
                if (x-1 >= 0 && grid[x-1][y] == 1) {
                    grid[x-1][y] = 2;
                    has.add(new int[] {x-1,y});
                    count--;
                    //System.out.println(times + "上");
                }

                if (y-1>=0 && grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    has.add(new int[] {x,y - 1});
                    count--;
                    //System.out.println(times + "左");
                }

                if (x+1<r && grid[x+1][y] == 1) {
                    grid[x+1][y] = 2;
                    has.add(new int[] {x + 1,y});
                    count--;
                    //System.out.println(times + "下");
                }

                if (y+1<c && grid[x][y+1] == 1) {
                    grid[x][y+1] = 2;
                    has.add(new int[] {x,y + 1});
                    count--;
                    //System.out.println(times + "右");
                }
                


            }
        }

        return count != 0 ? -1 : times;
    }
}
```