### 解题思路
此处撰写解题思路
任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂,也就是上下左右四个方向开始腐烂
将腐烂的橘子的坐标放到队列中,开始判断腐烂橘子的四个方向,是否是好橘子,开始腐烂.
最终队列中没有腐烂橘子时候并且好橘子还存在说明不可能全腐烂完返回-1;
### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        //记录坏橘子的坐标
        LinkedList<int[]> queue=new LinkedList<>();
        //记录好橘子
        int good=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]==1){
                    //好橘子加1;
                    good++;
                }else if(grid[i][j]==2){
                    //记录坏橘子的坐标
                    queue.add(new int[]{i,j});
                }
            }
        }
        //如果好橘子是0直接返回0
        if(good==0){
            return 0;
        }
        //记录结果
        int result=0;
        //行与列的值
        int row=grid.length,column=grid[0].length;
        while(!queue.isEmpty()&&good>0){
            result++;
            int size=queue.size();
            for(int i=0;i<size;i++){
                //每一次弹出一个坏橘子开始腐烂,
                int[]nums=queue.poll();
                //坏橘子的坐标
                int a=nums[0],b=nums[1];
                //上
                if(a-1>=0&&grid[a-1][b]==1){
                    grid[a-1][b]=2;
                    //将新的产生的腐烂橘子放到队列中
                    queue.add(new int[]{a-1,b});
                    good--;
                }
                //下
                if(a+1<row&&grid[a+1][b]==1){
                    grid[a+1][b]=2;
                    queue.add(new int[]{a+1,b});
                    good--;
                }
                //左
                if(b-1>=0&&grid[a][b-1]==1){
                    grid[a][b-1]=2;
                    queue.add(new int[]{a,b-1});
                    good--;
                }
                //右
                if(b+1<column&&grid[a][b+1]==1){
                    grid[a][b+1]=2;
                    queue.add(new int[]{a,b+1});
                    good--;
                }
            }
        }
        if(good>0){
            return -1;
        }
        return result;
    }
}
```