### 解题思路
存储为0的数据的行和列，然后，将其对应的每一行和每一列都标记为0即可

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int num_m = matrix.size();
        int num_n = matrix[0].size();
        vector<int> zero_col;
        vector<int> zero_row;
        for(int i=0;i<num_m;i++){
            for(int j=0;j<num_n;j++){
                if(matrix[i][j] == 0){
                    zero_row.push_back(i);
                    zero_col.push_back(j);
                }
            }
        }
        for(int i = 0; i < zero_row.size();i++){
            for(int j=0;j<num_n;j++){
                matrix[zero_row[i]][j] = 0;
            }
        }
        for(int i = 0; i < zero_col.size(); i++){
            for(int j = 0; j < num_m; j++){
                matrix[j][zero_col[i]] = 0;
            }
        }
    }
};
```