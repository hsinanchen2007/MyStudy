### 解题思路
先遍历一遍，记下水和岛的坐标，再遍历所有水，对每个水再遍历所有岛计算距离最小值，这个最小值再和最终目标比较求最大的，这个代码有个没优化的地方：当每个水计算出的距离已经小于目标值时就可以跳过这个水的计算了

### 代码

```c
int dis(int xi,int yi,int xj,int yj)
{
    int dx=xi>xj?(xi-xj):(xj-xi);
    int dy=yi>yj?(yi-yj):(yj-yi);
    return dx+dy;
}

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int potSize=gridSize*gridSize;
    int land_x[potSize];
    int land_y[potSize];
    int water_x[potSize];
    int water_y[potSize];
    int land_cnt=0;
    int water_cnt=0;

    for(int i=0;i<gridSize;i++)
    {
        for(int j=0;j<*gridColSize;j++)
        {
            if(grid[i][j]==1)
            {
                land_x[land_cnt]=i;
                land_y[land_cnt]=j;
                land_cnt++;
            }
            else if(grid[i][j]==0)
            {
                water_x[water_cnt]=i;
                water_y[water_cnt]=j;
                water_cnt++;
            }
        }
    }

    int ans=-1;

    for(int i=0;i<water_cnt;i++)
    {
        int nearest_dis=201;
        int d;
        int wx=water_x[i];
        int wy=water_y[i];
        for(int j=0;j<land_cnt;j++)
        {
            d=dis(wx,wy,land_x[j],land_y[j]);
            nearest_dis=nearest_dis>d?d:nearest_dis;
        }
        if(nearest_dis<201)
            ans=ans>nearest_dis?ans:nearest_dis;
    }
    return ans;
}
```