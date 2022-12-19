### 解题思路
通过计数器c跟层节点数len控制BFS遍历

### 代码
####BFS常规思路
```BFS常规思路
void BFS()
{
    定义队列;
    定义备忘录，用于记录已经访问的位置；

    判断边界条件，是否能直接返回结果的。

    将起始位置加入到队列中，同时更新备忘录。

    while (队列不为空) {
        获取当前队列中的元素个数。
        for (元素个数) {
            取出一个位置节点。
            判断是否到达终点位置。
            获取它对应的下一个所有的节点。
            条件判断，过滤掉不符合条件的位置。
            新位置重新加入队列。
        }
    }

}
```


```java
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int m=grid.length,n=grid[0].length;
        if (grid[0][0]==1||grid[m-1][n-1]==1)return -1;
        grid[0][0]=1;
        //存储每个能走的节点的坐标
        Queue<int[]>q=new LinkedList<>();
        q.add(new int[]{0,0});
        int len=q.size();
        int c=0;
        int[][]dir={{1, 0}, {1, 1}, {1,-1}, {0, 1}, {0, -1}, {-1, 0},{-1, -1}, {-1, 1}};
        int path=1;
        while(!q.isEmpty()){
            //当前点坐标
            int[] data=q.poll();
            int x=data[0];
            int y=data[1];
            if (x==m-1&&y==n-1)return path;
            //尝试八连通
            for (int[] d:dir){
                int x1=x+d[0];
                int y1=y+d[1];
                //成功记录位置并阻塞
                if (x1>=0&&y1>=0&&x1<m&&y1<n&&grid[x1][y1]==0){
                    q.add(new int[]{x1,y1});
                    grid[x1][y1]=1;
                }
            }
            //记录每一层遍历节点数
            c++;
            //层遍历结束
            if (c==len){
                c=0;
                path++;
                len=q.size();
            }
        }
        return -1;
    }
}
```