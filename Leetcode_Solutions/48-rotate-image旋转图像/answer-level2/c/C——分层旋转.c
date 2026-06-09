# 一层一层的旋转
写了两三个小时，发现不是程序太难了，是我的脑子转不过来。
## 说一下思路：
### 声明一个一维数组a
### 先i=0（最外层）
都是顺时针地旋转
a（正着排序）= 上边的行（从右往左）
上边的行（从右往左）= 左边的列（从上往下）
左边的列（从上往下）= 下边的行（从左往右）
下边的行（从左往右）= 右边的列（从下往上）
右边的列（从下往上）= a（正着排序）
### 再添加最外层对i的循环
i从0到matrixSize/2（如果是奇数最中间的不动）
## C代码
```
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int a[matrixSize];
    int i = 0;
    for(i=0; i<matrixSize/2; i++){//第i层
        for(int k=0; k<matrixSize-2*i; k++){
            a[k] = matrix[i][matrixSize-k-1-i];//a=上边列
        }
        for(int k=0; k<matrixSize-2*i; k++){
            matrix[i][matrixSize-k-1-i] = matrix[i+k][i];//上边列=左
        }
        for(int k=0; k<matrixSize-2*i; k++){
            matrix[i+k][i] = matrix[matrixSize-1-i][k+i];//左边列=下
        }
        for(int k=0; k<matrixSize-2*i; k++){
            matrix[matrixSize-1-i][k+i] = matrix[matrixSize-1-k-i][matrixSize-1-i];//下边列=右
        }
        for(int k=0; k<matrixSize-2*i; k++){
            matrix[matrixSize-1-k-i][matrixSize-1-i] = a[k];//右边列=a
        }
    }
}
```
