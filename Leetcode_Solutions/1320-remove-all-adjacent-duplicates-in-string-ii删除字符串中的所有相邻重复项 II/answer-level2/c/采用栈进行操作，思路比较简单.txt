```
char * removeDuplicates(char * s, int k){
    int sLen = strlen(s);

    /* 输入有效性判断  */
    if ((sLen == 0) || (k > sLen) || (k < 2)) {
        return s;
    }

    char* charBuff = (char *)malloc(sizeof(char) * (sLen + 1)); /* 栈1：用于存储字符 */
    int*  numBuff  = (int *)malloc(sizeof(int) * sLen); /* 栈2：用于存储当前字符的个数 */
    memset(charBuff, '\0', sLen + 1);
    memset(numBuff, 0, sLen);

    int top = -1; /* 栈顶索引 */
    int idx;

    for (idx = 0; idx < sLen; idx++) {
        if (top == -1) {
            top++;
            charBuff[top] = s[idx];
            numBuff[top]  = 1;
        } else {
            if (s[idx] != charBuff[top]) {
                top++;
                numBuff[top] = 1;
            } else {
                top++;
                numBuff[top] = numBuff[top - 1] + 1;
            }

            charBuff[top] = s[idx];
            //printf("idx:%d, top:%d\n", idx, top);
            if (numBuff[top] == k) {
                for (int i = top; i > top - k; i--) {
                    charBuff[i] = '\0';
                    numBuff[i]  = 0;
                }
                top = top - k;
            }
            //printf("top:%d, char:%c, num:%d\n", top, charBuff[top], numBuff[top]);
        }
    }

    return charBuff;
}
```
