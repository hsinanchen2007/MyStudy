遍历矩阵，计算值大于0的个数（z轴投影），同时计算各行（x轴投影）各列（y轴投影）的最大值，
将0的个数与各行各列最大值相加即为所有投影面积的和
``` C++ []
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            int maxRow=0;
            int maxCol=0;
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]>0) res++;
                maxRow=max(grid[i][j],maxRow);
                maxCol=max(grid[j][i],maxCol);
            }
            res=res+maxRow+maxCol;
        }
        return res;
    }
};
```