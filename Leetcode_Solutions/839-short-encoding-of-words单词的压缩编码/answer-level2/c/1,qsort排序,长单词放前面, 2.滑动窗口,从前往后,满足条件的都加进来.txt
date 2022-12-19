### 解题思路
此处撰写解题思路

### 代码

```c
/**
1,qsort排序,长单词放前面,
2.滑动窗口,从前往后,满足条件的都加进来
*/
#define MAX 16000

int Com(const void *a, const void *b)
{
    char *a1 = *(char **)a;
    char *b1 = *(char **)b;
    return strlen(a1) < strlen(b1);
}

int minimumLengthEncoding(char ** words, int wordsSize)
{
    qsort(words, wordsSize, sizeof(char *), Com);
    char out[MAX] = {0};
    char buf[10] = {0};
    sprintf(out, "%s#", words[0]);
    for (int i = 1; i < wordsSize; i++) {
        //printf("%d: i=%d, %s\n", __LINE__, i, words[i]);
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "%s#", words[i]);
        if (strstr(out, buf) != NULL) {
            continue;
        }
        strcat(out, buf);
    }
    return strlen(out);
}
```