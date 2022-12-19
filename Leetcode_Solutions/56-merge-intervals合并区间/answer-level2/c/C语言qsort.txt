### 解题思路
1, 对子数组的首元素进行排序，然后通过比较尾元素大小填入新数组即可。
2，C语言qsort函数还是很强大的，通过编写cmp函数，基本可以满足对各种数据类型的排序。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX(a,b) ((a>b) ? a : b)

int cmp(const void *a,const void *b){
    int *ap = *(int **)a;       
    int *bp = *(int **)b;

    if(ap[0] < bp[0])
        return -1;
    
    if(ap[0] > bp[0])
        return 1;
    
    return ap[1] - bp[1];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int** ans;
    ans = (int **)malloc(sizeof(int *) * intervalsSize);
    int i, j = -1;

    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    for(i=0; i<intervalsSize; i++){
        if(i==0){
            j++;
            ans[j] = (int *)malloc(sizeof(int) * 2);
            ans[j][0] = intervals[i][0];
            ans[j][1] = intervals[i][1];
        }else{
            if(ans[j][1] >= intervals[i][1])
                continue;
            
            if(ans[j][1] >= intervals[i][0])
                ans[j][1] = MAX(ans[j][1], intervals[i][1]);
            else{
                j++;
                ans[j] = (int *)malloc(sizeof(int) * 2);
                ans[j][0] = intervals[i][0];
                ans[j][1] = intervals[i][1];
            }
        }
    }

    *returnSize = j+1;
    int* columnSizes;
    columnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for(i=0; i<*returnSize; i++)
        columnSizes[i] = 2;
    *returnColumnSizes = columnSizes;
    return ans;
}
```