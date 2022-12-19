最后答案由四个矩阵容斥得到。
```
#define lowbit(x) ((x) & (-x))
class NumMatrix {
public:
    int n, m;
    vector<vector<int>> M;
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>> &matrix) : matrix(matrix) {
        n = matrix.size();
        if (n) m = matrix[0].size();
        else m = 0;
        M = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                modify(i + 1, j + 1, matrix[i][j]);
            }
        }
    }
    void modify(int i, int j, int delta) {
        for (int x = i; x <= n; x += lowbit(x)) {
            for (int y = j; y <= m; y += lowbit(y)) {
                M[x][y] += delta;
            }
        }
    }
    int getsum(int i, int j) {
        int ret = 0;
        for (int x = i; x; x -= lowbit(x)) {
            for (int y = j; y; y -= lowbit(y)) {
                ret += M[x][y];
            }
        }
        return ret;
    }
    void update(int x, int y, int v) {
        int delta = v - matrix[x][y];
        matrix[x][y] = v;
        modify(x + 1, y + 1, delta);
    }
    int sumRegion(int x1, int y1, int x2, int y2) {
        return getsum(x2 + 1, y2 + 1) - getsum(x1, y2 + 1) - getsum(x2 + 1, y1) + getsum(x1, y1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
```
