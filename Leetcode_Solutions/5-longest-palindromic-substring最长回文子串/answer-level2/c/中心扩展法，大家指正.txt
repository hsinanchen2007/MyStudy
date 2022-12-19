int GetMaxExpand(char *s, int off)
{
    int cnt = 0;
    int len = strlen(s);

    while (((off - cnt) > 0) && ((off + cnt) < (len - 1))) {
        if (s[off - cnt - 1] != s[off + cnt + 1]) {
            break;
        }
        cnt++;
    }

    return cnt;
}

char *longestPalindrome(char *s)
{
    char *myS;
    int i, j, len, tmp, off, start, end;

    // 入口参数保护
    if (strlen(s) == 0) {
        myS = (char *)malloc(1);
        myS[0] = '\0';
        return myS;
    }
    // 插入特殊字符#
    myS = (char *)malloc(strlen(s) * 2 + 2);
    len = strlen(s);
    for (i = 0, j = 0; i < len;) {
        myS[j++] = '#';
        myS[j++] = s[i++];
    }
    myS[j++] = '#';
    myS[j] = '\0';
    //printf("%s\n", myS);

    // 中心扩展找到最大回文字符串
    len = strlen(myS);
    off = 0;
    for (i = 1; i < len - 1; i++) {
        tmp = GetMaxExpand(myS, i);
        if (tmp > off) {
            off = tmp;
            start = i - off;
            end = i + off;
            printf("%c ", myS[i]);
            //DebugString(myS + i - off, end - start + 1);
        }
    }

    // 消除特殊符号#
    for (i = start, j = 0; i <= end; i++) {
        if (myS[i] != '#') {
            myS[j++] = myS[i];
        }
    }
    myS[j] = '\0';
    //printf("%s\n", myS);

    return myS;
}