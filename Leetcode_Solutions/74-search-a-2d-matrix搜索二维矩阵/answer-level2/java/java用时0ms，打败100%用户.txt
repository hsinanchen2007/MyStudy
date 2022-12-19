先获取在哪一行，如果每一行都没有，返回false
```
int containRow = -1;
for (int i = 0; i < rows; i++) {
    if (matrix[i][0] <= target && matrix[i][cols-1] >= target) {
        containRow = i;
    }
}
```
在上面获取的行里面在查找具体的列位置，如果找到返回true
```
if (containRow == -1) {
    return res;
}
for (int i = 0; i < cols; i++) {
    if (matrix[containRow][i] == target) {
        return true;
    }
}
```
完整代码：
```
public static boolean searchMatrix(int[][] matrix, int target) {
    boolean res = false;
    int rows = matrix.length;
    if (rows == 0) {
        return res;
    }
    int cols = matrix[0].length;
    if (cols == 0) {
        return res;
    }
    int containRow = -1;
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] <= target && matrix[i][cols-1] >= target) {
            containRow = i;
        }
    }
    if (containRow == -1) {
        return res;
    }
    for (int i = 0; i < cols; i++) {
        if (matrix[containRow][i] == target) {
            return true;
        }
    }
    return res;
}
```
时间复杂度O(m+n)


