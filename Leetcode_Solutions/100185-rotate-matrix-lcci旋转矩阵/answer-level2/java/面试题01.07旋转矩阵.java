### 解题思路
官方解题思路三：对于水平轴翻转而言，我们只需要枚举矩阵上半部分的元素，和下半部分的元素进行交换，即

matrix[row}][col}] 水平轴翻转matrix[n-row- 1][col]

对于主对角线翻转而言，我们只需要枚举对角线左侧的元素，和右侧的元素进行交换，即

matrix[row][col]主对角线翻转 matrix[col][row]

将它们联立即可得到：

matrix[row][col]水平轴翻转matrix[n−row−1][col]主对角线翻转matrix[col][n−row−1]
​	
 

和方法一、方法二中的关键等式：

matrix1[col][n−row−1]=matrix[row][col]

是一致的。

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for(int i=0; i<n; i++){
            //对角线为轴进行翻转
            for(int j=i; j<n; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
            //每行以中点进行翻转
            for(int j=0; j<n/2; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = tmp;
            }
        }
    }
}
```