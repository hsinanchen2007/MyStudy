### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size();
        int m = picture[0].size();
        vector<int> helper;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            int pos = 0;
            for (int j = 0; j < m; j++) {
                if (picture[i][j] == 'B') {
                    if (cnt == 0) {
                        pos = j;
                    }
                    cnt++;
                }
            }
            if (cnt == 1) {
                helper.push_back(pos);
            }
        }
        int ans = 0;
        for (auto j : helper) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += picture[i][j] == 'B' ? 1 : 0;
            }
            ans += cnt == 1 ? 1 : 0;
        }
        return ans;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```