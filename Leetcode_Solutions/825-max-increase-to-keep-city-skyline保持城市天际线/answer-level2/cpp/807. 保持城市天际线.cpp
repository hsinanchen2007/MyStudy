### 解题思路
保证每行每列的最大值不变即可
每个值变成行列最大值中较小的一个
### 代码

```cpp
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>h(m,0),l(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                h[i]=max(h[i],grid[i][j]);
                l[j]=max(l[j],grid[i][j]);
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==h[i]||grid[i][j]==l[j]) continue;
                res+=min(h[i],l[j])-grid[i][j];
            }
        }
        return res;
    }
};
```