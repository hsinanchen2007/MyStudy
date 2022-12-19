### 解题思路
1. 首先，先不考虑面积重叠问题，统计出所有立方体的总面积，利用一个双重循环就够了；
2. 对于面积重叠我分为三种情况：
    - 第一种是同一层的立方体上下面重叠，这种情况重叠的面积为2*(n-1)（n为对应位置的立方体数目）；
    - 第二种是当前位置立方体与其左方的重叠面积，这种情况下需要选出当前位置立方体和其左方的立方体数的最小值min，则重叠的面积为2*m；
    - 第三种为当前位置立方体与其下方的重叠面积，这种情况的计算方法与第二种相同，同样需要先找出当前位置立方体数和其下方位置立方体数的最小值m,重叠的面积为2*m;
3.最后将总面积减去重叠面积即可。 

### 代码

```c
#define FINDMIN(x,y) (x<y)?x:y

int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int sum = 0;
    int sub = 0;
    int i,j,m;
    
    //统计所有正方形的所有面之和
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[0];j++)
        {
            sum += grid[i][j] * 6;
        }
    }

    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[0];j++)
        {
            m = grid[i][j];
            if(m)
            {
                //寻找同一层上下立方体重叠的面
                
                sub += 2*(m-1);
                if(i+1 < gridSize)
                    sub =sub + 2*(FINDMIN(m,grid[i+1][j]));
                if(j+1<gridColSize[0])
                    sub =sub + 2*(FINDMIN(m,grid[i][j+1]));
            }
        }
    }

    return sum - sub;
}
```