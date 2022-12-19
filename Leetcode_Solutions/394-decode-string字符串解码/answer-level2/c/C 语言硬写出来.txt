### 解题思路
总体思路是递归，每次递归解决一个括号；
每次解决最后出现的括号

### 代码

```c


int GetBoxCount(char *s)
{
    int len = strlen(s);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '[') {
            count++;
        }
    }
    return count;
}

void FindOneBox(char *s, int *start, int *end)
{
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == '[') {
            *start = i;
            break;
        }
    }
    for (int i = *start; i < strlen(s); i++) {
        if (s[i] == ']') {
            *end = i;
            break;
        }
    }
}

int GetCopyCount(char *s, int start, int *len)
{
    int pos = -1;
    for (int i = start - 1; i >= 0; i--) {
        if (s[i] > '9' || s[i] < '0') {
            pos = i;
            break;
        }
    }
    int numLen = pos == -1 ? start : start - pos - 1;
    pos == pos == -1 ? 0 : pos;
    char *str = malloc(numLen + 1);
    memset(str, 0 , numLen + 1);
    strncpy(str, s + pos + 1, numLen);
    *len = numLen;
    int num = atoi(str);
    return num;
}

char * decodeString(char * s){
    if (s == NULL)
        return NULL;
    int count = GetBoxCount(s);
    if (count == 0)
        return s;
    int start = 0;
    int end = 0;
    FindOneBox(s, &start, &end);
    int numLen = 0;
    int num = GetCopyCount(s, start, &numLen);
    char *rets = malloc(strlen(s) + (end - start + 1) * num);
    char *rettmp = rets;
    memset(rets, 0 , strlen(s) + (end - start + 1) * num);
    strncpy(rets, s, start - numLen);
    rets += start - numLen;
    for (int i = 0; i < num; i++) {
        strncpy(rets, s + start + 1, end - start - 1);
        rets += end - start - 1;
    }
    if (end != strlen(s) - 1) {
        strncpy(rets, s + end + 1, strlen(s) - end + 1);
    }
    if (GetBoxCount(rettmp))
        return decodeString(rettmp);
    else 
        return rettmp;

}
```