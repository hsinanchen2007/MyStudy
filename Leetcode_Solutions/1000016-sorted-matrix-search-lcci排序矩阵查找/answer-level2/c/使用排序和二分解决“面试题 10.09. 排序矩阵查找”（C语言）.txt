### 解题思路
典型的分组有序类问题。

通常的解法式按照有序性，逐行处理；但这里给出另一种解法。

1.首先将所有数据进行排序；

2.对所有数据进行二分查找。

计算复杂度为o(n)+o(nlog(n))+o(log(n)) = o(nlog(n))

本方法优点在于思路简洁清晰，对于分组有序类型中的其他问题更为明显。

![image.png](https://pic.leetcode-cn.com/6d8198d6ae0fe0b8dd2180a387b9cc231e58cde27a7bbeb8e6ea9fc9f3707ba8-image.png)


### 代码

```c
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

//【算法思路】qsort+二分。
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(matrixSize == 0 || matrixColSize[0] == 0) {
        return false;
    }

    int row = matrixSize;
    int col = matrixColSize[0];

    int *info = (int *)calloc(row * col, sizeof(int));
    int isize = 0;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            info[isize++] = matrix[i][j];
        }
    }
    
    qsort(info, isize, sizeof(int), compare);

    int ll = 0, rr = isize - 1;

    while (ll < rr) {
        int mid = (ll + rr) / 2;
        if(target < info[mid]) {
            rr = mid;
        } else {
            ll = mid + 1;
        }
    }

    return info[ll] == target || (ll > 0 && info[ll - 1] == target);
}
```