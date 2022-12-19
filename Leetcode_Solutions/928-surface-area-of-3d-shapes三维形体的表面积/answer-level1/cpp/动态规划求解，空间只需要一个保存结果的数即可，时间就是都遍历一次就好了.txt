### 解题思路
思路很简单，我们把这个想成一个动态规划的题。我不是一下都放上去，我一个一个网格放，然后动态更新现在的表面积。单个网格的就简单了，4个数+2。好，继续放第二个，按理说表面积就是加了一个4个数加2。但是有覆盖的部分，那么覆盖了多少。首先我们是一个个挨着放的，所以只有上面和左面的网格会覆盖。比如这个格子上2个，上面的3个，左面的1个。左面覆盖了1*2*个面，上面覆盖了2*2个面。也就是少的那个的个数*2。当第一行时没有上面，第一列时没有左面。
思路就出来了，很简单。代码献上，这个比官方题解思路更简单，动态规划，时间和空间基本都是最佳。
主要思路就是把覆盖的面减掉就可以了，也不用说上下左右都得判断。我们只判断上左，右交给右边的左，下交给下边的上，这样的话每个情况就都一样了。
太迟了，顶不上去了答案应该。我觉得我是最佳。哈哈哈，做出题的人就是豪情万丈。

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==0)
                {
                    continue;
                }
                int up,left;
                if(i==0)
                {
                    up=0;
                }
                else
                {
                    up=grid[i-1][j];
                }
                if(j==0)
                {
                    left=0;
                }
                else
                {
                    left=grid[i][j-1];
                }
                count+=(4*grid[i][j]+2)-min(left,grid[i][j])*2-min(up,grid[i][j])*2;
            }
        }
        return count;
    }
};
```