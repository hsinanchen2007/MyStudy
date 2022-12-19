```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findOcurrences(char *text, char *first, char *second, int *returnSize)
{
    char **res = (char **)malloc(sizeof(char *) * 1000);
    for (int i = 0; i < 1000; ++i) {
        res[i] = (char *)malloc(sizeof(char) * (20 + 2));
    }

    char **res1 = (char **)malloc(sizeof(char *) * 1000);
    for (int i = 0; i < 1000; ++i) {
        res1[i] = (char *)malloc(sizeof(char) * (20 + 2));
    }

    int k = 0;
    int m = 0;
    for (int i = 0; i < strlen(text); i++) {
       

        if (text[i] != ' ') {
            res[k][m++] = text[i];
        }

        if (text[i] == ' ') {
            res[k][m] = '\0';
            k++;
            m = 0;
        }

        if (text[i] == '\0') {
            res[k][m] = '\0';
            k++;
            m = 0;
            }
    }
    res[k][m] = '\0';
    
    k = k + 1;
    int size = 0;

    for (int i = 0; i < k - 2; i++) {
        if (strcmp(res[i], first) == 0 && strcmp(res[i + 1], second) == 0) {
            strcpy(res1[size], res[i + 2]);
            res1[size++][strlen(res[i + 2]) + 1] = '\0';
        }
    }
    *returnSize = size;
    return res1;
}

```
