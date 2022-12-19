### 解题思路
1、归并集
2、最后遍历index计算root的个数

### 代码

```c
int findRoot(int *index, int i)
{
    while (index[i] != i) {
        i = index[i];
    }
    return i;
}

void my_union(int *index, int j, int k) 
{
    int root_j = findRoot(index, j);
    int root_k = findRoot(index, k);

    if (root_j == root_k) {
        return;
    } else if (root_j > root_k) {
        index[root_j] = root_k;
    } else {
        index[root_k]  = root_j;
    }
    return;
}

int findCircleNum(int** M, int MSize, int* MColSize)
{
    int index[MSize];
    for (int i = 0; i < MSize; i++) {
        index[i] = i;     
    }
    
    for (int j = 0; j < MSize; j++) {
        for (int k = 0; k < j; k++) {
            if (M[j][k] == 1) {
                my_union(index, j, k);
            }
        }
    }
    
    int count = 0;
    for (int m = 0; m < MSize; m++) {
        if (index[m] == m) {
            count++;
        }
    }
    return count;   
}

```