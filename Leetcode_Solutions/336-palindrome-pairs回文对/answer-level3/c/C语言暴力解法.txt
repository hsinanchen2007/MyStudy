# 本题目的接口说明
`*returnColumnSizes`是要专门申请一个数组长度是回文对的总数，即`*returnSize`，数组的值都为2

```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define COLUMN_SIZE 2
#define RETURN_SIZE 5000
//判断 字符串是否使回文字符串 x为str起始位置 y为str末尾位置
bool ispalin(char* word, int x, int y){
    while (y > x)
    {
        if (word[x] != word[y])
        {
            return false;
        }
        x++;
        y--;
    }
    return true;
}

/*************************
 * 参数
 *      words 字符串数组
 *      wordSize 字符串总数
 *      *returnSize 返回回文对数
 *      **returnColumnSizes 
 *      返回值 result 返回所有回文对的索引 每个回文对两个索引
 * 
**************************/


int** palindromePairs(char ** words, int wordsSize, int* returnSize, int** returnColumnSizes){
    int resultSize = 0;
    int i;
    int j;
    int **result = (int **)malloc( RETURN_SIZE * sizeof(int *) );
    if(result == NULL)
        return NULL;
    for( i = 0; i < RETURN_SIZE; i++)
    {
        int* tmp = (int *)malloc( COLUMN_SIZE * sizeof(int *));
        if(tmp == NULL)
            return NULL;
        result[i] = tmp;
    }

    //记录每个字符串的长度
    int *len = (int*)malloc(sizeof(int)*wordsSize);
    for (i = 0; i < wordsSize; i++)
    {
        len[i] = strlen(words[i]);
    }
    // 思路：暴力枚举word[i]+word[j] 再判断是否为回文对
    for (i = 0; i < wordsSize; i++){
        for (j = 0; j < wordsSize; j++){
            if (i != j){
                int i1, j1;
                if (len[i] > len[j])//字符串i 长度大于 字符串j
                {
                    i1 = 0;
                    j1 = len[j]-1;
                    while (j1 >= 0)
                    {
                        if (words[i][i1] != words[j][j1])
                        {
                            break;
                        }
                        i1++;
                        j1--;
                    }
                    if (j1 < 0 && ispalin(words[i], len[j], len[i]-1))
                    {
                        result[resultSize][0] = i;
                        result[resultSize][1] = j;
                        resultSize++;
                    }
                }
                else if (len[i] < len[j])//word[i]+word[j]
                {
                    i1 = 0;
                    j1 = len[j]-1;
                    while (i1 < len[i])
                    {
                        if (words[i][i1] != words[j][j1])
                        {
                            break;
                        }
                        i1++;
                        j1--;
                    }
                    if (i1 == len[i] && ispalin(words[j], 0, len[j]-len[i]-1))
                    {
                        result[resultSize][0] = i;
                        result[resultSize][1] = j;
                        resultSize++;
                    }
                }
                else if (i < j)//len(word[i])==len(word[j])
                {
                    i1 = 0;
                    j1 = len[j]-1;
                    while (j1 >= 0)
                    {
                        if (words[i][i1] != words[j][j1])
                        {
                            break;
                        }
                        i1++;
                        j1--;
                    }
                    if (j1 < 0)
                    {
                        result[resultSize][0] = i;
                        result[resultSize][1] = j;
                        resultSize++;
                        result[resultSize][0] = j;
                        result[resultSize][1] = i;
                        resultSize++;
                    }
                }              
            }
        }
    }
    
    
    //返回结果
    *returnSize = resultSize;
    
    if(resultSize > 0){
        *returnColumnSizes = malloc(resultSize*sizeof(int));
        for(i= 0; i < resultSize;i++)
            (*returnColumnSizes)[i] = 2;
    }

    return result;
}
```
