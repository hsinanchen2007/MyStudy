### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int tmp;
        for(int i=0;i<row;++i){
            for(int j=i;j<col;++j){
                tmp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=tmp;
            }
        }
        for(int i=0;i<row;++i){
            for(int j=0;j<col/2;++j){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[i][col-1-j];
                matrix[i][col-1-j]=tmp;
            }
        }
        
    }
};
```