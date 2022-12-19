### 解题思路
此处撰写解题思路

### 代码

```cpp

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix.size();j++){
                int zz=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=zz;
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size()/2;j++){
                int zz=matrix[i][matrix.size()-1-j];
                matrix[i][matrix.size()-1-j]=matrix[i][j];
                matrix[i][j]=zz;
            }
        }
    }
};
```