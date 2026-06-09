```
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty()) return 0;
        int R = picture.size();
        int C = picture[0].size();
        vector<int> rows(R, 0);
        vector<int> cols(C, 0);
        vector<vector<int> > cols_black_rows(C);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    ++cols[j];
                    cols_black_rows[j].push_back(i);
                }
            }
        }
        vector<int> valid_rows;
        vector<int> valid_cols;
        for (int i = 0; i < R; ++i) {
            if (rows[i] == N) valid_rows.push_back(i);
        }
        for (int i = 0; i < C; ++i) {
            if (cols[i] == N) valid_cols.push_back(i);
        }
        int res = 0;
        for (auto i : valid_rows) {
            for (auto j : valid_cols) {
                bool match = true;
                for (auto k : cols_black_rows[j]) {
                    if (picture[i] != picture[k]) {
                        match = false;
                        break;
                    }
                }
                if (match) ++res;
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/0b3ea73d6c9bb08bbc23b0b2759f3a2d2212eb9e798a2767dd19b095cac32d10-image.png)
