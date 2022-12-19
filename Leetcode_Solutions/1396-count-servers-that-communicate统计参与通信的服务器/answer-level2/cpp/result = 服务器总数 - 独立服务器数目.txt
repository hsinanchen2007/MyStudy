服务器总数：统计每行的总服务器数量与每列的总服务器数量，任意一个的和即为总数。
独立服务器数目：行与列的服务器数目均为1.
```
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> sum_r(grid.size(), 0);    
        vector<int> sum_c(grid[0].size(), 0);  
        for(int i = 0 ; i < grid.size(); ++i)
            for(int j = 0; j < grid[i].size(); ++j)
            {
                sum_r[i] += grid[i][j];
                sum_c[j] += grid[i][j];
            } 
        int re = accumulate(sum_r.begin(), sum_r.end(), 0); 
        for(int i = 0 ; i < sum_r.size(); ++i)
        {
            if(sum_r[i] == 1)
            {
                for(int j = 0; j < grid[i].size(); ++j)
                {
                    if(grid[i][j] == 1 && sum_c[j]==1)
                    {
                        re--;
                        break;
                    }
                }
            }
        }
        return re;
    }
};
```
