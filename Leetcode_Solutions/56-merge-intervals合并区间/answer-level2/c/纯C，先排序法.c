![1.png](https://pic.leetcode-cn.com/de2478c591767cb6a651affb57b482b026b1841b7902e662bab32522cf1509a1-1.png)

### 解题思路
本题坑比较多，先排序

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmq2(int **a, int **b){
	return **a - **b;
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
	if (intervalsSize == 1){
		*returnSize = 1;
		** returnColumnSizes = *intervalsColSize;
		return intervals;
	}
    else if(intervalsSize < 1){
        *returnSize = 0;
        return 0;
    }
    qsort(intervals, intervalsSize, sizeof(int*), cmq2);
	int **res = (int**)malloc(sizeof(int*)*intervalsSize), x = 0;
	res[x++] = (int*)malloc(sizeof(int)*(*intervalsColSize));
	res[0][0] = intervals[0][0];
	res[0][1] = intervals[0][1];
	(*returnColumnSizes)[0] = *intervalsColSize;
	for (int i = 1; i < intervalsSize; i++){
		if (intervals[i][0] <= res[x-1][1]){
			res[x-1][1] = intervals[i][1]>res[x-1][1]?intervals[i][1]:res[x-1][1];
		}
		else{
			res[x] = (int*)malloc(sizeof(int)*(*intervalsColSize));
			res[x][0] = intervals[i][0];
			res[x][1] = intervals[i][1];
			(*returnColumnSizes)[x] = *intervalsColSize;
            x++;
		}
	}
    *returnSize = x;
	return res;
}
```