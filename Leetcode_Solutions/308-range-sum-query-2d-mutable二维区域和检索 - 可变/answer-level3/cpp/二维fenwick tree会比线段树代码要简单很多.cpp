```cpp

class NumMatrix {
private:
    vector<vector<int>> clone;
    vector<vector<int>> tree;

    int lowbit(int x) {
        return x & (-x);
    }

    int getSum(int row, int col) {
        int ans = 0;
        for (int i = row; i > 0; i -= lowbit(i))
            for (int j = col; j > 0; j -= lowbit(j))
                ans += tree[i][j];
        return ans;
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int n = matrix.size(), m = matrix[0].size();
        clone.assign(n, vector<int> (m));
        tree.assign(n + 1, vector<int> (m + 1));
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                update(i, j, matrix[i][j]);
    }
    
    void update(int row, int col, int val) {
        int delta = val - clone[row][col];
        clone[row][col] = val;
        for (int i = row + 1; i < tree.size(); i += lowbit(i))
            for (int j = col + 1; j < tree[0].size(); j += lowbit(j))
                tree[i][j] += delta;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2 + 1, col2 + 1) - getSum(row1, col2 + 1) - getSum(row2 + 1, col1) + getSum(row1, col1); 
    
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */


```