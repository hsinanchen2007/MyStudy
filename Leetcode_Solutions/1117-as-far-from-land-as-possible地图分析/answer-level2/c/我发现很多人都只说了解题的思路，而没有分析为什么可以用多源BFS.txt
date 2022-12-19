### 解题思路
1. 首先我们要理解“曼哈顿距离”这个概念：abs(x0-x1)+abs(y0-y1)。这其实就是每上/左/下/右移动一次，距离就加1。看到这里，我们就应该想到，这与BFS层次遍历的每遍历一层，层数加1，是有关的。
2. 拿到了BFS的基本想法，最直观的思路：遍历每一个海洋，由海洋(0)为源点，层次遍历，当第一次遍历到陆地(1)，就保存并比较此时的层次数，最后得到一个最大值输出即可。这种思路很直观，但我们可以看到，海洋(0)的数目往往是大于或远大于陆地(1)的数目，这样遍历会导致运行时间变大。
3. 那我们就想到了，可不可以反其道而行之，以陆地(1)为源点，去BFS遍历海洋(0)呢？这就涉及到了“多源BFS遍历”的问题，题解里有一位大佬的动画分析非常直观清晰明了，大家可以去看看，就在置顶页。
4. 我在这里主要分析一下，为什么可以用多源来解：首先将陆地(1)全部入队，然后BFS遍历海洋(0)，如果遍历到一个点，要再往下遍历海洋(0)时，发现要往下遍历的这个海洋(0)已经先被其他的陆地(1)遍历了，说明这个海洋(0)应该是距离先遍历它的那个陆地(1)更近。
![1336_ex1.jpeg](https://pic.leetcode-cn.com/48b18297b81d4fd45f6d50fcf74392ec3d8c5d81c85c1f44a1aff8397b45f47a-1336_ex1.jpeg)
借用示例1的图，以(0,,0)为源点层序遍历两次到(1,1)时，发现(1,2)和(2,1)两个海洋已经被(2,2)的陆地遍历过了，说明(1,2)和(2,1)距离(2,2)的陆地更近，不需要再往下遍历了。

p.s.:不知道这样说大家懂了没有，希望能给大家帮助。这道题的英文题目更好理解一些，附在这里：find a water cell such that its distance to the nearest land cell is maximized and return the distance.

### 代码

```c
typedef struct{
    int x;
    int y;
    int level;
}land;
int maxDistance(int** grid, int gridSize, int* gridColSize){
    int line=gridSize, col=*gridColSize;
    land *queue=(land*)malloc(sizeof(land)*line*col);
    int move[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int front=0, rear=0, flag=0;
    int tx,ty,tl,xx,yy;
    int i,j;
    for(i=0;i<line;i++)
        for(j=0;j<col;j++)
            if(grid[i][j]==1){
                queue[rear].x=i;
                queue[rear].y=j;
                queue[rear++].level=0;
            }
    while(front!=rear){
        tx=queue[front].x;
        ty=queue[front].y;
        tl=queue[front++].level;
        for(i=0;i<4;i++){
            xx=tx + move[i][0];
            yy=ty + move[i][1];
            if(xx<0||xx>=line||yy<0||yy>=col)
                continue;
            if(grid[xx][yy]==0){
                flag=1;
                grid[xx][yy]=2;
                queue[rear].x=xx;
                queue[rear].y=yy;
                queue[rear++].level=tl+1;
            }
        }
    }
    return flag==1?tl:-1 ;
}
```