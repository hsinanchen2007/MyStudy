### 解题思路
此代码，我是学习的别人的思路。详细解题思路：https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/lu-di-bu-duan-chang-da-zhi-dao-fu-gai-zheng-ge-di-/

### 代码

```c
int maxDistance(int **grid, int gridSize, int *gridColSize)
{
    int i,j;
    int p=0,l=0;
    int c_sea=0;
    for (i = 0; i <gridSize; i++)
        for (j = 0; j < gridSize; j++)
            if(grid[i][j]==0){
                c_sea++;
            }
    if(c_sea==0||c_sea==gridSize*gridSize)
        return -1;

    while(c_sea!=0){
    	p++;
        for(i=0;i<gridSize;i++)
            for(j=0;j<gridSize;j++)
                if(grid[i][j]==p){
                    if(i>0&&grid[i-1][j]==0){
                        grid[i-1][j]=p+1;
                        c_sea--;
                    }
                    if(j>0&&grid[i][j-1]==0){
                        grid[i][j-1]=p+1;
                        c_sea--;
                    }
                    if(i<gridSize-1&&grid[i+1][j]==0){
                        grid[i+1][j]=p+1;
                        c_sea--;
                    }
                    if(j<gridSize-1&&grid[i][j+1]==0){
                        grid[i][j+1]=p+1;
                        c_sea--;
                    }
                }
        l++;
    }
    
    return l;
}

```