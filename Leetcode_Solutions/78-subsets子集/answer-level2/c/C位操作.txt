```
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){ 
    int len = (int)pow(2, numsSize); //所有排列个数为2**n，包含空集
    *returnSize = len;
    int **res = (int **)malloc(len * sizeof(int *));
    int *col = (int *)malloc(len * sizeof(int));
    memset(col, 0, len * sizeof(int));
    res[0] = NULL;
    *returnColumnSizes = col;
    for (int i = 1; i < len; i++) {
        int *tmp = (int *)malloc(numsSize * sizeof(int)); //创建临时指针用于存放每个返回的结果
        int j = 1, pos = 0; //j用于判断i中bit位为1的个数，只有为1时才从输入取值；pos用于确定在输入中的位置，每次均加1
        while (j <= i) {
            if ((j & i) == j) {
                tmp[col[i]++] = nums[pos];
            }
            pos++;
            j <<= 1;
        }
        res[i] = tmp;
    }
    return res;
}
```
