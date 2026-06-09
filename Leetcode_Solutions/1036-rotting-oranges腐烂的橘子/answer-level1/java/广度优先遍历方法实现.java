### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public int orangesRotting(int[][] grid) {
        int freshNum=0;
        LinkedList<Integer> queue=new LinkedList<>();
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1){
                    freshNum++;
                }
                if(grid[i][j]==2){
                    queue.add(i*10+j);
                }
            }
        }
        if(queue.isEmpty()){
            return freshNum>0?-1:0;
        }
        int len=queue.size();
        int step=0;
        while(!queue.isEmpty()){
                int pos=queue.poll();
                int x=pos/10;
                int y=pos%10;
                grid[x][y]=0;
                if(x+1<grid.length&&grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    queue.offer((x+1)*10+y);
                    freshNum--;
                }
                if(x-1>=0&&grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    queue.offer((x-1)*10+y);
                    freshNum--;
                }
                if(y+1<grid[0].length&&grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    queue.offer((x)*10+y+1);
                    freshNum--;
                }
                if(y-1>=0&&grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    queue.offer((x)*10+y-1);
                    freshNum--;
                }
                len--;
                if(len==0){
                    step++;
                    len=queue.size();
                }
        }
        return freshNum==0?step-1:-1;
    }
}
```