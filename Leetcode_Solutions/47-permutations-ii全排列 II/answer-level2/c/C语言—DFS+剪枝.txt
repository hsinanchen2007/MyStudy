```
#include <stdio.h>
#include "securec.h"

long int CalcFact(int val)
{
    long int rst = 1;
    int i;
    for (i = 1; i <= val; i++) {
        rst *= i;
    }
    return rst;
}

void InsertionSort(int *nums, int n)
{
    int i, j;
    if (n <= 1) {
        return;
    }
    for (i = 1; i < n; i++) {
        int value = nums[i];
        
        for (j = i - 1; j >= 0; j--) {
            if (value < nums[j]) {
                nums[j + 1] = nums[j]; // 数据移动
            } else {
                break;
            }
        }
        nums[j + 1] = value; // 插入数据
    }
}

void dfs(int *nums,int numsSize,int *mark,int *path,int index,int **result,int *reIndex)
{
    int i, j;

    for (i = 0; i < numsSize; i++) {
        if (!mark[i]) {
            /* 在Mark[i - 1]刚刚被撤销的时候剪枝，说明接下来会被选择，搜索一定会重复，故“剪枝” */
            if ((i > 0) && (nums[i] == nums[i - 1]) && (!mark[i - 1])) {
                continue;
            }

            mark[i] = 1;
            path[index] = nums[i];
            printf("get:%d \n",nums[i]);
            index = index + 1;
            
            if (index == numsSize) {
                result[*reIndex] = (int *)malloc(sizeof(int) * numsSize);
                for (j = 0; j < numsSize; j++) {
                    result[*reIndex][j] = path[j];
                    printf(" %d ",path[j]);
                }
                printf("\n");
                *reIndex = *reIndex + 1; /* 记录路径的条数 */
            }

            dfs(nums, numsSize, mark, path, index, result, reIndex); /* 对下一个节点进行相同的深度优先搜索 */
            
            mark[i] = 0; /* 恢复现场 */
            index = index - 1; /* 返回上一个节点 */
        }
    }
}

/* 给定一个没有重复数字的序列，返回其所有可能的全排列 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int *mark = (int *)malloc(sizeof(int) * numsSize);
    int *path = (int *)calloc(sizeof(int), numsSize);
    int i;
    for (i = 0; i < numsSize; i++) {
        mark[i] = 0;
    }
    int index = 0;
    int **result = (int **)malloc(sizeof(int *) * 17000);
    int reIndex = 0;
    /* 排序，方便剪枝 */
    InsertionSort(nums, numsSize);

    dfs(nums, numsSize, mark, path, index, result, &reIndex);
    *returnSize = reIndex;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 17000);
    for (i = 0; i < reIndex; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return result;
}

int main()
{
    int numsSize;
    while (scanf_s("%d", &numsSize) != EOF) {
        int maxReturnSize = CalcFact(numsSize);
        int *nums = (int *)malloc(sizeof(int) * numsSize);
        int **rstArr = (int **)malloc(sizeof(int *) * maxReturnSize * numsSize);
        int returnSize;
        int *returnColumnSizes = (int *)calloc(sizeof(int), maxReturnSize);

        for (int i = 0; i < numsSize; i++) {
            scanf("%d", nums + i);
        }

        rstArr = permute(nums, numsSize, &returnSize, &returnColumnSizes);

        for (int i = 0; i < returnSize; i++) {
            for (int j = 0; j < returnColumnSizes[i]; j++) {
                printf("%d ", rstArr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
```
