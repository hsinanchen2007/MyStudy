class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int sum=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                sum+=grid[i][j];
        int area=sum*6;
        //俯视重叠
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]>1)
                    area-=(grid[i][j]-1)*2;
        //侧视重叠
        for(int i=0;i<n;i++)
            for(int j=0;j<n-1;j++)
                area-=min(grid[i][j],grid[i][j+1])*2;
        //正视重叠
        for(int i=0;i<n;i++)
            for(int j=0;j<n-1;j++)
                area-=min(grid[j][i],grid[j+1][i])*2;
        return area;
    }
};

一开始想到的是各个方向投影，后来发现柱体内部存在空洞则不满足，但是换个角度考虑，用所有正方体的表面积去减掉叠在一块的面积即可，叠在一起的面积符合短板效应，由较小者决定，题目就简单了