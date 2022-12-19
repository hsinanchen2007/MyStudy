### 解题思路
c语言常规解法

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** printVertically(char * s, int* returnSize)
{
    int start = 0;
    int end = 0;
    int i;
    int len =  strlen(s);
    int max  = 0;
    int lenArr[201] =  {0};
    *returnSize =0;
    char **res = (char **)malloc(201 * sizeof(char *));
    char **temp = (char **)malloc(201 * sizeof(char *));
    int index = 0;
    for ( i = 0; i < 201; i++) {
        temp[i] = malloc(201 * sizeof(char));
        res[i] = malloc(201 * sizeof(char));
        memset(temp[i], '\0', 201 * sizeof(char));
        memset(res[i], '\0', 201 * sizeof(char));
    }
    for (i = 0; i < len; i++) {
        if (s[i] == ' ') {
            end = i -1;
            memcpy(temp[index], s+start, end - start + 1);
            printf("temp[%d] :%s\n", index, temp[index]);
            index++;
            start = i + 1;
        }
    }
    memcpy(temp[index], s+start, len - start + 1);
    printf("temp[%d] :%s\n", index, temp[index]);
    for (i = 0; i <= index; i++) {
        int temp1 = strlen(temp[i]);
        lenArr[i] = temp1;
        max = max > temp1 ? max : temp1;
    }
    *returnSize = max;
    for ( i = 0; i < max; i++) {
        for (int j = 0; j <= index; j++) {
            if(lenArr[j] > i) {
                res[i][j] = temp[j][i];
            } else {
                res[i][j] = ' ';
            }
        }
    }
    for (i = 0; i < max; i++) {
        for (int j = index; j >= 0; j--) {
            if (res[i][j] != ' ') {
                res[i][j+1] = '\0';
                break;
            }
        }
    }
    return res;
}

```