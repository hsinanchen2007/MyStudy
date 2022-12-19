### 解题思路
状态表示f[i][j]:选第i个房子时刷j号颜色的最小代价。

状态转移:f[i][j] = min(f[i - 1][k])(k != j) + costs[i][j];
这是比较好想的，然而这种状态转移时间复杂度太高，每个j都要遍历f[i - 1][k](k从 0 到 n - 1 且 k 不等于j)
那么复杂度就是O(nmm)

可以从上一轮的最小值入手考虑，其实f[i][j = 0 ~ n] 中的大部分都可以由 min(f[i - 1][k]) + costs[i][j] 转移过来，除了上一轮最小值下标和这轮的j相同时就需要找次小值。

因此只要将每一轮的最小值、最小值的下标和次小值存下来即可。

### 代码

```cpp
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int m = costs.size();
        if(m == 0) return 0;
        int n = costs[0].size();
        vector<vector<int> > f(m, vector<int> (n));
        int index1, index2;
        int min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f;
        for(int i = 0; i < n; i++)
        {
            f[0][i] = costs[0][i];
            if(f[0][i] <= min1)
            {
                index2 = index1;
                min2 = min1;
                index1 = i;
                min1 = f[0][i];
            }
            else if(f[0][i] < min2)
            {
                index2 = i;
                min2 = f[0][i];
            }
        }

        for(int i = 1; i < m; i++)
        {
            int index11, index22;
            int min11 = 0x3f3f3f3f, min22 = 0x3f3f3f3f;
            for(int j = 0; j < n; j++)
            {
                if(j == index1)
                {
                    f[i][j] = min2 + costs[i][j];
                }
                else f[i][j] = min1 + costs[i][j];
                
                if(f[i][j] <= min11)
                {
                    index22 = index11;
                    min22 = min11;
                    index11 = j;
                    min11 = f[i][j];
                }
                else if(f[i][j] < min22){
                    index22 = j;
                    min22 = f[i][j];
                }
            }
            min1 = min11;index1 = index11;min2 = min22;index2 = index22;
        
        }
        return min1;
    }
};
```