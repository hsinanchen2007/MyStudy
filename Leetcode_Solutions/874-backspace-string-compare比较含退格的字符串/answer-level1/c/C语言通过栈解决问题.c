```
bool backspaceCompare(char * S, char * T){
    char *SStack = (char *)malloc(200 * sizeof(char)); // 保存S中有效字符的栈
    char *TStack = (char *)malloc(200 * sizeof(char)); // 保存T中有效字符的栈
    int STop = -1, TTop = -1; // 栈顶

    for (int i = 0; i < strlen(S); i++) { // 将S中字符压栈
        if (S[i] == '#') {
            if (STop > -1) {
                STop--;
            }
        }
        else {
            SStack[++STop] = S[i];
        }
    }

    for (int i = 0; i < strlen(T); i++) { // 将T中字符压栈
        if (T[i] == '#') {
            if (TTop > -1) {
                TTop--;
            }
        }
        else {
            TStack[++TTop] = T[i];
        }
        printf("%d ", TTop);
    }

    if (STop != TTop) { // 若栈顶高度不一致，S与T不同
        return false;
    }
    else { // 栈高一致的情况下，判断内含字符是否一致
        while (STop > -1) {
            if (SStack[STop] != TStack[TTop]) {
                break;
            }
            STop--;
            TTop--;
        }
        if (STop == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    free(SStack);
    free(TStack);
}
```
