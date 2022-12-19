// 思路：N*N的矩阵，一次旋转四个边，逐渐缩小矩阵(N--)
// 具体做法：1> 令正方形的边界为(left,left)、(left,right)、(right,left)、(right,right)，其中初始值为left=0，right= matrix.size()-1;
//          2> 保证left<right,循环旋转四个边，left++，right--;
//          3> 在正方形上边中找一点(left,i),计算出其他四个点，进行旋转 

```
void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size(), left = 0, right = size - 1;	
        while (left < right){
            for (int i = left; i < right; i++){
                int tmp = matrix[left][i];
                matrix[left][i] = matrix[right+left-i][left];
                matrix[right + left - i][left] = matrix[right][right + left - i];
                matrix[right][right + left - i] = matrix[i][right];
                matrix[i][right] = tmp;
            }
            left++;
            right--;
        }
    }
```