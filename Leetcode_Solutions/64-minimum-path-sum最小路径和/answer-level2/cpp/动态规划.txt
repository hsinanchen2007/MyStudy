**最左边和最上面两条边只能一个方向走，需要单独独立出来**
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int m=grid.size(),n=grid[0].size();
        vector<int> v(n,0);
        for(int i=0;i<m;++i)
        {
            v[0]+=grid[i][0];
            for(int j=1;j<n;++j)
            {
                if(i==0)
                {
                    v[j]=grid[i][j]+v[j-1];
                    continue;
                }
                v[j]=grid[i][j]+min(v[j],v[j-1]);
            }
        }
        return v[n-1];
    }
};
```
