```
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);//returnColumnSizes储存杨辉三角每一行元素的个数
    int **nums;
    nums = (int**)malloc(sizeof(int*) * (*returnSize));
    for (int i = 0; i < numRows; i++){
        (*returnColumnSizes)[i] = i + 1;
        nums[i] = (int*)malloc(sizeof(int) * (*returnColumnSizes)[i]);
        for (int j = 0; j <= i; j++){
            if (j == 0 || j == i)
                nums[i][j] = 1;
            else
                nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
        }
    }
    return nums;
}
```
