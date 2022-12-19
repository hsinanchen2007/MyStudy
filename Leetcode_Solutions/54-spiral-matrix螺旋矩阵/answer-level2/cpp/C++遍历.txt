### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool inGrid(int i, int j, int m, int n) {
        if (i >= 0 && i < m && j >= 0 && j < n){
            return true;
        }
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        vector<vector<int> > direct{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int> > searched(matrix.size(), vector<int>(matrix[0].size(), 0));
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0, k = 0;
        for(int mn = 0; mn < (m * n); mn++){
            res.push_back(matrix[i][j]);
            searched[i][j] = 1;
            i += direct[k][0];
            j += direct[k][1];
            if(inGrid(i, j, m, n) && searched[i][j] == 0){
                continue;
            } else{
                i -= direct[k][0];
                j -= direct[k][1];
                k = (k+1)%4;
                i += direct[k][0];
                j += direct[k][1];
            }
        }
        return res;
    }
};
```