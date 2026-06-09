### 解题思路
总体思路：表面积等于所有方块的表面积之和减去2倍相邻面积
1. 每个网格内的方块表面积之和：上底加下底加上侧边面积————根据示例一判断下底面也要计算,`ans+=grid[i][j]*4+2;`
2. 相邻两个网格间重复的面积等于方块数较少的网格中方块的数量，于是对每个网格，与其相邻的网格进行比较，将相邻的面积记录起来`count_adj+= min(grid[i][j],grid[new_x][new_y]);`
3. 最后`ans-=count_adj;`即为所求表面积


### 复杂度分析
时间复杂度：O(N²)，N为网格长度和宽度
空间复杂度：O(1)，只需要保存常量的方向向量

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = (int) grid[0].size();
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1}; 

        int count_adj=0,ans=0;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]!=0)
                {
                    ans+=(grid[i][j]*4+2);
                    for(int k=0;k<4;k++)
                    {
                        int new_x = i+x[k],new_y=j+y[k];
                        if((new_x>=0)&&(new_x<N)&&(new_y>=0)&&(new_y<N))
                        { 
                            count_adj+= min(grid[i][j],grid[new_x][new_y]);
                        }
                    }
                }
            }
        }
        ans-=count_adj;
        return ans;
    }
};
```