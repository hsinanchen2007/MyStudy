```
char * removeDuplicates(char * S){
    char s[20000], *res;
    int top = -1;

    int sLen = strlen(S);
    for (int i = 0; i < sLen; i++) { // 遍历S中的每一个字符
        s[++top] = S[i]; // 将字符压栈
        if (top > 0 && s[top] == s[top - 1]) { // 如果栈中有2个及以上的字符存在，且栈顶字符与其相邻字符相同，将它们都出栈
            top -= 2;
        }
    }
    res = (char *)malloc((top + 2) * sizeof(char)); // 分配字符串空间
    res[top + 1] = '\0';
    for (int i = 0; i <= top; i++) {
        res[i] = s[i];
    }
    return res;
}
```
