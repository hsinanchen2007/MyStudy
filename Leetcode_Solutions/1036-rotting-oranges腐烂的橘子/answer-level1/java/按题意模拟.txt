### 解题思路
按照题意进行模拟 首先定义一个变量为r，初始值为2(用处为标记矩阵中腐烂的橘子 且含有时间信息 如r=2代表初始就是腐烂的 r=3代表第一分钟被腐烂的... 以此类推 )，然后我们遍历矩阵，每一次遍历代表每一分钟，当找到一个腐烂的橘子即grid[x][y]==r 去寻找其上下左右的橘子 有新鲜的 就将其置为r+1代表下一分钟(即下一轮遍历中)要被腐烂。然后我们将r++继续遍历矩阵直至没有新鲜的橘子会被腐烂。最后在遍历一遍矩阵看看有无新鲜橘子 如有将r置为1 然后函数返回r-2即为题目所需答案

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        //directions
        int[] dr = new int[]{-1, 0, 1, 0};
        int[] dc = new int[]{0, -1, 0, 1};
        
        //rotten number
        int r = 2;
        boolean flag = false;

        int row = grid.length;
        int column = grid[0].length;
        while(true){
            for(int i=0;i<row;i++){
                for(int j=0;j<column;j++){
                    if(grid[i][j] == r){
                        for(int k=0;k<4;k++){
                            int x = i+dr[k];
                            int y = j+dc[k];
                            if(0<=x && x< row && 0<=y && y<column){
                                if(grid[x][y] == 1){
                                    flag = true;
                                    grid[x][y] = r+1;
                                }
                            }
                        }
                    }
                }
            }
            if(!flag) break;
            r++;
            flag = false;
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(grid[i][j] == 1) r=1;
            }
        }
        return r-2;
    }
}
```