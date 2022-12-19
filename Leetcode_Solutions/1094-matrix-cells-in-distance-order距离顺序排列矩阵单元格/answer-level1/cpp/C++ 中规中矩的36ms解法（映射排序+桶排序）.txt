### 方法一 映射排序
```cpp
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans(R * C, vector<int>(3));
        int cnt = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                ans[cnt][0] = i;
                ans[cnt][1] = j;
                ans[cnt][2] = abs(R - r0) + abs(C - c0);
                ++cnt;
            }
        }
        sort(ans.begin(), ans.end(), [&](vector<int> a, vector<int> b) {return a[2] < b[2]; });
        for (int i = 0; i < cnt; i++) ans[i].pop_back();
        return ans;
    }
};
```

### 方法二 桶排序
```cpp
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans(R * C, vector<int>(2, 0));
        vector<vector<int>> m(R + C);
        for (int i = 0; i < R; ++i) 
            for (int j = 0; j < C; ++j) {
                int dis = abs(i - r0) + abs(j - c0);
                m[dis].emplace_back(i);
                m[dis].emplace_back(j);
            }
            
        int cnt = 0;
        for (int i = 0; i < R + C; ++i) {
            for (int j = 0; j < m[i].size(); j += 2)
            {
                ans[cnt][0] = m[i][j];
                ans[cnt][1] = m[i][j + 1];
                ++cnt;
            }
        }
        return ans;
    }
};
```