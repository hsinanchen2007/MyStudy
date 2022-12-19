### 解题思路
穷举完第一排穷举第二排

### 代码

```java
class NumMatrix {

    int[][] data;

    public NumMatrix(int[][] matrix) {
        data = matrix;
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0, c1 = col1;
        while(row2 >= row1){
            while(col2 >= c1){
                result += data[row1][c1++];
            }
            c1 = col1;
            row1++;
        }
        return result;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
```