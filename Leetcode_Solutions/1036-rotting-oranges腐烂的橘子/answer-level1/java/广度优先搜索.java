## 思路
广度优先搜索。和树的层次遍历时一样的思想，只不过左右儿子变成了与之相邻的四个橘子。思想一样，还是用队列存储当前腐烂的橘子
## 代码
```
class Solution {
    public int orangesRotting(int[][] grid) {

        Queue<Pos> q=new LinkedList<>();
        int totalRow=grid.length;
        int totalCol=grid[0].length;
        for(int i=0;i<totalRow;i++){//初始化队列，将一开始的烂橘子加入队列中
            for(int j=0;j<totalCol;j++){
                if(grid[i][j]==2)
                    q.add(new Pos(i,j,0));
            }
        }
        
        int maxMinute=0;
        int[][] helper={{1,0},{-1,0},{0,1},{0,-1}};//辅助数组，用于确定烂橘子传播的范围
        while(!q.isEmpty()){
            Pos current=q.poll();
            maxMinute=current.minute;
            for(int k=0;k<4;k++){
                int newRow=current.row+helper[k][0];
                int newCol=current.col+helper[k][1];
                if(newRow>=0&&newRow<totalRow&&newCol>=0&&newCol<totalCol&&grid[newRow]                                                                                 [newCol]==1){
                    q.add(new Pos(newRow,newCol,current.minute+1));
                    grid[newRow][newCol]=2;
                }
                     
            }
        }

        for(int i=0;i<totalRow;i++){//感染完了如果还有橘子没烂，则返回-1；
            for(int j=0;j<totalCol;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }

        return maxMinute;

    }
}
class Pos{//模拟层次遍历树时树的节点
    int row;
    int col;
    int minute;
    public Pos(int row,int col,int minute){
        this.row=row;
        this.col=col;
        this.minute=minute;
    }
}
```
