### 代码

```c
int cmp(const void *a, const void *b) 
{
    char *x = *(char **) a;
    char *y = *(char **) b;
    int lenx = strlen(x);
    int leny = strlen(y);
    if (lenx < leny) {
        return -1;
    } else if (lenx > leny) {
        return 1;
    } else {
        if (strcmp(x, y) <= 0) {
            return 1;
        } else {
            return -1;
        }
    }
}

bool check(char d[], char s[])
{
    for (int i = 0, j = 0; i < strlen(d); i++) {
        while (j < strlen(s) && s[j] != d[i]) j++;
        if (j >= strlen(s)) return false;
        else j++;
    }
    return true;
}

char * findLongestWord(char * s, char ** d, int dSize){
    if (s == NULL || d == NULL || dSize == 0) return "";
    qsort(d, dSize, sizeof(char *), cmp);
    for (int i = dSize - 1; i >= 0; i--) {
        if (check(d[i], s)) {
            return d[i];
        }
    }
    return "";
}
```