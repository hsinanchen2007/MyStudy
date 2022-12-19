```
char * removeOuterParentheses(char * S){
    char s1[10000]; // 栈
    char s2[10000]; // 保存去掉最外层括号的结果
    int t1 = -1, t2 = -1, idx = 1; // t1为s1的栈顶指针；t2为s2中保存的最后一个字符的下标；idx保存每一个原语的起点下标
    int sLen = strlen(S);
    char *res; // 保存最终结果

    for (int i = 0; i < sLen; i++) {
        if (S[i] == '(') { // 遇到'('压栈
            s1[++t1] = '(';
        }
        else { // 遇到'）'出栈
            t1--;
        }

        if (t1 == -1) { // 当栈为空时，找到一个原语，去除外层括号后保存至s2
            for (int j = idx; j < i; j++) {
                s2[++t2] = S[j];
            }
            idx = i + 2;
        }
    } 

    res = (char *)malloc((t2 + 2) * sizeof(char)); // 给字符串分配空间：s2中保存的字符的个数为t2+1，另外字符串结尾有一个'\0'，所以分配t2+2个字符空间
    res[t2 + 1] = '\0'; // 字符串尾部赋予'\0'
    for (int i = 0; i <= t2; i++) { // 将s2中保存的字符复制到res中
        res[i] = s2[i];
    }

    return res;
}
```
