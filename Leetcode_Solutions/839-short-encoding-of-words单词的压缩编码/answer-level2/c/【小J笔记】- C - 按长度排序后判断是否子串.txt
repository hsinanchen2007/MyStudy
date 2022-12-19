- 假设我们已经有一个函数int IsSubStr(char *word0, char *word1)，可以判断word1是否是word0的子串
- 那么我们将整个单词列表按照字符串长度降序排列，对所有单词标记为未访问
- 从第一个未访问的单词开始，判断之后所有未访问的但是是否是该单词的子串，如果是则标记
- 最终剩余没有被标记的单词长度求和就是答案
```
#define MAX_WORD_SIZE (2010)
#define MAX_WORD_LEN (10)
#define NULL_PTR (0)
#define TRUE (1)
#define FALSE (0)

typedef struct {
    int wordLen;
    char word[MAX_WORD_LEN];
}Word;

Word g_words[MAX_WORD_SIZE];
int g_visit[MAX_WORD_SIZE];

int CmpFunc(const void *a, const void *b)
{
    Word *word0 = (Word*)a;
    Word *word1 = (Word*)b;
    return word1->wordLen - word0->wordLen;
}

int IsSubStr(char *word0, char *word1)
{
    int i,j;
    int len0 = strlen(word0);
    int len1 = strlen(word1);
    i = len0 - 1;
    j = len1 - 1;
    while ((i >= 0) && (j >= 0)) {
        if (word0[i] != word1[j]) {
            return FALSE;
        }
        i--;
        j--;
    }
    return TRUE;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    int i;
    int j;
    int totalLen = 0;
    if ((words == NULL_PTR) || (wordsSize == 0)) {
        return 0;
    }
    for (i = 0; i < wordsSize; i++) {
        g_words[i].wordLen = strlen(words[i]);
        strncpy(g_words[i].word, words[i], strlen(words[i]) + 1);
        g_visit[i] = FALSE;
    }
    qsort(g_words, wordsSize, sizeof(Word), CmpFunc);
    for (i = 0; i <= wordsSize - 1; i++) {
        for (j = i + 1; j <= wordsSize - 1; j++) {
            if (IsSubStr(g_words[i].word, g_words[j].word) == TRUE) {
                g_visit[j] = TRUE;
            }
        }
    }    
    for (i = 0; i <= wordsSize - 1; i++) {
        if (g_visit[i] == FALSE) {
            totalLen += g_words[i].wordLen;
            totalLen++;
        }
    }
    return totalLen;
}
```
