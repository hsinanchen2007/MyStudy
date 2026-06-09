### 解题思路
![0775d84f7b8f4dca82b3e16494c40da79d3c421f4d7fd6394420fba4c79d218b-image.png](https://pic.leetcode-cn.com/acad78c6ae544f845d692b874dc1ef34bf6bbf13b2ba888a493ebc94dacdd123-0775d84f7b8f4dca82b3e16494c40da79d3c421f4d7fd6394420fba4c79d218b-image.png)


### 代码

```c
//升序排序后的第k个元素
int comp(int *a, int *b){
    return *a - *b;
}
int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int idx = 0;
    int *nums = (int *)malloc(matrixSize * *matrixColSize * sizeof(int));
    for(int i = 0; i < matrixSize; i++){
        for (int j = 0; j < *matrixColSize; j++){
            nums[idx] = matrix[i][j];
            idx++;
           
        }
    }
    qsort(nums, idx, sizeof(int), comp);
    return nums[k-1];
}
```