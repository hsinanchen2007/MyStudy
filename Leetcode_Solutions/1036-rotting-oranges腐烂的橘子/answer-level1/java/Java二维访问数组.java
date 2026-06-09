添加一个二维访问数组note，记录橘子由新鲜变烂的时间。每次扫描所有橘子的状态。一开始所有烂橘子(2)的访问时间为1，接着烂橘子相邻的新鲜橘子(1)访问时间变为2，以此继续重复下去。如果某次扫描没有橘子的状态发生变化，则跳出while循环。最后再扫描一遍橘子的状态，如果没有新鲜橘子(1)，则输出所有橘子变腐烂的最后时间，注意times要减一；否则，输出-1，表明仍然有新鲜橘子。
执行用时 : 5 ms, 在Rotting Oranges的Java提交中击败了94.32% 的用户
内存消耗 : 35.5 MB, 在Rotting Oranges的Java提交中击败了91.56% 的用户
```
class Solution {
    public int orangesRotting(int[][] grid) {
        int times = 1;
        boolean flag = true;
        int[][] note = new int[grid.length][grid[0].length];
        for(int i=0; i<note.length; i++){
            for(int j=0; j<note[0].length; j++){
                if(grid[i][j]==2){
                    note[i][j] = times;
                }else{
                    note[i][j] = 0;
                }
            }
        }
        while(flag){
            flag = false;
            for(int i=0; i<grid.length; i++){
                for(int j=0; j<grid[0].length; j++){
                    if(grid[i][j]==2&&note[i][j]==times){
                        if(i>0&&grid[i-1][j]==1){
                            grid[i-1][j] = 2;
                            note[i-1][j] = times+1;
                            flag = true;
                        }
                        if(i<grid.length-1&&grid[i+1][j]==1){
                            grid[i+1][j] = 2;
                            note[i+1][j] = times+1;
                            flag = true;
                        }
                        if(j>0&&grid[i][j-1]==1){
                            grid[i][j-1] = 2;
                            note[i][j-1] = times+1;
                            flag = true;
                        }
                        if(j<grid[i].length-1&&grid[i][j+1]==1){
                            grid[i][j+1] = 2;
                            note[i][j+1] = times+1;
                            flag = true;
                        }
                    }
                }
            }
            if(flag){
                times++;;
            }
        }
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return times-1;
    }
}
```