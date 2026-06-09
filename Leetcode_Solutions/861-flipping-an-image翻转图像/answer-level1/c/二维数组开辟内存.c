### 解题思路
A是二维数组指针，用A[i][j]取值，ASize是行数，* AColSize是列数，* returnSize是返回的行数，** returnColumnSizes是返回的列数。
在main函数中如何给A赋值？
![image.png](https://pic.leetcode-cn.com/1fdd98e31ddf662e46fcc6559fc26b754a3702408cbd18839b421553634baf86-image.png)

int arr[3][4] = {{1,0,1},{1,0,1},{1,0,1}};
int *returnColumnSizes;
int **A = (int **)malloc(sizeof(int *) * ASize); // 因为存放的是指针，所以是int *
for (int i = 0; i < ASize; i++) {
    A[i] = (int *)malloc(sizeof(int) * AColSize); // 存放的是int数据
}
for (int i = 0; i < ASize; i++) {
    for (int j = 0; j < AColSize; j++) {
        A[i][j] = arr[i][j];
}
}
flipAndInvertImage(A, ASize, &AColSize, &returnSize, &returnColumnSizes);
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX 21
//#define ABS(n) (n) < 0 ? (-(n)) : (n)
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    int array = 0;
    int i, j;
    int sum = *AColSize - 1;
    for (i = 0; i < ASize; i++) {
        for (j = 0; j < (*AColSize + 1)/2; j++) {
            array = A[i][j];
            A[i][j] = A[i][sum - j];
            A[i][sum - j] = array;
        }
    }
    for (i = 0; i < ASize; i++) {
        for (j = 0; j < *AColSize; j++) {
            A[i][j] = abs(A[i][j] - 1);
        }
    }
    * returnSize = ASize;
    * returnColumnSizes = AColSize;

    return A;

}
```