### 解题思路
N*N的矩阵，每个元素都有对应的位置，将一个大矩阵看成几层，最外面一个口字型第一层，接着里面，再里面，针对N的奇偶性有些许的不同，但是结果都一样，每一层要进行N-1轮位置交换，示意图如下
![1586257481(1).png](https://pic.leetcode-cn.com/6f3ef24dab84841f43b65afc4cbaa0434b9ed7cfc396b11a1ca4a331bb4b18bd-1586257481\(1\).png)






### 代码

```c
//思路：先选中一个元素，计算出它旋转后应该属于的位置
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize<=1) return;
    int mid=matrixSize/2-1;
    for(int m=0;m<=mid;++m)
        for(int n=m;n<matrixSize-1-m;++n)
        {
            int temp=matrix[m][n];
            matrix[m][n]=matrix[matrixSize-1-n][m];//左上角
            matrix[matrixSize-1-n][m]=matrix[matrixSize-1-m][matrixSize-1-n];//左下
            matrix[matrixSize-1-m][matrixSize-1-n]=matrix[n][matrixSize-1-m];
            matrix[n][matrixSize-1-m]=temp;//右上角
        }
}
```