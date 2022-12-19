### 解题思路
1、就是对字符串进行翻转
2、找到每个字符串，然后分别翻转

### 代码

```c
void reverseString(char *s, int len)
{
    for (int index = 0; index < len / 2; index++) {
        char temp;
        temp = s[len - index - 1];
        s[len - index - 1] = s[index];
        s[index] = temp;
    }
    return;
}

char *reverseWords(char *s)
{
    int len = strlen(s);
    char *begin = NULL;
    char *end = NULL;

    if(len <= 0) {
        return s;
    }

    end = s + len;
    if (*(end - 1) == ' ') {
        end--;
    }
    while ((end >= s) && (*end == ' ')) {
        *end = '\0';
        end--;
    }
    len = strlen(s);
    if(len <= 0) {
        return s;
    }

    reverseString(s, len);

    begin = s;
    end = s;
    while (*end != '\0') {
        begin = end;
        while ((*end == ' ') && (*end != '\0')) {
            end++;
        }

        if (end - begin > 1) {
            begin += 1;
            memmove(begin, end, (s + len - end + 1));
            end = begin;
        }

        if (*end == '\0') {
            break;
        }
        begin = end;
        while ((*end != ' ') && (*end != '\0')) {
            end++;
        }

        if (end - begin > 0) {
            reverseString(begin, (end - begin));
        }

        if (*end == '\0') {
            break;
        }
    }

    /* delete kongge */
    if (*(end - 1) == ' ') {
        end--;
    }
    while ((end >= s) && (*end == ' ')) {
        *end = '\0';
        end--;
    }
    return s;
}
```