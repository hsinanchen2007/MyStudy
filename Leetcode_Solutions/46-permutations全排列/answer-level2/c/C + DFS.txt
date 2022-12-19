![image.png](https://pic.leetcode-cn.com/f26a7de421bf7dc0e74311eac3596771d47d10b18f324e4e2859685052b33c3d-image.png)
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int testCnt = 0;

void DFS(int *inTmp, int **outTmp, int *visitTmp, int *returnSize, int **returnColumnSizes, int *tmpArray, int index, int n)
{
    // 终止条件:如果搜索到所有的数字，则输出排列数
    if (index == n) {
        testCnt++;
        printf("The %dth result is:\n ", testCnt);

        outTmp[*returnSize] = (int*)calloc(n, sizeof(int));
        (*returnColumnSizes)[*returnSize] = n;
        for (int i = 0; i < n; i++) {
            outTmp[*returnSize][i] = tmpArray[i];
            printf("%d ", tmpArray[i]);
        }
        printf("\n");
        (*returnSize)++;
        return;
    }

    // 遍历所有路径
    for (int i = 0; i < n; i++) {
        // 若该节点未被访问过
        if (visitTmp[i] == 0) {
            visitTmp[i] = 1; // 标记该节点已被访问
            tmpArray[index] = inTmp[i]; // 取数
            DFS(inTmp, outTmp, visitTmp, returnSize, returnColumnSizes, tmpArray, index + 1, n); // 遍历下一个节点
            visitTmp[i] = 0; // 清除标记
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if ((nums == NULL) || (numsSize == 0)) {
        return NULL;
    }

    // 求返回的最大可能组合性
    int maxSize = 1;
    for (int i = numsSize; i >= 1; i--) {
        maxSize *= i;
    }

    *returnSize = 0;
    *returnColumnSizes = (int*)calloc(maxSize, sizeof(int));

    // 定义返回数组
    int **outputArray = (int**)calloc(maxSize, sizeof(int*));
    for (int i = 0; i < maxSize; i++) {
        outputArray[i] = (int*)calloc(numsSize, sizeof(int));
    }

    // 定义标记数组
    int *visitArray = (int*)calloc(numsSize, sizeof(int));

    // 定义一维缓存数组
    int *tmpArray = (int*)calloc(numsSize, sizeof(int));

    DFS(nums, outputArray, visitArray, returnSize, returnColumnSizes, tmpArray, 0, numsSize); // 遍历下一个节点
    
    return outputArray;
}