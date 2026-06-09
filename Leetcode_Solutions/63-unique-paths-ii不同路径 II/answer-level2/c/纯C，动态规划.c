### 解题思路
![image.png](https://pic.leetcode-cn.com/bdd87889da30c080c7bfae87deb6867f97c705aef5c9e60de215b58aad5038de-image.png)

基于62题的思路，稍作修改：
在第0行和第0列遇到障碍后的所有格子均不能到达；
然后每次遇到障碍，则将此位置置0

### 代码

```c
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    if(obstacleGrid[obstacleGridSize-1][*obstacleGridColSize-1]==1)
        return 0;

    long route_amount[101][101]={{0,},};
    route_amount[0][0]=1;
    int i,j;

    for(i=0;i<obstacleGridSize;i++)
    {
        if(obstacleGrid[i][0]==1)
            break;
        route_amount[i][0]=1;//只能从上面来
    } 
    for(j=0;j<*obstacleGridColSize;j++)
    {
        if(obstacleGrid[0][j]==1)
            break;
        route_amount[0][j]=1;//只能从左面来
    } 
    for(int m=1;m<obstacleGridSize;m++)
    {
        for(int n=1;n<*obstacleGridColSize;n++)
        {
            if(obstacleGrid[m][n]==1)
                route_amount[m][n]=0;
            else
                route_amount[m][n]=route_amount[m-1][n]+route_amount[m][n-1];
        }
    }
    return route_amount[obstacleGridSize-1][*obstacleGridColSize-1];
}
```