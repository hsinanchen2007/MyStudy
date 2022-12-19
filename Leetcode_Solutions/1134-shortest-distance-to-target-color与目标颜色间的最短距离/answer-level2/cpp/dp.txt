1. 简单的DP即可.
2. 分别求出每个索引到其左侧和右侧指定颜色的最短距离。
3. 递推公式```dp[i][x] = min(left[i][x],right[i][x])```,其中```dp[i][x]```代表从索引i处到颜色```x```的最短距离.
```c++  []
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        int m = queries.size();
        vector<vector<int>> left(n,vector<int>(3,-1));
        vector<vector<int>> right(n,vector<int>(3,-1));
        vector<int> ans(m,n);
        
        /*intial*/
        left[0][colors[0]-1] = 0;
        for(int i = 1; i < n; ++i){
            for(int j = 0;j < 3; ++j){
                if(left[i-1][j] >= 0){
                    left[i][j] = left[i-1][j]+1;
                }
            }
            left[i][colors[i]-1] = 0;
        }
        right[n-1][colors[n-1]-1] = 0;
        for(int i = n-2;i >= 0; --i){
            for(int j = 0;j < 3; ++j){
                if(right[i+1][j] >= 0){
                    right[i][j] = right[i+1][j]+1;
                }
            }
            right[i][colors[i]-1] = 0;
        }
        
        for(int i = 0;i < m; ++i){
            int idx = queries[i][0];
            int color = queries[i][1]-1;
            if(left[idx][color] == -1 && right[idx][color] == -1){
                ans[i] = -1;
            }
            if(left[idx][color] >= 0){
                ans[i] = min(ans[i],left[idx][color]);
            }
            if(right[idx][color] >= 0){
                ans[i] = min(ans[i],right[idx][color]);
            }
        }
        
        return ans;
    }
};
```
```python []
class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        n = len(colors)
        left = [[n for _ in range(4)] for _ in range(n)]
        right = [[n for _ in range(4)] for _ in range(n)]
        ans = [n for _ in range(len(queries))]
        
        for i in range(n):
            if i > 0:
                for j in range(1,4):
                    left[i][j] = left[i-1][j] + 1
                    right[n-1-i][j] = right[n-i][j] + 1
            left[i][colors[i]] = 0
            right[n-1-i][colors[n-1-i]] = 0
        
        for i in range(len(queries)):
            ans[i] = min(ans[i],left[queries[i][0]][queries[i][1]])
            ans[i] = min(ans[i],right[queries[i][0]][queries[i][1]])
            if ans[i] >= n:
                ans[i] = -1
        
        return ans
```

