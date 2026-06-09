### 解题思路
观察旋转矩阵和原矩阵的对应关系，可将图像旋转 90 度可转换成两次翻转操作：
1. 先沿着主对角线翻转（转置），即 $matrix[i][j] = matrix[j][i]$
2. 再沿中线左右翻转，即 $matrix[i][j] = matrix[i][n-j-1]$
比如：
$$
matrix=\left[
	\begin{matrix}
		1 & 2 & 3\\
		4 & 5 & 6 \\
		7 & 8 & 9 \\
	\end{matrix}
\right]
$$

沿着主对角线翻转（转置）后，
$$
matrix=\left[
	\begin{matrix}
		1 & 4 & 7\\
		2 & 5 & 8 \\
		3 & 6 & 9 \\
	\end{matrix}
\right]
$$
再沿中线左右翻转后，
$$
matrix=\left[
	\begin{matrix}
		7 & 4 & 1\\
		8 & 5 & 2 \\
		9 & 6 & 3 \\
	\end{matrix}
\right]
$$
最后得到的就是旋转90度后的矩阵，其中每转置一行就可以翻转一行。
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {

        int n = matrix.length;
        for(int i=0;i<n;i++){
            //沿对角线翻转（转置）
             for(int j=i;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
            //沿中线左右翻转
           for(int j=0;j<n/2;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = temp;
            }
        }
    }
}
```
![image.png](https://pic.leetcode-cn.com/51c84f4f0e71208e22fcf694cf5be1af0a14d57fbdd7c98c54ae5416e437e6e8-image.png)
