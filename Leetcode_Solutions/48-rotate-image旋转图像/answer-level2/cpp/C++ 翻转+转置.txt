```c++
class Solution {
public:
    // https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
    void rotate(vector<vector<int>>& matrix) {
        // upside down
        reverse(matrix.begin(), matrix.end());
        // transpose
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
```