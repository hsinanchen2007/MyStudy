### what?

将一个`n×n`的二维矩阵沿着顺时针方向旋转`90`度。

### how?

#### Method 1.create a new matrix

创建一个新的矩阵`newMatrix`作为`matrix`的副本，将`newMatrix`中位置为`(i,j)`处的元素复制到`matrix`中位置为`(j, (n-1-i))`处，以完成旋转。

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        //copy the value of matrix to new_matrix
        int[][] newMatrix=new int[n][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                newMatrix[i][j]=matrix[i][j];
            }
        }
        //change the value of matrix according to new_matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                matrix[j][n-1-i]=newMatrix[i][j];
            }
        }
    }
}
```

优点是代码简单，容易理解。缺点是空间复杂度 $O(n^2)$ ，显然不满足题意`in-place`。

#### Method 2.move four element once

![](https://pic.leetcode-cn.com/5bfa8299ae84839864f9626284e4e7259ab67de562573f8a43b994d41a512647.png)

红色点：表示每轮旋转需要考虑的出发点。

绿色点：表示每轮旋转设计的四个点。

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        for(int i=0; i<n/2; i++) {
            for(int j=i; j<n-1-i; j++) {
                int tmp=matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i]=tmp;
            }
        }
    }
}
```

空间复杂度为$O(1)$，满足题目要求。

#### Method 3.axisymmetric twice

矩阵发生`90`, `180`, `270`, `360`度旋转时，元素在四个位置上发生转移：
- `(i,j)`
- `(j,n-1-j)`
- `(n-1-i,n-1-j)`
- `(n-1-j,i)`

先沿着右对角线进行轴对称翻折，再沿着水平轴对称的翻折，最后达到顺时针旋转`90`度的效果。

注意对称翻转时，只需要考虑沿着轴一边的元素（即矩阵一半的元素）。

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        int tmp=-1;
        //fold along the right diagonal
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n-1-i; j++) {
                tmp=matrix[i][j];
                //swap
                matrix[i][j]=matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i]=tmp;
            }
        }
        //fold along the level
        for(int i=0; i<n/2; i++) {
            for(int j=0; j<n; j++) {
                tmp=matrix[i][j];
                //swap
                matrix[i][j]=matrix[n-1-i][j];
                matrix[n-1-i][j]=tmp;
            }
        }
    }
}
```

## complexity:

- $T:O(n^2)$　(ｎ为矩阵边长)
- $S:O(1)$
