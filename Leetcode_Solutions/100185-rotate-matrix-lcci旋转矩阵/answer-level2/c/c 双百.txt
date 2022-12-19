### 解题思路
首先对每一行，以中点为中心进行反转
之后将矩阵按照对角线转置
好像因为是N*N
所以c语言给的`int* matrixColSize`并没有什么用
### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int len=matrixSize;
    for(int i=0;i<len;i++)//首先对每一行，以中点为中心进行反转
    {
        for(int j=0;j<len/2;j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][len-1-j];
            matrix[i][len-1-j] = temp;
        }
    }
     for(int i=0;i<len;i++)//之后将矩阵按照对角线转置
     {
        for(int j=0;j<len-1-i;j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[len-1-j][len-1-i];
            matrix[len-1-j][len-1-i] = temp;
        }
    }
}
```