/* 
找到第一次且只出现一次的字符
建立一个临时数组存储已经出现过且不仅仅一次的字符
*/

```
bool isBelong(char str[], int len, char c)
{
    for (int index = 0; index < len; index++) {
        if (c == str[index]) {
            return true;
        }
    }

    return false;
}

char firstUniqChar(char* s)
{
    int len = strlen(s);
    char *tmp = NULL;
    int strSize = 0;
    
    if ((s == NULL) || (len == 0)) {
        return ' ';
    }

    tmp = (char *)malloc(sizeof(char) * len);
    memset(tmp, 0x0, sizeof(char) * len);
    for (int i = 0; i < len; i++) {
        if ((strSize > 0) && isBelong(tmp, strSize, s[i])) {
            continue;
        }

        bool sign = true;
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                sign = false;
                break;
            }
        }

        if (sign == true) {
            return s[i];
        }

        tmp[strSize++] = s[i];
        // printf("%c %d ", tmp[i], i);
    }

    return ' ';
}
```
