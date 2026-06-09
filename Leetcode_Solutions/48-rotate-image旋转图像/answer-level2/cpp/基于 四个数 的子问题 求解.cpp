### 解题思路
对于 以 四个数 为子问题“旋转”，根据规律可以直接得出四个坐标（只需知道i，j即可）
分别： 按 顺时针（n为行数==列数）
    (i,j) (j,n-i-1) (n-i-1,n-j-1) (n-j-1,i)---然后按照顺时针旋转直接操作即可
对于一个n*n二维数组：   对 i，j的界限
    i<=n/2 <==> i<n/2 + n%2;
    j < n / 2

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
       for (int i = 0; i <= n / 2 ; ++i) {
            for (int j = 0; j < n / 2 ; ++j) {
            swap(matrix[n - i - 1][n - j - 1],matrix[n - j - 1][i]);
            swap(matrix[j][n - i - 1],matrix[n - i - 1][n - j - 1]);
            swap(matrix[i][j],matrix[j][n - i - 1]);
        }
       }
    } 
};
```
对于i，j的界限问题如果有合适的解释的话，还请各位解惑