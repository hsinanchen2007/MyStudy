### 解题思路
此处撰写解题思路

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** getValidT9Words(char* num, char** words, int wordsSize, int* returnSize){
    char tbl[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};

    int i,j;
    int tmp;
    int len = strlen(num);
    char **matrix = (char **)malloc(sizeof(char *) * wordsSize);
    char **rlt = (char **)malloc(sizeof(char *) * wordsSize);

    // 先计算出每一个单词对应在手机上应该输入的字母号
    for (i = 0; i < wordsSize; i++) {
        matrix[i] = (char *)malloc(sizeof(char) * (len + 1));
        for (j = 0; j < len; j++) {
            tmp = words[i][j] - 'a';
            matrix[i][j] = tbl[tmp];
        }
        matrix[i][j] = 0;
    }

    // 然后将所有单词对应的字母号和输入的num比对
    *returnSize = 0;
    for (i = 0; i < wordsSize; i++) {
        if (strcmp(matrix[i], num) == 0) {
            rlt[*returnSize] = words[i];
            (*returnSize)++;
        }
    }
    return rlt;
}


```