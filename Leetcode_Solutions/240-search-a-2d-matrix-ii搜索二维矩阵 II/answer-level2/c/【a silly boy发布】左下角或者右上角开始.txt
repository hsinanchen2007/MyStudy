![F0A4189F-C455-4E82-BE18-A7543E5F3007.jpeg](https://pic.leetcode-cn.com/2c408cb2a8adb268faef62b5bf8fc828301c51913c2f167cc21a58eefe8f8edf-F0A4189F-C455-4E82-BE18-A7543E5F3007.jpeg)

```
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) 
{
    //左下角开始
    int i;
    int j;
    i = matrixRowSize - 1;
    j = 0;
    while ((i >= 0) && (i < matrixRowSize) && (j >= 0) && (j < matrixColSize)) {
        if (matrix[i][j] == target) {
            return true;
        }
        if (matrix[i][j] > target) {
            i--;
        } else if (matrix[i][j] < target) {
            j++;
        }
    }

    return false;
}
```
