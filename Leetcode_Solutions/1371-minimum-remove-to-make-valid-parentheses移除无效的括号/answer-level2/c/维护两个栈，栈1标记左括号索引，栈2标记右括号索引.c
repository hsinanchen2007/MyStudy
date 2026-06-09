```
//碰见左括号就入栈1，碰见右括号，如果栈1为底，则栈2入栈
//如果栈1有数据，出栈
char * minRemoveToMakeValid(char * s){
    int slen = strlen(s);
    if (s == NULL || slen == 0) {
        return "";
    }
    char *ret = (char *)malloc(sizeof(char) * (slen + 1));
    memset(ret, 0, sizeof(char) * (slen + 1));
    int stacks1[10001] = { -1 };
    int stacks2[10001] = { -1 };
    int idx1 = -1;
    int idx2 = -1;
    int flag = 0;
    for (int i = 0; i < slen; i++) {
        if (s[i] == '(') {
            stacks1[++idx1] = i;
        } else if (s[i] == ')') {
            if (idx1 == -1) {
                stacks2[++idx2] = i;
            } else {
                --idx1;
            }
        }
    }

    int lidx = 0, ridx = 0, newidx = 0;
    for (int i = 0; i < slen; i++) {
        if (lidx <= idx1 && i == stacks1[lidx]) {
                lidx++;
            }else if (ridx <= idx2 && i == stacks2[ridx]) {
                ridx++;
            } else {
                ret[newidx++] = s[i];
            }
    }
    
    ret[newidx] = '\0';
    return ret;
}
```
