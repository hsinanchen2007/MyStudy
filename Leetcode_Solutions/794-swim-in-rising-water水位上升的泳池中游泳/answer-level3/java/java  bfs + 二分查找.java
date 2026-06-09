### 解题思路

思路是 找到一个值val，存在一条路径，该条路径上从头到尾所有的值<=val

找到是否存在这条路径使用bfs，广度优先搜索

确定这个值使用二分查找，在所有的矩阵值的最大和最小值之间二分

### 代码

```java
class Solution {
    public int swimInWater(int[][] grid) {
        int max=0;
        int min= Integer.MAX_VALUE;
        int xlen = grid.length;
        int ylen = grid[0].length;
        
        for(int i=0 ; i<xlen ; i++){
            for(int j=0 ;j<ylen ; j++){
                max = Math.max(grid[i][j],max);
                min = Math.min(grid[i][j],min);
            }
        }
        int start = min;
        int end = max;
        Queue<int[]> queue = new LinkedList<>();
        
        int[][] dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        
        
        while(start<end){
            int mid = (start + end)/2;
            if(grid[0][0]>mid){
                start = mid+1;
                continue;
            }
            
            queue.offer(new int[]{0,0});
            boolean isEnd = false;
            boolean[][] visited = new boolean[xlen][ylen];
            visited[0][0] = true;
            
            while(!queue.isEmpty()){
                int size = queue.size();
                for(int i=0 ; i<size ; i++){
                    int[] index = queue.poll();
                    if(index[0]==xlen-1 && index[1]==ylen-1){
                        isEnd =true;
                        break;
                    }
                    for(int[] dir : dirs){
                        int x = dir[0] + index[0];
                        int y = dir[1] + index[1];
                        
                        if(x>=0 && x<xlen && y>=0 && y<ylen && !visited[x][y] && grid[x][y]<=mid){
                            queue.offer(new int[]{x,y});
                            visited[x][y]=true;
                        }
                    }
                }
                
            }          
            if(isEnd){
                end = mid;
            } else{
                start = mid+1;
            }
            queue.clear();
            
        }       
        return start;     
    }  
}
```