思路如标题。
![image.png](https://pic.leetcode-cn.com/9dab698a5981ede5fc8ff4792565a262898d4a9e8f040d38ba65d0311b59f330-image.png)

```
void DepthSearch(int **M, int row, int col, int *flag, int Size)
{
    if (M[row][col] == 1 && flag[col] == 0) {
        flag[col] = 1;
        for (int i = 0; i < Size; i++) {
            DepthSearch(M, col,i, flag, Size);
        }
    }
}

int findCircleNum(int** M, int MSize, int* MColSize){
    if (M == NULL || MSize == 0 || MColSize == NULL || *MColSize == 0) {
        return 0;
    }
    
    int *flag = (int *)malloc(MSize * sizeof(int));
    if (flag == NULL) {
        return 0;
    }
    memset(flag, 0, MSize * sizeof(int));
    int ret = 0;
    for (int i = 0; i < MSize; i++) {
        if (flag[i] == 1) {
            continue;
        }
        flag[i] = 1;
        for (int j = 0; j < MSize; j++) {
            DepthSearch(M, i, j, flag, MSize);
        }
        ret++;
    }
    free(flag);
 return ret;
}
```
