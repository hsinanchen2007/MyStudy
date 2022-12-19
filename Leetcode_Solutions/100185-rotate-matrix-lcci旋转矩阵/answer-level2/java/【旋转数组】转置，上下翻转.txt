### 解题思路
这题关键在于找到规律：

> 将矩阵顺时针旋转`90°`，其实就相当于把矩阵中第 `i` 行的第 `j` 个元素即 $matrix[i][j]$，放在第 `j` 行的**倒数第 `i` 个位置**即 $matrix[j][n - 1- i]$。



**1、利用额外数组**

利用额外数组就很简单了，定义一个新的数组`newMatrix`，根据上面的规律，我们可以得到转换公式： 
$$newMatrix[j][n - 1- i] = matrix[i][j] \tag{1.1}$$

```java
class Solution {
    public void rotate(int[][] matrix) {
        if (matrix == null) {
            return;
        }

        int n = matrix.length;
        int[][] newMatrix = new int[n][n];

        // 直接用转换公式
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                newMatrix[j][n - 1 - i] =  matrix[i][j];
            }
        }

        // 更新matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] =  newMatrix[i][j];
            }
        }
    }
}

```

**2、原地旋转**

能进行原地变换操作的前提是，变换公式的等号两边不能出现一边元素被另一边覆盖的情况，显然公式$(1.1)$不满足要求。
我们再看一下上面提到的规律：
> 将矩阵顺时针旋转`90°`，其实就相当于把矩阵中第 `i` 行的第 `j` 个元素即 $matrix[i][j]$，放在第 `j` 行的**倒数第 `i` 个位置**即 $matrix[j][n - 1- i]$。

其实如果这句话中的倒数去掉的话，显然这就是**转置**，而把矩阵第 `i` 行的元素放到倒数第 `i`行，这不就是绕水平对称轴**上下翻转**嘛，所以**旋转90°**操作其实可以看成将数组做一次**上下翻转**，然后再做一次**转置**。

我们知道，**上下翻转**的变换公式：
$$matrix[i][j] = matrix[i][j] \tag{1.2}$$
以及**转置**的变换公式：
$$matrix[j][i] = matrix[i][j] \tag{1.3}$$
等号两边元素都不会出现一边被另外一边覆盖的情况。

> 注意：**上下翻转要写在转置之前**，因为如果**先转置**的话行跟列**对调**了，倒数第`i`行其实是倒数第`j`列，那应该再做**左右翻转**（$matrix[i][n - 1 - j]=matrix[i][j]$）。

总的来说，矩阵顺时针旋转90°，其实相当于下面两种**复合操作**中的一种： 

- 矩阵先**上下翻转**，然后再**转置**
- 矩阵先**转置**，然后再**左右翻转**

```java
class Solution {
    public void rotate(int[][] matrix) {
        if (matrix == null) {
            return;
        }

        int n = matrix.length;

        // 1、上下翻转：  swap(matrix[n - 1 - i][j], matrix[i][j])
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix, i, j, n - 1 - i, j);
            }
        }

        // 2、转置：  swap(matrix[i][j], matrix[j][i])
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix, i, j, j, i);
            }
        }
    }

    // 交换二维数组两个位置的值
    private void swap(int[][] matrix, int i, int j, int x, int y) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[x][y];
        matrix[x][y] = temp;
    }
}
```

