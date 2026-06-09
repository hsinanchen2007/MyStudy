### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0){
            return ;
        }
        int r = n / 2 - 1;
        int c = (n - 1) / 2;
        for(int i = r; i >= 0; i--){
            for(int j = c; j >= 0; j--){
                swap(matrix[i][j],matrix[j][n - i - 1]);
                swap(matrix[i][j],matrix[n - i - 1][n - j - 1]);
                swap(matrix[i][j],matrix[n - j - 1][i]);
            }
        }
    }
};

```