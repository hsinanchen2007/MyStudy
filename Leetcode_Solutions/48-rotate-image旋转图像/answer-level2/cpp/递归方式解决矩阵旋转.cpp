### 解题思路
1、找出矩阵旋转的规律，找出变化的坐标(注意重复)
2、递归替换数据4次，交换数据，不用多开辟空间
### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i , j; 
        for (i = 0 ; i < (matrix.size()+1) / 2; i++) {
            for (j = i; j < matrix.size() - 1 - i; j++ ) {
                int count = 4;
                exchange(matrix, j , i, matrix[j][i] , count);
            }
        }

    }

    void exchange(vector<vector<int>>& matrix, int x, int y , int currentTmp, int &count) {
        if (count == 0){return;}
        count--;
        int destinationX = y;
        int destinationY = matrix.size() - 1 - x;
        int tmp = matrix[destinationX][destinationY];
        matrix[destinationX][destinationY] = currentTmp;
        exchange(matrix, destinationX, destinationY , tmp , count);
    }
};
```