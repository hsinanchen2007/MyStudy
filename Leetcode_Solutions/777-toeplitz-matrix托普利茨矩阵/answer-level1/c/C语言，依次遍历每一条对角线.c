# 解题思路：
依次检查每一条对角线，若不同则返回false。检查完后返回true。
比较每一条对角线，即依次遍历第一行及第一列，判断当前数延伸出去的是否相等。
对角线每一个数的坐标都是上一个数的横纵坐标加一。

执行用时：16ms，战胜81.63%
内存消耗：5.8MB
```
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
    int i, j;
    int M = matrixSize;
    int N = matrixColSize[0];
    for(i=0, j=0; j<N-1; j++){ //检索右上三角
        int temp = matrix[i][j]; //依次检索第一行的数
        int a = i+1, b = j+1;
        while(a<M && b<N){
            if(matrix[a][b] != temp)
            return false;
            a++;
            b++;
        }
    }
    for(i=1, j=0; i<M-1; i++){ //检索左下三角
        int temp = matrix[i][j]; //依次检索第一列的数
        int a = i+1, b = j+1;
        while(a<M && b<N){
            if(matrix[a][b] != temp)
            return false;
            a++;
            b++;
        }
    }
    return true;
}
```
