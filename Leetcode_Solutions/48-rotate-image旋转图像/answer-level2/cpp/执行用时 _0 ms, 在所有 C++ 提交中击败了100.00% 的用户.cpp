### 解题思路
数学规律，一圈一圈的旋转。在一圈中旋转每组对应的四个位置的值

### 代码

```cpp
class Solution {
public:
    执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    内存消耗 :6.7 MB, 在所有 C++ 提交中击败了100.00%的用户
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n<=1) return;
        int temp;
        for(int i = 0; i<n/2;++i){//圈数
            for(int j = i;j<n-1-i;++j){//一圈中需要旋转的组数，
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};
```