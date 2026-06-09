### 解题思路
分三步，空间复杂度O(1):
1. 去除所有多余空格。
2. 整个句子字符翻转。
3. 对#2后的字符串里的每个单词字符翻转。

### 代码

```c
void reverse_str(char *s, int len)
{
    int i = 0;
    int j = len - 1;
    char ch;

    for (; i < j; i++, j--) {
        ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    };
}

char *reverseWords(char *s)
{
    int wh = 0, i;
    char *p = s;

    /* 1. strip whitespaces */
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            continue;
        }

        if (p != s && s[i-1] == ' ')
            *(p++) = ' ';
        *(p++) = s[i];
    }
    *(p) = '\0';

    /* 2. reverse the entire string. */
    reverse_str(s, strlen(s));

    /* 3. reverse each word. */
    p = s;
    for (i = 0; ; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverse_str(p, &s[i] - p);
            if (s[i] == '\0')
                break;
            else
                p = &s[i+1];
        }
    }

    return s;
}
```