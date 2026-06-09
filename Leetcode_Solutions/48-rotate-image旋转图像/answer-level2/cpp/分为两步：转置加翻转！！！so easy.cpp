### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void matrixTransposition(vector<vector<int>>& matrix,int n){  
        int i,j;
        int temp;
        for(i=0;i<n;++i){
            for(j=i+1;j<n;++j){
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
    }
    void matrixSymmetry(vector<vector<int>>& matrix,int n){
        int i,j;
        int temp;
        for(i=0;i<n;++i){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        matrixTransposition(matrix,n);
        matrixSymmetry(matrix,n);
    }
};
```