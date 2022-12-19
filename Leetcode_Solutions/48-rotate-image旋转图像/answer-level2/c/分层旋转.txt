### 解题思路
此处撰写解题思路

### 代码

```c
//tR tC 代表左上角的元素， dR dC 代表右下角的元素
void rotate_edge(int **matrix, int tR, int tC, int dR, int dC)
{
    int times = dC - tC;
    int tmp;
    for (int i = 0; i < times; i++) {
        tmp = matrix[tR][tC + i];
        matrix[tR][tC + i] = matrix[dR - i][tC];
        matrix[dR - i][tC] = matrix[dR][dC - i];
        matrix[dR][dC - i] = matrix[tR + i][dC];
        matrix[tR + i][dC] = tmp;
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
   int tR = 0;
   int tC = 0;
   int dR = matrixSize - 1;
   int dC = matrixColSize[0] - 1;
   while (tR < dR) {
       rotate_edge(matrix, tR++, tC++, dR--, dC--);
   }
}
```