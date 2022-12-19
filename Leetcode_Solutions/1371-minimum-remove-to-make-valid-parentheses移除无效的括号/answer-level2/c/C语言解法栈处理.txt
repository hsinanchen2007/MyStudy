```
char * minRemoveToMakeValid(char * s)
{
    int len = strlen(s);
    int *stk = (int *)malloc(sizeof(int) * len);
    int *ret = (int *)malloc(sizeof(int) * len);
    /* 注意加1 预留 */
    char *stret = (char *)malloc(sizeof(char) * (len+1));

    int top = 0;
    int num = 0;

    int i = 0;
    for (i = 0; i < len; i++) {
        ret[i] = -1;
    }

    for (i = 0; i < len; i++) {
        if (s[i] == '(') {
            stk[top] = i;
            top++;
        } else if (s[i] == ')') {
            if (top == 0) {
                ret[num++] = i;
            } else {
                top--;
            }
        }
    }

    while (top != 0) {
        top--;
        ret[num++] = stk[top];
    }

    for (int i = 0; i < len; i++) {
        if (ret[i] != -1) {
            s[ret[i]] = '0';
        }
    }

    int ls = 0;
    for (i = 0; i < len; i++) {
        if (s[i] == '0') {
            continue;
        }
        stret[ls++] = s[i];
    }

    stret[ls] = '\0';
    free(ret);
    free(stk);
    return stret;
}
```
