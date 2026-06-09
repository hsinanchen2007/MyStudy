### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/5dd9e46967a5920e50b31d7f02e44270ac480cf78f7d1963e534e29ca20ac08c-image.png)

利用qsort()库函数
### 代码

```c
#define DEBUG 0

int compare(void *x, void *y){
    long ret = ((long)*((int *)x)) - ((long)*((int *)y));
    if(ret > 0)
        return 1;
    else if(ret == 0)
        return 0;
    else
        return -1;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    if(matrix == NULL || matrixSize < 1 || matrixColSize == NULL) return 0;

    int num = matrixSize * matrixColSize[0];
    int * mat = (int *)malloc(sizeof(int) * (num));
    for(int i =0; i<matrixSize; i++){
        for(int j =0; j<matrixColSize[0]; j++){
            mat[i*matrixColSize[0] + j] = matrix[i][j];
        }
    }
    
    qsort(mat,num,sizeof(int),compare);

    int ret = mat[k-1];
    free(mat);
    return ret;
}
```