class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> tmp(n, vector<int>(n));

        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                tmp[i][j] = matrix[n-j-1][i];
            }
        }

        matrix = tmp;
    }
};