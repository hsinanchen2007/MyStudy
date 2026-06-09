### 解题思路
几个步骤：
（1）对原数组排序，找一个比较快的排序算法就可以，如希尔、快速排序等；
（2）对排序后的数组找差值绝对值，并找出最小值；
（3）找出最小值的个数；并创建二维指针空间；
（4）将对应差值最小的对放入二维指针中即可。
如不想节省空间，可将（3）（4）步合并，可提升速度
执行结果：
通过
显示详情 
执行用时 :144 ms, 在所有 c 提交中击败了38.33%的用户
内存消耗 :17.5 MB, 在所有 c 提交中击败了100.00%的用户
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    int **res;
    int i;
    int j;
    int d;
    int tmp;
    int *ptmp;
    d = arrSize / 2;
    int min;
    int cnt;
    while (d > 0) {
        for (i = d; i < arrSize; i++) {
            tmp = arr[i];
            j = i - d;
            while (j >= 0 && tmp < arr[j]) {
                arr[j + d] = arr[j];
                j = j - d;
            }
            arr[j + d] = tmp; 
        }
        d = d / 2;
    }
    ptmp = (int *)malloc(sizeof(int) * (arrSize - 1));

    for (i = 0; i < arrSize - 1; i++) {
        ptmp[i] = arr[i + 1] - arr[i];
        if (i == 0) {
            min = ptmp[i];
        } else {
            if (min >= ptmp[i]) {
                min = ptmp[i];
            }
        }
    }
    cnt = 0;
    for (i = 0; i < arrSize - 1; i++) {
        if (ptmp[i] == min) {
            cnt++;
        }
    }
    *returnSize = cnt;
    *returnColumnSizes = (int *)malloc(sizeof(int)*cnt);
    res = (int **)malloc(sizeof(int *) * cnt);
    j = 0;
    for (i = 0; i < arrSize - 1; i++) {
        if (ptmp[i] == min) {
            res[j] = (int *)malloc(sizeof(int) * 2);
            res[j][0] = arr[i];
            res[j][1] = arr[i + 1];
            *(*returnColumnSizes+j) = 2;
            j++;
        }
    }
    return res;
}
```