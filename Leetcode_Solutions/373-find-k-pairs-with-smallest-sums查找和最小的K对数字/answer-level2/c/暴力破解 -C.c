### 解题思路
1.列出所有素组组合
2.对二维数组的和大小升序排序。
3.输出数组
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int comp (const void *a, const void *b)
{
    int *ap = *(int **)a;
    int *bp = *(int **)b;
    if ((ap[0] + ap[1]) == (bp[0] + bp[1])) {
        return ap[0] - bp[0];
    }
    return (ap[0] + ap[1]) - (bp[0] + bp[1]);
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
    int **returnnum;
    int row = 2;
    int i, j;
    int *q;
    int l, m;
    int length;
    int temp1, temp2;

    if (0 == nums1Size || 0 == nums2Size) {
        *returnSize = 0;
        q = (int *) malloc(sizeof(int));
        q[0] = 0;
        *returnColumnSizes = q;
        return NULL;
    }
    length = nums1Size * nums2Size;
    q = (int *) malloc(sizeof(int) * k);
    returnnum = (int **)malloc(sizeof(int *) * length);
    for (i = 0; i < length; i++) {
        returnnum[i] = (int *)malloc(sizeof(int) * row);
    }
    l = 0;
    //列出所有素组组合
    for (i = 0; i < nums1Size; i++) {
        for (j = 0; j < nums2Size; j++) {
            returnnum[l][0] = nums1[i];
            returnnum[l][1] = nums2[j];
            l++;
        }
    }

    //对二维数组的和大小升序排序。
    qsort(returnnum, length, sizeof(int) * 2, comp);
#if 0
    int minIndex;
    for (i = 0; i < length - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < length; j++) {
            if ((returnnum[j][0] + returnnum[j][1]) < (returnnum[minIndex][0] + returnnum[minIndex][1])) {     // 寻找最小的数
                minIndex = j;                 // 将最小数的索引保存
            }
        }
        temp1 = returnnum[i][0];
        temp2 = returnnum[i][1];
        returnnum[i][0] = returnnum[minIndex][0];
        returnnum[i][1] = returnnum[minIndex][1];
        returnnum[minIndex][0] = temp1;
        returnnum[minIndex][1] = temp2;
        if (i >= k) {//已经找出前k个小的数组，达到目标，退出。
            break;
        }
    }
#endif
    if (k < length) {
        * returnSize = k;
    } else {
        *returnSize = length;
    }
    for (i = 0; i < k; i++) {
        q[i] = row;
    }
    *returnColumnSizes = q;

    return returnnum;
}
```