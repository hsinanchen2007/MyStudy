### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> B;
        int row=A.size(),column=A[0].size();
        B.resize(row);
        for(int i=0;i<row;++i){
            B[i].resize(column);
            for(int j=0;j<column;++j){
                if(A[i][j]==0) B[i][column-1-j]=1;
                if(A[i][j]==1) B[i][column-1-j]=0;
            }
        }
        return B;
    }
};
```