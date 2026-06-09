### 解题思路
递归：深度优先算法（DFS），遇到1，就将岛屿数量加一，同时访问周边是否相邻的1，如果遇到联通的1就置为0，这样，就不导致重复计算 
迭代：广度优先算法（BFS）,使用队列保存四个方向四个点处的坐标，判断是否是1  
递归的解法如果想用迭代的方法解决，最常用的办法是借助队列或者堆栈解决 
DFS的迭代应该可以采用堆栈来解决，没有仔细考虑  

### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        int num = 0;
        for(int i=0;i<grid.length;i++)
            for(int j =0;j<grid[i].length;j++){
                Queue<int[]> q = new LinkedList();
                //BFS
                if(grid[i][j]=='1'){
                    q.add(new int[]{i,j});
                    // System.out.print(i);
                    // System.out.println(j);
                    while(!q.isEmpty()){
                        int[] xy = q.poll();
                        // System.out.print(xy[0]);
                        // System.out.println(xy[1]);    
                        if(grid[xy[0]][xy[1]] == '1'){
                            grid[xy[0]][xy[1]] = '0';
                            if(xy[0]+1 < grid.length)
                                q.add(new int[]{xy[0]+1,xy[1]});

                            if(xy[1]+1 < grid[i].length)
                                q.add(new int[]{xy[0],xy[1]+1});

                            if(xy[0] >= 1)
                                q.add(new int[]{xy[0]-1,xy[1]});

                            if(xy[1] >= 1)   
                                q.add(new int[]{xy[0],xy[1]-1});
                            }
                    }
                    num++;
                    //System.out.println(num);
                }  
            }
        return num;
    }
    public void dfs(int i,int j,char[][]grid){
        if(grid[i][j]=='1'){
            grid[i][j] = '0';
            if(i+1<grid.length)
                dfs(i+1,j,grid);
            if(j+1<grid[i].length)
                dfs(i,j+1,grid);
            if(i>=1)
                dfs(i-1,j,grid);
            if(j>=1)
                dfs(i,j-1,grid);
        }else return;
    }
}
```