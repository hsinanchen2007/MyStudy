class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        //计算每个格子的v的贡献，如果v>0,则上下底面贡献2
        //然后计算四个侧面的贡献度为每个侧面高出相邻的v的高度，即max(v-nv,0);
        int m=grid.size();
        vector<vector<int>> gridcopy(m+2,vector<int>(m+2,0));
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                gridcopy[i][j]=grid[i-1][j-1];
            }
        }
        int res=0;
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(gridcopy[i][j]!=0)
                {
                    res+=2;
                    res+=max(gridcopy[i][j]-gridcopy[i-1][j],0);
                    res+=max(gridcopy[i][j]-gridcopy[i+1][j],0);
                    res+=max(gridcopy[i][j]-gridcopy[i][j+1],0);
                    res+=max(gridcopy[i][j]-gridcopy[i][j-1],0);
                }
            }
        }
        return res;
    }
};