### 解题思路
一个位置的数字在旋转过程中对应着四个数字的位置，也就是说，四个位置上的数字可以构成一个“旋转圈”，每个矩阵都有若干个这样的旋转圈，每次旋转一个圈即可，当然因为在遍历数组的过程中存在重复遍历已旋转元素的情况，因此设一个visited数组标记情况，一个旋转圈对应四次操作，用for循环控制，每次保存当前位置的数，确定下一个位置的坐标（可以根据矩阵性质算出来），再将当前位置的数放置到旋转后位置，并将旋转后位置上原来的数保存起来，再找这个数的下个位置，以此类推即可。
### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int pre,temprow,tempcol;
    int visited[matrixSize][matrixSize];
    for(int i=0;i<matrixSize;i++)
        for(int j=0;j<matrixSize;j++)
            visited[i][j]=0;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=0;j<matrixSize;j++)
        {
            if(visited[i][j]==0)
            {
                
            pre=matrix[i][j];
            for(int k=0;k<4;k++)
            {
                visited[i][j]=1;
                temprow=j;
                tempcol=matrixSize-1-i;
                i=temprow;
                j=tempcol;
                int temp=pre;
                pre=matrix[i][j];
                matrix[i][j]=temp;
            }
            }
        }
    }
}

```