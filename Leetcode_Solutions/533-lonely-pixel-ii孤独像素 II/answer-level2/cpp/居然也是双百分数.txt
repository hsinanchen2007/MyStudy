
```cpp
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int n = picture.size();
        int m = picture[0].size();
        map<vector<char>, int> zipped;
        for (int i = 0; i < n; i++) {
            zipped[picture[i]]++;
        }
        int ans = 0;
        for (auto& e : zipped) {
            if (e.second != N) {
                continue;
            }
            int cnt = 0;
            vector<int> pos;
            for (int j = 0; j < m; j++) {
                if (e.first[j] == 'B') {
                    pos.push_back(j);
                    cnt++;
                }
            }
            if (cnt != N) {
                continue;
            }
            for (auto j : pos) {
                int lcnt = 0;
                for (int i = 0; i < n; i++) {
                    if (picture[i][j] == 'B') {
                        lcnt++;
                    }
                }
                ans += (lcnt == N) ? N : 0;
            }
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