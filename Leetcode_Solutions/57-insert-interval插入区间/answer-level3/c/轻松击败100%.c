```


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int pushbackInterval(int **result, int num, int *element, int *colSize) {
    result[num] = (int*)malloc(sizeof(int)*10);
    result[num][0] = element[0];
    result[num][1] = element[1];
    colSize[num] = 2;
    return num + 1;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int *insert = newInterval;
    int **result = (int**)malloc(sizeof(int*)*(intervalsSize+1));
    *returnColumnSizes = (int*)malloc(sizeof(int)*(intervalsSize+1));
    
    int num = 0;
    for (int i = 0; i < intervalsSize; i++) {
        int *e = intervals[i];
        
        if (!insert) {
            num = pushbackInterval(result, num, e, *returnColumnSizes);
            continue;
        }
        
        if (e[1] < insert[0]) {
            num = pushbackInterval(result, num, e, *returnColumnSizes);
            continue;
        }
        
        if (e[0] > insert[1]) {
            num = pushbackInterval(result, num, insert, *returnColumnSizes);
            insert = NULL;
            
            num = pushbackInterval(result, num, e, *returnColumnSizes);
            continue;
        }
        
        insert[0] = insert[0] < e[0] ? insert[0] : e[0];
        insert[1] = insert[1] > e[1] ? insert[1] : e[1];
    }
    
    if (insert) {
        num = pushbackInterval(result, num, insert, *returnColumnSizes);
    }
    
    *returnSize = num;
    return result;
}



```
