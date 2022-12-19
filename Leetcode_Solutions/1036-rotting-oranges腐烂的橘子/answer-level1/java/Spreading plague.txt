### 解题思路
是一个类似与层序遍历的解题方法。方法我都懂，但是学习了题解里面用一个类来表示orange,真的方便又好用。
![43v1528553893.png](https://pic.leetcode-cn.com/c3eaa6899a035d1c4721a4e9523f068f471151c0e86c9182361dedf9ef241459-43v1528553893.png)
### 代码

```java
class Solution {
    class orange{
        int x,y,timer;
        public orange(int i,int j, int time){
            x=i;
            y=j;
            timer=time;
        }
    }
    public int orangesRotting(int[][] grid) {
        int row=grid.length;//多少个数组,这是y轴
        int col=grid[0].length;//每个数组的长度，这是x轴
        int timeC=0;

        Queue<orange> Spread=new LinkedList<orange>();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    Spread.offer(new orange(i,j,timeC));
                }
            }
        }

        while(!Spread.isEmpty()){
            orange before=Spread.poll();
            timeC=before.timer;

            if(before.x-1>=0&&grid[before.x-1][before.y]==1){//右不越界
                grid[before.x-1][before.y]=2;
                Spread.offer(new orange(before.x-1,before.y,timeC+1));
            }
            if(before.y-1>=0&&grid[before.x][before.y-1]==1){//左不越界
                grid[before.x][before.y-1]=2;
                Spread.offer(new orange(before.x,before.y-1,timeC+1));
            }
            if(before.y+1<col&&grid[before.x][before.y+1]==1){//上不越界
                grid[before.x][before.y+1]=2;
                Spread.offer(new orange(before.x,before.y+1,timeC+1));
            }
            if(before.x+1<row&&grid[before.x+1][before.y]==1){//下不越界
                grid[before.x+1][before.y]=2;
                Spread.offer(new orange(before.x+1,before.y,timeC+1));
            }

        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return timeC;

    }
}
```