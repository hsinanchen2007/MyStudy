### 解题思路
跟腐烂的橘子那道题本质是一样的。
腐烂的橘子：网格中腐烂的橘子能将新鲜的橘子全都腐败所需的最少天数，即从当前的currentQueueSize个腐烂的橘子出发（多个源点），寻找能遍历完网格中所有未腐烂的橘子的step数。
地图分析：从当前陆地（1，相当于腐烂的橘子）出发直到走到所有海洋（0，相当于新鲜的橘子）的最少时间。
### 代码

```java
import java.util.ArrayList;
class Solution {
    public int maxDistance(int[][] grid) {
        int i,j,k=0;
        int x,y=0;
        int max=0;
        int step=0;
        int N=grid.length;
        int[][] move={{1,0},{-1,0},{0,1},{0,-1}};
        Queue<Integer> queue=new LinkedList<>();
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(grid[i][j]==1){
                    queue.offer(getIndex(i,j,N));
                }
            }
        }
        if(queue.size()==0||queue.size()==N*N){
            return -1;
        }
        while(!queue.isEmpty()){
            int currentsize=queue.size();
            for(k=0;k<currentsize;k++){
                int head=queue.poll();
                x=head/N;
                y=head%N;
                for(i=0;i<4;i++){
                    int newX=x+move[i][0];
                    int newY=y+move[i][1];
                    if(panduan(newX,newY,N)&&grid[newX][newY]==0){
                        grid[newX][newY]=1;
                        queue.offer(getIndex(newX,newY,N));
                    }
                }
            }
            step++;
        }
        return step-1;
    }
    public int getIndex(int i,int j,int N){
        return N*i+j;
    }
    public boolean panduan(int i,int j,int N){
        if(i<N&&i>=0){
            if(j<N&&j>=0){
                return true;
            }
        }
        return false;
    }
}
```