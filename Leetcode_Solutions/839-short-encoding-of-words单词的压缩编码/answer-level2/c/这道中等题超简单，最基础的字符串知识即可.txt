```
int cmp(char **a, char **b)
{
    return(strlen(*b) - strlen(*a));
}

int minimumLengthEncoding(char ** words, int wordsSize){
    int i;
    char str[16000] = {0};  /* 长度大于 2000 * 7 + 2000(#号) 即可 */
    int cnt = 0;
    char* tmp = NULL;

    if (words == NULL || wordsSize == 0) {
        return 0;
    }

    qsort(words, wordsSize, sizeof(words[0]), cmp); /* 按长度排序，解决像【me, time】这种用例 */
    for (i = 0; i < wordsSize; i++) {
        tmp = strstr(str, words[i]);
        if (tmp == NULL || tmp[strlen(words[i])] != '#') {
            cnt += sprintf(str + cnt, "%s#", words[i]);
        }
    }

    return cnt;
}
```
