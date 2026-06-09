// 我就是闲得*疼哈哈用矩阵乘法写斐波那契😂

// 斐波那契f(n)可以通过矩阵乘法来计算，如下：
// $$
// \left[
//  \begin{matrix}
//    f(n) \\
//    f(n-1)
//   \end{matrix}
//   \right] = \left[
//  \begin{matrix}
//    1 & 1\\
//    1 & 0
//   \end{matrix}
//   \right] \left[
//  \begin{matrix}
//    f(n-1) \\
//    f(n-2)
//   \end{matrix}
//    \right] = \left[
//  \begin{matrix}
//    1 & 1\\
//    1 & 0
//   \end{matrix}
//   \right]^{n-1} \left[
//  \begin{matrix}
//    f(1) \\
//    f(0)
//   \end{matrix}
//    \right] 
// $$
// 即计算：
// $$
// \left[
//  \begin{matrix}
//    1 & 1\\
//    1 & 0
//   \end{matrix}
//   \right]^{n-1} \left[
//  \begin{matrix}
//    1\\
//    0
//   \end{matrix}
//    \right] 
// $$

// 如上累乘是O(N)的，可以通过递归或者位运算来优化成O(logN)，即快速幂，下边儿给出了递归和位运算俩方法。

// ``` Java
class Solution {
    public int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        int[][] m = new int[][] {{1, 1}, {1, 0}};
        int[][] originM = new int[][] {{1}, {0}}; 
        int[][] res = matrixMul(matrixPow(m, n - 1), originM); 
        return res[0][0];
    }

    int[][] matrixMul(int[][] a, int[][] b) {
        int row = a.length;
        int col = b[0].length;
        int[][] res = new int[row][col];
        
        for (int i = 0; i < row; i++) {
            for (int k = 0; k < b.length; k++) {
                for (int j = 0; j < col; j++) {  // 矩阵乘法时注意按行读矩阵b可以利用cpu缓存来加速哈
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }

    // 递归实现logN快速幂
    int[][] matrixPow (int[][] m, int n) {
        if (n == 1) {
            return m;
        }
        int[][] res = matrixPow(m, n / 2);
        return (n & 1) == 0? matrixMul(res, res): matrixMul(matrixMul(res, res), m);
    }

    // 位运算实现logN快速幂
    int[][] matrixPow (int[][] m, int n) {
        int[][] res = new int[][] {{1, 0}, {0, 1}};
        while (n > 0) {
            // 比如13的2进制是1101，即2^3 + 2^2 + 2^0, 即x^13 = x^(2^3 + 2^2 + 2^0) = x^8*x^4*x
            if ((n & 1) == 1) {
                res = matrixMul(res, m);
            }
            n >>= 1;
            m = matrixMul(m, m);
        }
        return res;
    }

    
}

// ```
