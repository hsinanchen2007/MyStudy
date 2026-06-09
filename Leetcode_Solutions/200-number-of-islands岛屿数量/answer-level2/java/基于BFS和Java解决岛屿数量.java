### 题解
这个题解基于BFS，首先创建一个vidited数组来看某一个点是否被访问过，遍历整个grid，判断每一个点是否时陆地以及是否访问过，并进行BFS，向四个方向搜索，不论搜索结果我是否是岛屿，将其的值设置为true，表示访问过，若为岛屿，则进入队列，继续搜索，随后遍历完整个grid，输出岛屿数

### 代码

```java
//地段
class block
    {
        char landtype;
        int xposition;
        int yposition;
    }
class Solution {
    boolean visited[][]=null;
    //记录岛屿的数量
    int counted=0;
    //记录陆地的方向
    int dir[][]=new int[][]{{0,1},{1,0},{-1,0},{0,-1}};
    //由于使用BFS方法，需建立一个全局map变量
    char[][] landmap=null;
    block start=null;
    block next=null;
    public void BFS(int x,int y)
    {
        start=new block();
        start.landtype=landmap[x][y];
        start.xposition=x;
        start.yposition=y;
        Queue<block> q=new LinkedList<block>();
        q.add(start);
        while(!q.isEmpty())
        {
            start=q.poll();
            if(start.landtype=='1')
            {
                visited[start.xposition][start.yposition]=true;
                //让岛屿尝试向四个方向
                for(int i=0;i<dir.length;i++)
                {
                    int newx=start.xposition+dir[i][0];
                    int newy=start.yposition+dir[i][1];
                    //判断新生成的地段是不是越界了
                    if(newx>=0&&newx<landmap.length&&newy>=0&&newy<landmap[0].length&&visited[newx][newy]==false)
                    {
                        //判断设工程的地段是不是岛屿
                        if(landmap[newx][newy]=='1')
                        {
                            //将岛屿加入队列中
                         next=new block();
                        next.xposition=newx;
                        next.yposition=newy;
                        next.landtype=landmap[newx][newy];
                        q.add(next);
                        }
                        //不论新找到的地块是不是岛屿，都设为已经访问，下一次进队列不涉及这个点
                         visited[newx][newy]=true;   
                    }
                }
            }else
            {
                visited[start.xposition][start.yposition]=true;
            }
        }
    }
    public int numIslands(char[][] grid) {
        if(grid==null||grid.length==0||(grid.length==1&&grid[0].length==0)) return 0;
        //拷贝map数组
        landmap=new char[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++)
        {
            landmap[i]=Arrays.copyOf(grid[i],grid[0].length);
        }
        //初始化visited数组
        visited=new boolean[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++)
        {
            for(int j=0;j<grid[0].length;j++)
            {
            visited[i][j]=false;
            //对于水面则让他设为被访问过
            if(grid[i][j]=='0')
                {
                visited[i][j]=true;
                }
            }
        }
        //对grid上每一个符合要求的点进行BFS
        for(int i=0;i<grid.length;i++)
        {
            for(int j=0;j<grid[0].length;j++)
            {
                //这个点若未访问并且是陆地，则进行BFS
                if(!visited[i][j]&&grid[i][j]=='1')
                {
                    BFS(i,j);
                    //增加一块岛屿
                    counted++;
                }               
            }
        }
        return counted;
    }
}
```