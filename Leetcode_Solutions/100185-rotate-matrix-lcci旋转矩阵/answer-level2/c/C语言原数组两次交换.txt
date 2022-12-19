```bash
示例：matrix = 
        [
            [1,2,3],
            [4,5,6],
            [7,8,9]
        ]；
```
```
先对角交换，matrix =  //2和4，3和7，6和8互换
        [
            [1,4,7],
            [2,5,8],
            [3,6,9]
        ]；
```
```
再纵向对称交换，matrix =  //1和7，2和8，3和9互换
            [
                [7,4,1],
                [8,5,2],
                [9,6,3]
            ]；
```

```c
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
  int i, j;
  for (i = 0; i < matrixSize; i++)
    for (j = 0; j < matrixColSize[i] && j < i; j++)
      swap(&matrix[i][j], &matrix[j][i]);
  for (i = 0; i < matrixSize; i++)
    for (j = 0; j < matrixColSize[i] / 2; j++)
      swap(&matrix[i][j], &matrix[i][matrixSize - j - 1]);
}
```