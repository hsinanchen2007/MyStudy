## 对角线法----较快
```cpp
class Solution {
public:
    //
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r0 = matrix.size(), c0 = matrix[0].size();
        if(r0==1 || c0==1) return true;
        for(int i=0; i<r0; i++){
            for(int k=1; i+k<r0 && k<c0; k++){
                if(matrix[i+k][k] != matrix[i][0]) return false;
            }
        }
        for(int j=1; j<c0; j++){
            for(int k=1; k<r0 && j+k<c0; k++){
                if(matrix[k][j+k] != matrix[0][j]) return false;
            }
        }
        return true;
    }
};
```
## 检查左上邻居----较慢
```cpp
class Solution {
public:
    
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r0 = matrix.size(), c0 = matrix[0].size();
        if(r0==1 || c0==1) return true;
        for(int i=1; i<r0; i++){
            for(int j=1; j<c0; j++){
                if(matrix[i][j]!=matrix[i-1][j-1]) return false;
            }
        }
        
        return true;
    }
};
```