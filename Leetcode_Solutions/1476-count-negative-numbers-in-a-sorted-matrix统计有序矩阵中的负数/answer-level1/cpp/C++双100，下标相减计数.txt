### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int ans = 0;
        for(vector<int> row : grid)
        {
            for(int i = 0; i < row.size(); ++i)
            {
                if(row[i] < 0)
                {
                    ans += row.size() - i;
                    break;
                }
            }
        }
        return ans;
        
    }
};
```