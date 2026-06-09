# 二分
```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int y = 0, ans = 0;
        for(auto &p : grid){
            y = p.end() - upper_bound(p.begin(),p.end()-y,0, greater<int>());
            ans += y;
        }
        return ans;
    }
};
```
# 倒序
```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int y = m - 1, ans = 0;
        for(auto &p : grid){
            while(y>=0&&p[y]<0)y--;
            ans += (m-1-y);
        }
        return ans;
    }
};
```