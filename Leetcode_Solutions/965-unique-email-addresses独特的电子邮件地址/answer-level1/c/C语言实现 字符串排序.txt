### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int numUniqueEmails(char ** emails, int emailsSize){
    if (emails == NULL || emailsSize == 0) return 0;
    char* res[emailsSize];
    for (int i=0; i<emailsSize; i++) {
        int idx=0;
        int len = strlen(emails[i]);
        res[i] = (char*) malloc(len+1);
        int flag1=0, flag2=0;
        for (int j=0; j<len; j++) {
            if (emails[i][j] == '@') {
                flag1 = 0;
                flag2 = 1;
            }
            if (emails[i][j] == '.' && flag2 == 0) continue;
            if ((emails[i][j] == '+' && flag2 == 0) || flag1 == 1) {
                flag1 = 1;
                continue;
            }
            res[i][idx++] = emails[i][j];
        }
        res[i][idx] = '\0';
    }
    qsort(res, emailsSize, sizeof(char*), cmp);
    int count = 1;
    for (int i=1; i<emailsSize; i++) {
        if (strcmp(res[i], res[i-1]))
            count++;
    }
    return count;
}
```