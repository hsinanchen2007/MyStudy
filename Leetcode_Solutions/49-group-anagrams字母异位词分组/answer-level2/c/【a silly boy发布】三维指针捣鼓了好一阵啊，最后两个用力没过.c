```
int cmp(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){

    
    if ((strs == NULL) || (strsSize == 0)) {
        *returnSize = 0;
    }
    int i;
    int j;
    int *flag = (int *)malloc(strsSize * sizeof(int));
    int *flagTmp = (int *)malloc(strsSize * sizeof(int));
    
    char **strsCpy = (char **)malloc(strsSize * sizeof(char*));
    for (i = 0; i < strsSize; i++) {
        strsCpy[i] = (char *)malloc((strlen(strs[i]) + 1) * sizeof(char));
        memcpy(strsCpy[i], strs[i], (strlen(strs[i]) + 1) * sizeof(char));
    }
    
    
    for (i = 0; i < strsSize; i++) {
        qsort(strs[i], strlen(strs[i]), sizeof(strs[i][0]), cmp);
        flag[i] = 0;
        flagTmp[i] = 0;
        //printf("%s\n", strs[i]);
    }
    
    int index = 0;
    
    //判断相同字符串
    for (i = 0; i < strsSize; i++) {
        if (flag[i] == 0) {
            index++;
            flag[i] = index;
            for (j = i + 1; j < strsSize; j++) {
                //printf("strs[%u]: %s, strs[%u]: %s\n", i, strs[i], j, strs[j]);
                if (strcmp(strs[i], strs[j]) == 0) {
                    flag[j] = index;
                }
            }
        }
    }
    
    *returnSize = index;
    (*returnColumnSizes) = (int *)malloc((*returnSize) * sizeof(int));
    
    char ***returnStr = (char ***)malloc(strsSize * sizeof(char **));
    for (i = 0; i < strsSize; i++) {
        returnStr[i] = (char **)malloc(strsSize * sizeof(char *));
        for (j = 0; j < strsSize; j++) {
            returnStr[i][j] = (char *)malloc(40 * sizeof(char));
        }
    }
    
    int tmpValue = 0;
    int jIndex = 0;
 
    for (i = 0; i < strsSize; i++) {
        jIndex = 0;
        if (flagTmp[i] == 0) {
            flagTmp[i] = 1;
            tmpValue = flag[i];
            memcpy(returnStr[tmpValue - 1][jIndex], strsCpy[i], strlen(strsCpy[i]) + 1);
            jIndex++;
            (*returnColumnSizes)[tmpValue - 1] = jIndex;
            for (j = i + 1; j < strsSize; j++) {
                if (flagTmp[j] == 0) {
                    if (tmpValue == flag[j]) {
                        memcpy(returnStr[tmpValue - 1][jIndex], strsCpy[j], strlen(strsCpy[j]) + 1);
                        jIndex++;
                        (*returnColumnSizes)[tmpValue - 1] = jIndex;
                        flagTmp[j] = 1;
                    }            
                }
            }
            
        } 
    } 
    
    /*
    //测试项
    for (i = 0; i < index; i++) {
         memcpy(returnStr[i][0], strsCpy[i], (strlen(strsCpy[i]) + 1) * sizeof(char));
         memcpy(returnStr[i][1], strsCpy[i], (strlen(strsCpy[i]) + 1) * sizeof(char));
         memcpy(returnStr[i][2], strsCpy[i], (strlen(strsCpy[i]) + 1) * sizeof(char));
        (*returnColumnSizes)[i] = 3;
    }
    */
    
    free(flag);
    free(flagTmp);
    
    for (i = 0; i < strsSize; i++) {
        free(strsCpy[i]);
    }
    free(strsCpy);
    
    return returnStr;
}
```
