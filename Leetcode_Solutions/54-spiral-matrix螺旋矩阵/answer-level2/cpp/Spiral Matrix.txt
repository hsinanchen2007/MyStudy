```
class Solution {
public:
    typedef long long LL;
    typedef vector<vector<int>> IVVEC;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return{};
        LL m = matrix.size();    // 行数;
        LL n = matrix[0].size(); // 列数;
        if (m == 1) {
            return matrix[0];
        } else {
            if (n == 0) return{};
            else if (n == 1) {
                iVec.reserve(m);
                for (const auto &iv : matrix) {
                    iVec.push_back(iv[0]);
                }
                return iVec;
            } else {
                LL m1 = 0, m2 = m - 1;
                LL n1 = 0, n2 = n - 1;
                while (m1 <= m2 && n1 <= n2) {
                    dododo(m1, m2, n1, n2, matrix);
                    ++m1, --m2, ++n1, --n2;
                }
                return iVec;
            }
        }

    }

private:
    vector<int> iVec;

    void dododo(LL m1, LL m2, LL n1, LL n2, const IVVEC &mat) {
        if (m1 == m2) {
            // 只有一行;
            for (LL idx = n1; idx <= n2; ++idx) {
                iVec.push_back(mat[m1][idx]);
            }
        } else if (n1 == n2) {
            // 只有一列;
            for (LL idx = m1; idx <= m2; ++idx) {
                iVec.push_back(mat[idx][n1]);
            }
        }
        else {
            // 左 -> 右;
            for (LL idx = n1; idx <= n2; ++idx) {
                iVec.push_back(mat[m1][idx]);
            }
            // 上 -> 下;
            for (LL idx = m1+1; idx <= m2-1; ++idx) {
                iVec.push_back(mat[idx][n2]);
            }
            // 左 <-- 右;
            for (LL idx = n2; idx >= n1; --idx) {
                iVec.push_back(mat[m2][idx]);
            }
            // 上 <- 下;
            for (LL idx = m2 - 1; idx >= m1 + 1; --idx) {
                iVec.push_back(mat[idx][n1]);
            }
        }
    }
};
```
