标准DFS模板，盒子放扑克，book为0表示扑克在手中，为1表示放到盒子中，index表示第几个盒子
切记==别写成=，开内存保证大小别越界，数组维数为个数的阶乘n！，参数有点多，没想好如何优化？谁给个建议
```
int Getnum(int num) {
    if (num == 0) {
        return 0;
    }
    int temp = 1;
    for (int i = 1; i <= num; i++) {
        temp = temp*i;
    }
    return temp;
}
void Dfs(int **ret, int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int index, int book[], int temp[])
{
    if (index == numsSize) {
        ret[*returnSize] = (int *)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            ret[*returnSize][i] = temp[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;        
    }
    for (int i = 0; i < numsSize; i++) {
        if (book[i] == 0) {
            temp[index] = nums[i];           
            book[i] = 1;
            Dfs(ret, nums, numsSize, returnSize, returnColumnSizes, index + 1, book, temp);
            book[i] = 0;
        }

    }
    return;
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int len = Getnum(numsSize);
    int **ret = (int **)malloc(sizeof(int *) * len);
    int *book = (int *)malloc(sizeof(int) * (numsSize));
    int *temp = (int *)malloc(sizeof(int) * (numsSize));
    memset(book, 0, sizeof(int) * (numsSize));
    memset(temp, 0, sizeof(int) * (numsSize));
    *returnColumnSizes = (int *)malloc(sizeof(int) * len);
    if (nums == NULL || numsSize == 0) {
        returnColumnSizes[0][0] = 0;
        return ret;
    }
    
    Dfs(ret, nums, numsSize, returnSize, returnColumnSizes, 0, book, temp);
    free(book);
    free(temp);
    return ret;
}
```
