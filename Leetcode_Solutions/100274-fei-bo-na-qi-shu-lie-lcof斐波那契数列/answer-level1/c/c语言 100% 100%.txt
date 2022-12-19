### 解题思路
1.解决斐波那契数列最有效率的做法：快速矩阵幂
2.快速幂解决斐波那契，简单易懂
http://zhedahht.blog.163.com/blog/static/25411174200722991933440/
3.原理举例
(F(3), F(2)) = (F(2), F(1))((1, 1), (1, 0))=(F(2)+F(1), F(2))；
(F(4), F(3)) = (F(3), F(2))((1, 1), (1, 0))=(F(2), F(1))((1, 1), (1, 0))((1, 1), (1, 0))=(F(3)+F(2), F(3))；

### 代码

```c
#define MAX_MOD 1000000007 

// 定义2×2矩阵；
typedef struct Matrix {
    // 数据成员
    unsigned long long m00;
    unsigned long long m01;
    unsigned long long m10;
    unsigned long long m11;
}Matrix2by2;

// 定义2×2矩阵的乘法运算
Matrix2by2 MatrixMultiply(const Matrix2by2* matrix1, const Matrix2by2* matrix2)
{
    Matrix2by2 matrix12 = {1, 1, 1, 0};

    matrix12.m00 = (matrix1->m00 * matrix2->m00 + matrix1->m01 * matrix2->m10) % MAX_MOD;
    matrix12.m01 = (matrix1->m00 * matrix2->m01 + matrix1->m01 * matrix2->m11) % MAX_MOD;
    matrix12.m10 = (matrix1->m10 * matrix2->m00 + matrix1->m11 * matrix2->m10) % MAX_MOD;
    matrix12.m11 = (matrix1->m10 * matrix2->m01 + matrix1->m11 * matrix2->m11) % MAX_MOD;
    return matrix12;
}


// 定义2×2矩阵的幂运算
Matrix2by2 MatrixPower(unsigned long long n)
{
    Matrix2by2 matrix = {1, 1, 1, 0};
    Matrix2by2 tempMatrix = {1, 1, 1, 0};
    // 就自己 找不到和他相乘的数
    if (n == 1) {
        matrix.m00 = 1;
        matrix.m01 = 1;
        matrix.m10 = 1;
        matrix.m11 = 0;
    } else if (n % 2 == 0) {
        // n为偶数 幂可折半 (n/2)+(n/2)
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(&matrix, &matrix);
    } else if (n % 2 == 1) {
        // n为奇数 幂可折半 ((n+1)/2)+((n+1)/2)
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(&matrix, &matrix);
        // 再+1
        matrix = MatrixMultiply(&matrix, &tempMatrix);
    }
    return matrix;
}

long fib(long long n){
    
    if (n == 0)
        return 0;
        
    if (n == 1)
        return 1;
    n--;
    Matrix2by2 fibMatrix = MatrixPower(n);
    return fibMatrix.m00;
}


```