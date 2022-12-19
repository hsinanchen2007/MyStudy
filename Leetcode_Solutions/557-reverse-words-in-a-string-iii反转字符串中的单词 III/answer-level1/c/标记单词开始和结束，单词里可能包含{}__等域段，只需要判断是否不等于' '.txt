int word(char c)
{
    if ((c != ' ') && (c != '\0')) {
        return 1;
    } else {
        return 0;
    }
}
char *reverseWords(char *s)
{
    int i;
    int j;
    int len;
    int start;
    int end;
    int n = 0;
    char *result;
    int flag = 0;  // 0代表前一个非字母，1代表前一个是字母
    len = strlen(s);
    result = (char *)malloc(len + 1000000000);
    if (len == 0) {
        result[0] = '\0';
        return result;
    }
    for (i = 0; i <= len; i++) {
        if (flag == 0 && word(s[i])) {
            start = i;
            flag = 1;
        }
        if ((flag == 1) && ((s[i] == ' ') || (s[i] == '\0'))) {
            // printf("i:%d\n",i);
            flag = 0;
            i--;
            end = i;
            for (j = end; j >= start; j--) {
                result[n++] = s[j];
            }
            if (s[i + 1] != '\0') {
                result[n++] = ' ';
            }
        }
    }
    if (result[n - 1] == ' ') {
        n--;
    }
    result[n] = '\0';
    return result;
}