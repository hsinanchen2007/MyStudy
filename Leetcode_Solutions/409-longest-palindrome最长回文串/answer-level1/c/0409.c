```
int longestPalindrome(char *s) {
    int length = strlen(s);

    char *str = (char *) malloc(sizeof(char) * (length + 1));
    strcpy(str, s);
    str[length] = '\0';

    int maxLength = 0;
    int flag = 0;
    for (int i = 0; i < length; ++i) {
        if (str[i] != '_') {
            for (int j = i + 1; j < length; ++j) {
                if (str[i] == str[j]) {
                    maxLength += 2;
                    str[i] = str[j] = '_';
                    break;
                }
            }
        }
        if (flag || str[i] != '_') {
            flag = 1;
        }
    }

    return maxLength + flag;
}
```
