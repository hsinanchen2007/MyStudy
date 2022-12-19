```c
#define MAX_SIZE 205
char g_ch[MAX_SIZE][MAX_SIZE];

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** printVertically(char* s, int* returnSize){
    if (s == NULL) {
        *returnSize = 0;
        return NULL;
    }
    memset(g_ch, 0, sizeof(g_ch));
    int i = 0;
    int j = 0;
    int row = 0;
    int col = 0;
    int maxLen = 0;
    char* p = strtok(s, " ");
    while(p)
    {  
        strcpy(g_ch[i], p);
        ++i;
        maxLen = MAX(maxLen, strlen(p));
        p = strtok(NULL, " ");  
    }
    *returnSize = maxLen;
    row = maxLen;
    col = i;
    char **ret = (char**)malloc(sizeof(char*) * row);
    for (j = 0; j < maxLen; ++j) {
        ret[j] = (char*)malloc(sizeof(char) * (col + 1));
    }

    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            if (g_ch[j][i] == '\0') {
                ret[i][j] = ' ';
            } else {
                ret[i][j] = g_ch[j][i];
            }
        }
        ret[i][j] = '\0';
        for (j = col - 1; j >= 0; --j) {
            if (ret[i][j] == ' ') {
                ret[i][j] = '\0';
            } else {
                break;
            }
        }
        
    }

    return ret;
}


```