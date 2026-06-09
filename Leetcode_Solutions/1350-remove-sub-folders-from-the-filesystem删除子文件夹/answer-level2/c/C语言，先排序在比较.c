```
#define min(a,b) ((a) < (b)) ? (a) : (b)
int cmp(const void *arg1, const void *arg2)
{
    char *s1 = *(char**)arg1;
    char *s2 = *(char**)arg2;
    return strcmp(s1, s2);
}
int getlevel(char *s)
{
    int sum = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '/') {
            sum++;
        }
    }
    return sum;
}
char ** removeSubfolders(char ** folder, int folderSize, int* returnSize){
    if (folder == NULL || folderSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(folder, folderSize, sizeof(char*), cmp);
    char **res = malloc(folderSize * sizeof(char*));
    int cnt = 0;
    res[cnt] = (char*)calloc((strlen(folder[0]) + 1), sizeof(char));
    strncpy(res[cnt], folder[0], strlen(folder[0]));
    cnt++;
    for (int i = 1; i < folderSize; i++) {
        int len1 = strlen(res[cnt - 1]);
        int len2 = strlen(folder[i]);
        int minlen = min(len1, len2);
        int level1 = getlevel(res[cnt - 1]);
        int level2 = getlevel(folder[i]);
        if ((strncmp(res[cnt - 1], folder[i], minlen) == 0) && (level1 < level2)) {
            continue;
        }
        res[cnt] = (char*)calloc((strlen(folder[i]) + 1), sizeof(char));
        strncpy(res[cnt], folder[i], strlen(folder[i]));
        cnt++;
    }
    *returnSize = cnt;
    return res;
}
```
