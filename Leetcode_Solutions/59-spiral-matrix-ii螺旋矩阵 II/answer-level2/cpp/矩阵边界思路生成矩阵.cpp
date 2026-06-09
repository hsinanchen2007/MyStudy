### 解题思路

根据前一个题目，螺旋矩阵，矩阵的遍历结构不变，之前的矩阵读取变成赋值，赋值为一个从1递增的数。的确是同一个问题非常好的反向思维推演。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));

        int row = n;
        int column = n;

        int top = 0;
        int bottom = row - 1;
        int left = 0; 
        int right = column - 1;
        
        vector<int> res;
        int count = 1;
        while(left <= right && top <= bottom) {
            for(int i = left; i <= right; i++) {
                if(bottom < top) break;
                matrix[top][i] = count++;
            }
            top++;

            for(int i = top; i <= bottom; i++){
                if(right < left) break;
                matrix[i][right] = count++;
            }
            right--;

            for(int i = right; i >= left; i--) {
                if(bottom < top) break;
                matrix[bottom][i] = count++;
            }
            bottom--;

            for(int i = bottom; i >= top; i--) {
                if(right < left) break;
                matrix[i][left] = count++;
            }
            left++;
        }

        return matrix;
    }
};
```