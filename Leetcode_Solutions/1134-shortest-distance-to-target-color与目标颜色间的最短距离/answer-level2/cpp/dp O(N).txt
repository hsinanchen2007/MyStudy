### 解题思路
维护一个二维数组dis, dis[i][color-1]表示i位置，color的最小距离
通过两个for循环，
第一个从做到右，对dis[i]，更新dis[i][j]为dis[i-1][j]+1, 并设置dis[i][color-1]为0， 因为i位置颜色是color
第二个循环从右往左，更新dis[i][j]为 min(dis[i][j], dis[i+1][j]+1)

最后，对每一个query，取出dis中对应的值就ok。

### 代码

```cpp
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        int m = queries.size();
        vector<vector<int>> dis(n+2,vector<int>(3,n));
        vector<int> ans(m,-1);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0;j < 3; ++j){
                dis[i+1][j] = dis[i][j]+1;
            }
            dis[i+1][colors[i]-1] = 0;
        }

        for(int i = n;i >= 1; --i){
            for(int j = 0;j < 3; ++j){
                dis[i][j] = min(dis[i][j], dis[i+1][j]+1);
            }
        }
        for(int i = 0;i < m; ++i){
            int idx = queries[i][0]+1;
            int color = queries[i][1]-1;
            if(dis[idx][color] < n){
                ans[i] = dis[idx][color];
            }
        }
        
        return ans;
    }
};
```