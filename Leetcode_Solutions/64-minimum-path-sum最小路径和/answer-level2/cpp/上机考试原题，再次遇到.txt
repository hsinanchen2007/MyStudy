```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m_size=grid.size();
        int n_size=grid[0].size();
        //cout<<m_size<<" "<<n_size<<endl;
        for(int i(n_size-2);i>=0;i--)
        {
            //cout<<"hit goodtrap"<<endl;
            grid[m_size-1][i]+=grid[m_size-1][i+1];
        }
        for(int j(m_size-2);j>=0;j--)
        {
            //cout<<"hit goodtrap"<<endl;
            grid[j][n_size-1]+=grid[j+1][n_size-1];
        }
        for(int j=n_size-2;j>=0;j--)
        {
            for(int i=m_size-2;i>=0;i--)
            {
                grid[i][j]+=grid[i+1][j]>grid[i][j+1]?grid[i][j+1]:grid[i+1][j];
            }
        }
        return grid[0][0];
    }
};
```
重新写了一次