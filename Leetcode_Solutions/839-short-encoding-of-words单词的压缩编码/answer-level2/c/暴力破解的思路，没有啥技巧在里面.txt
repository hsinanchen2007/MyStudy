用临时的变量保存输入的字符串数组，然后对这些字符串数组做按照长度排序。
再定义一个足够长的字符数组，用来保存生成的索引字符串，遍历排序完成的字符串数组，有如下两个逻辑：
1、如果字符串数组中的元素不是索引字符串的子串，则将其拼接到索引字符串中
2、如果字符串数组中的元素是索引字符串中的子串，还需要检查是否在子串中字符串数组元素结尾的位置，保存的是'#' 
   例如：
   索引字符串：abcde#ab#
   字符串数组元素： abc
   虽然abd是abcde#ab#的子串，但是abcde#ab#中abc之后的字符并不是'#'，因此需要把abc也拼接进去

说的有点绕，我们考虑题面，要在索引字符串里面找到所有输入的单词，如果2的条件不将abc插入到索引字符串中，那么根据abc索引到的单词将是abcde。
因为在索引字符串中查找单词结束的条件是找到'#'。

代码如下：
```
#define WORDSIZE 2000
#define WORDLEN 8

char g_tempWords[WORDSIZE][WORDLEN] = {0};
char g_Str[WORDSIZE * WORDLEN + WORDSIZE] = {0};
int g_tmpWordLen = 0;

int comp(const void *_a, const void *_b)
{
    return strlen((char *)_a) > strlen((char *)_b) ? -1 : 1;
}

int minimumLengthEncoding(char ** words, int wordsSize){

    g_tmpWordLen = 0;
    memset(g_Str, 0, sizeof(char) * (WORDSIZE * WORDLEN + WORDSIZE));
    memset(g_tempWords, 0, WORDSIZE * WORDLEN);

    for (int i = 0; i < wordsSize; i++) {
        memcpy(g_tempWords[i], words[i], strlen(words[i]));
        g_tmpWordLen++;
    }

    qsort(g_tempWords, g_tmpWordLen, sizeof(g_tempWords[0]), comp);
 
    for (int i = 0; i < g_tmpWordLen; i++) {
        char *subStr = strstr(g_Str, g_tempWords[i]);
        if (subStr == NULL) {
            strcpy(&g_Str[strlen(g_Str)], g_tempWords[i]);
            g_Str[strlen(g_Str)] = '#';
        } else {
            if (subStr[strlen(g_tempWords[i])] != '#') {
                strcpy(&g_Str[strlen(g_Str)], g_tempWords[i]);
                g_Str[strlen(g_Str)] = '#';
            }
        }
    }

    return strlen(g_Str);
}
```

```
