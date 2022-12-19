### 解题思路
具体见注释。

### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        
        if(grid.length == 0) return 0;

        int height = grid.length;
        int width = grid[0].length;
        int count = 0;
        boolean [][] visited = new boolean [height][width];  //记录是否访问
        Queue<int[]> myqueue = new LinkedList<>();
        int dirs [][]= {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i = 0; i < height; i++){   //开始遍历
            for(int j = 0; j < width; j++){

                if(grid[i][j] == '0' || visited[i][j] == true)  continue; //已访问跳过
                
                myqueue.add(new int[]{i,j});    //初始添加第一个点
                visited[i][j] = true;

                while(!myqueue.isEmpty()){

                   int now [] = myqueue.poll();
                   for(int [] dir: dirs){      //四个方向

                       int i_now = dir[0] + now[0];
                       int j_now = dir[1] + now[1];

                        if(i_now>=0 && j_now>=0 && i_now < height && j_now < width && visited[i_now][j_now] == false && grid[i_now][j_now] == '1'){
                            myqueue.add(new int []{i_now,j_now} );
                            visited[i_now][j_now] = true;
                        }

                   }

                }
                count++;
            }
        }
    return count;
    }
}
```