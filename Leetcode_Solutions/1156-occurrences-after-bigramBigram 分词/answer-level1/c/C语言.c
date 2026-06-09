### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findOcurrences(char * text, char * first, char * second, int* returnSize){
    char *retstr = NULL;
    int resSize = 0;
    int flag1 = 0;
    int flag2 = 0;


    char **res = (char**)malloc(sizeof(char*) * 1000);

    while ((retstr = strtok(text, " ")) != NULL) {
        text = NULL;
        if (flag1 == 1 && flag2 == 1) {
            res[resSize] = (char*)malloc(sizeof(char) * 11);
            memset(res[resSize], 0x00, sizeof(char) * 11);
            strcpy(res[resSize], retstr);
            resSize++;
            flag1 = 0;
            flag2 = 0;
        }

        if (strcmp(first, retstr) == 0) {
            flag1 = 1;
            continue;
        }
        if (flag1 == 1) {
            if (strcmp(second, retstr) == 0) {
                flag2 = 1;
            } else {
                flag1 = 0;
                flag2 = 0;
            }
        }
    }

    *returnSize = resSize;

    return res;
}
```