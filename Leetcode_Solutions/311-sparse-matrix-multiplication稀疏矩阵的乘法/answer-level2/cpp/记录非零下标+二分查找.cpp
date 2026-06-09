首先用二维数组记录A每行非零下标和B每列非零下标。
在乘的时候，可以用二分查找找出对应行和列同时非零的下标，相乘即可。
```c++
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.size() < 1 || B.size() < 1 || B[0].size() < 1) return {};
        int m = A.size();
        int n = A[0].size();
        int k = B[0].size();
        vector<vector<int>> a(m);
        vector<vector<int>> b(k);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] != 0) a[i].push_back(j);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (B[i][j] != 0) b[j].push_back(i);
            }
        }
        vector<vector<int>> res(m, vector<int>(k, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < k; ++j) {
                if (a[i].size() < 1 || b[j].size() < 1) continue;
                auto ai = a[i].begin();
                auto bi = b[j].begin();
                //int cur_max = 0;
                int sum = 0;
                while (ai != a[i].end() && bi != b[j].end()) {
                    //cur_max = max(*ai, *bi);
                    if (*ai == *bi) {
                        sum += A[i][*ai] * B[*bi][j];
                        ai++;
                        bi++;
                    }
                    else {
                        if (*ai > *bi) bi = lower_bound(bi, b[j].end(), *ai);
                        else ai = lower_bound(ai, a[i].end(), *bi);
                    }
                }
                res[i][j] = sum;
            }
        }
        return res;
    }
};
```