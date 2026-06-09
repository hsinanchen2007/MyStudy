/*注意：
1 // memcpy函数原地址指向的内存的长度和目的地址执向的内存的长度一样长
2   // 全局变量用的时候务必初始化，不能以为定义的地方初始化了，就不用初始化了。否则力扣上不通过
*/
#define  ROW_SIZE  1024
int g_RowIdx = 0;
//int g_cached[ROW_SIZE] = {0}; 
int *g_cached = NULL;
int g_used[ROW_SIZE] = {0}; // 代表nums的某个元素是否使用过
void step(int* nums, int numsSize, int stepdCnt, int** returnArr, int** returnColumnSizes)
{
    if (stepdCnt == numsSize) {
        returnArr[g_RowIdx] = (int *)malloc(sizeof(int) * numsSize);
        memset(returnArr[g_RowIdx], 0, sizeof(int) * numsSize);

        memcpy(returnArr[g_RowIdx], g_cached, sizeof(int) * numsSize); // letcode 要求memcpy函数原地址指向的内存的长度和目的地址执向的内存的长度一样长。这里如果g_cached的长度跟result数组一行的长度不一样，leetcode上memcpy的时候有问题
        (*returnColumnSizes)[g_RowIdx] = numsSize;
        g_RowIdx++;
        return ;
    }

    int i;
    for (i = 0; i < numsSize; i++) {
        if (g_used[i]) {
            continue;
        }

        g_used[i] = 1;

        g_cached[stepdCnt] = nums[i];  // 这里我缓存的是nums[i]，代表在广度上选一个值
        step(nums, numsSize, stepdCnt + 1, returnArr, returnColumnSizes);

        g_used[i] = 0;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (nums == NULL || returnSize == NULL || returnColumnSizes == NULL) {
        return NULL;
    }

    int **result = (int **)malloc(sizeof(int *) * ROW_SIZE);  // 假设最多输出ROW_SIZE 行
    *returnColumnSizes = (int *)malloc(sizeof(int) * ROW_SIZE);

    memset(g_used, 0, sizeof(int) * ROW_SIZE);
    g_cached = (int *)malloc(sizeof(int) * numsSize);
    memset(g_cached, 0, sizeof(int) * numsSize);
    //memset(g_cached, 0, sizeof(int) * ROW_SIZE); 
g_RowIdx = 0; // 全局变量用的时候务必初始化，不能以为定义的地方初始化了，就不用初始化了。
    step(nums, numsSize, 0, result, returnColumnSizes);

    *returnSize = g_RowIdx;
    return result;
}