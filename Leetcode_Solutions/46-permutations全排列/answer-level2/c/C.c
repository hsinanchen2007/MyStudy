按照题解写个C的
```
// 阶乘函数，用于开辟空间时确定大小 
long factorial(int n) {
    if (n == 0) {
        return 1;
    } 
    return n * factorial(n-1);
}
// 交换数组中指定的两个位置
void swap(int* nums,int i,int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
// 主要实现函数，回溯算法
void fun(int* nums, int numsSize,int index, int* returnSize,int** returnColumnSizes, int **res){
    if (index == numsSize) {
        res[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        for (int j = 0; j < numsSize; j++) {
            res[*returnSize][j] = nums[j];
        }
        (*returnColumnSizes)[(*returnSize)++] = numsSize;
        return;
    }
    for (int i = index; i < numsSize; i++){
       swap(nums, index, i);
       fun(nums, numsSize, index + 1, returnSize, returnColumnSizes, res); 
       swap(nums, index, i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int**returnColumnSizes) {
    long row = factorial(numsSize);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * row);
    int** res = (int**)malloc(sizeof(int*) * row);
    fun(nums, numsSize, 0, returnSize, returnColumnSizes, res);
    return res;
}

```
