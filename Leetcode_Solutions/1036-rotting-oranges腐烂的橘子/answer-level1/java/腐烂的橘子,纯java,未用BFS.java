### 解题思路
1.先遍历一次所有橘子,取得对应的信息:新鲜橘子的数目,腐烂橘子的数目和位置并记录在一个数组中
2.把储存腐烂橘子位置的数组进行遍历,并且对周围的橘子进行感染
3.判断是否所有的橘子已经被感染,或者有橘子不可能被感染等特殊情况
### 代码

```java
public class Solution {
    public int orangesRotting(int[][] grid) {
        int lenx = grid.length;
        int leny = grid[0].length;
        int min=0;
        int []fresh = new int[100];	//记录每分钟新鲜句子的数量,因为最多四分钟所有句子坏掉,所以数组长度为5即可

        while(true){
            int [][]pos = new int [100][2];

            int px=0;
            //遍历所有橘子,寻找新鲜的和腐烂的橘子
            for(int x=0;x<lenx;x++)
                for(int y=0;y<leny;y++)
                {
                    if(grid[x][y]==1)
                        fresh[min]++;	//记录新鲜的橘子
                    if(grid[x][y]==2){
                        pos[px][0] = x;	//先记录腐烂橘子的位置,后续再统一处理
                        pos[px][1] = y;
                        px++;
                    }
                }
            //统一处理腐烂橘子,px为烂橘子的数目
            for(int i=0;i<px;i++)
                {
                    int x = pos[i][0];
                    int y = pos[i][1];
                    if(x+1<lenx)		//确保输注不会越界
                        if(grid[x+1][y]==1)
                            grid[x+1][y]=2;
                    if(x-1>=0)
                        if(grid[x-1][y]==1)
                            grid[x-1][y]=2;
                    if(y+1<leny)
                        if(grid[x][y+1]==1)
                            grid[x][y+1]=2;
                    if(y-1>=0)
                        if(grid[x][y-1]==1)
                            grid[x][y-1]=2;
                }
            //如果没有腐烂的水果,或者没有新鲜的水果就退出循环
            if(fresh[min]==0)
                break;
            //如果腐烂的水果没有增加说明不可能腐烂了
            if(min-1>=0)		//确保数组不会越界
                if(fresh[min-1]==fresh[min]){
                    min=-1;
                    break;
                }
            if(min==0&&px==0){
                min=-1;
                break;
            }
            min=min+1;;
        }
        return min;
    }

}

```