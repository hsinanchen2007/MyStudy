### 解题思路
将矩阵拆分成四个部分，左上角，右上角，左下角和右下角，只需要按逆时针的方式进行交换，交换三次就可实现顺时针旋转90度

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /**
         *将矩阵拆分成四个部分，左上角，右上角，左下角和右下角，只需要按逆时针的方式进行交换，交换三次就可实现顺时针旋转90度
         **/
        int n = matrix.size();
        for(int i = 0; i < n/2; i++) {         //行的取值范围是0~n/2
            for(int j = 0; j < (n+1)/2; j++) { //列的取值范围因为要考虑到当矩阵是单数的时候，所以是 0~(n+1)/2  这两个范围是每一部分的矩阵行列大小
                std::swap(matrix[i][j],matrix[n-j-1][i]);                   //交换左上角和左下角
                std::swap(matrix[n-j-1][i],matrix[n-i-1][n-j-1]);           //交换左下角和右下角
                std::swap(matrix[n-i-1][n-j-1],matrix[n-(n-j-1)-1][n-i-1]); //最后交换右下角和右上角
            }
        }
    }
};
```