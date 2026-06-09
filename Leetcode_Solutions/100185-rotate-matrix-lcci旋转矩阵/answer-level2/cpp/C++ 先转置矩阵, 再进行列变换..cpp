```cpp
class Solution {
private:
    int n;
    
    void transpose(vector<vector<int>>& matrix) {
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
    
    void colTrans(vector<vector<int>>& matrix) {
        int leftCol = 0, rightCol = n - 1;
        while (leftCol < rightCol) {
            for (int i = 0; i < n; i++)
                swap(matrix[i][leftCol], matrix[i][rightCol]);
            leftCol++, rightCol--;
        }
    }
    
public:
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        transpose(matrix);
        colTrans(matrix);
    }
};
```