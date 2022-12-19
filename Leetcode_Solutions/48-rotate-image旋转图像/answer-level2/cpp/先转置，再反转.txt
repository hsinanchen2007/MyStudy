### 解题思路
先转置，再反转

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int hight = matrix.size();
        int tmp = 0;
        for(int i =0;i<hight;i++){
            for(int j = i;j<hight;j++){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for(int i=0;i<hight;i++){
            for(int j=0;j<hight/2;j++){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[i][hight-1-j];
                matrix[i][hight-1-j] = tmp;
            }
        }
    }
};
```