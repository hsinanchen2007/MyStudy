### 解题思路
由于每次旋转90度，4次转动为一个周期，因此矩阵中任意一个元素都可以找到其他三个元素，将这四个元素按照位置依次交换（题目条件是按照顺时针旋转矩阵）即可得到这四个位置的新的数据值。
假设四个数据为a,b,c,d，现在要做的就是实现a=b,b=c,c=d,d=a.可以用一个临时变量tmp存储a的值，实现四个数据的交换。也可以不新建变量，通过如下方式实现四个数据的交换。
a=b-a;  //得到b,a的差
b=c-b;  //得到c,b的差
c=d-c;  //得到d,c的差
d=d-a-b-c;  //d-c得到c,再-b得到b，再-a得到a
a=a+d;
b=b+a;
c=c+b;

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){

    int n=(*matrixColSize);
    for(int i=0;i<n/2;i++){
        for(int j=i;j<(n-1-i);j++){
            matrix[i][j]=matrix[n-1-j][i]-matrix[i][j];
            matrix[n-1-j][i]=matrix[n-1-i][n-1-j]-matrix[n-1-j][i];
            matrix[n-1-i][n-1-j]= matrix[j][n-1-i]-matrix[n-1-i][n-1-j];
            matrix[j][n-1-i]=matrix[j][n-1-i]-matrix[i][j]-matrix[n-1-j][i]-matrix[n-1-i][n-1-j];
            matrix[i][j]+=matrix[j][n-1-i];
            matrix[n-1-j][i]+=matrix[i][j];
            matrix[n-1-i][n-1-j]+=matrix[n-1-j][i];
        }
    }

}
```