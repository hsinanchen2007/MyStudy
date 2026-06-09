### 解题思路
按照长度排序再加上寻找子串。寻找子串的时候不只是子串就可以了，而且还必须是子串直接到结尾。不是contain,而是contain(p+结束符)。

### 代码

```c
int cmp(const void *p1, const void *p2)
{
    char **s1 = (char **)p1;
    char **s2 = (char **)p2;
    return (strlen(*s2) - strlen(*s1));
}
int minimumLengthEncoding(char ** words, int wordsSize){

    if(words == NULL || wordsSize == 0) {
        return 0;
    }
    int result = 0;
    bool flag = false;
    char *p = NULL;
    qsort(words, wordsSize, sizeof(words[0]), cmp);
    result += (strlen(words[0]) + 1);
    for (int i = 1; i < wordsSize; i++) {
        flag = false;
        for (int j = 0; j < i; j++) {
            p = strstr(words[j], words[i]);
            if (p != NULL) {
                if (*(p + strlen(words[i])) == '\0') {
                    flag = true;
                    break;
                }
            }
        }
        if (flag == false) {
            result += (strlen(words[i]) + 1);   
        }
    }

    return result;

}
```