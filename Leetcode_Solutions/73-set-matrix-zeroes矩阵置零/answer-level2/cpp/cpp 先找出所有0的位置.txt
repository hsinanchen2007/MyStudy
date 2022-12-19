### 解题思路
先找出所有0的位置
行列分别存在一个数组中
分别遍历行列数组，将改行或该列全部置零

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    
        int clomSize = matrix.size();
        int rowSize = matrix[0].size();

        vector<int> clom0;
        vector<int> row0;
        //找出所有有0的行和列
        for(int i =0;i<clomSize;i++){
            for(int j = 0;j<rowSize;j++){
                if(matrix[i][j] == 0){
                    clom0.push_back(i);
                    row0.push_back(j);
                }
            }
        }

        for(int i = 0;i<clom0.size();i++){
            for(int j = 0;j<rowSize;j++){
                matrix[clom0[i]][j] = 0;
            }
        }
        for(int i = 0;i<row0.size();i++){
            for(int j = 0;j<clomSize;j++){
                matrix[j][row0[i]] = 0;
            }
        }

}
};

```