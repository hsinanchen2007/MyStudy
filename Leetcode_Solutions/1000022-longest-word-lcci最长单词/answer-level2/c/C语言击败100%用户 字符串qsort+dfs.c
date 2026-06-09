### 解题思路
先将字符串数组按照题目要求排序：长度升序，如果长度相等，按字典序降序
排序完成后，从后向前找满足条件的单词(dfs)，每个待匹配的母串下标用maxi记录，只有排在maxi前面的单词才可能组成它
dfs：
  退出条件：待匹配字符串为空，即完全匹配，return true
  匹配算法：从maxi-1位置向前查找
           长度大于被匹配字符，跳过；
           字符串不匹配，跳过；
           如果能匹配，则偏移后继续使用dfs
  注意：此题认为子字符串可以重复使用，例如["mbzznzbccc","zbmcbbcbze","cbz","cbzcbz"]可以认为"cbzcbz"由2个"cbz"组成，返回值为"cbzcbz"，而不是""。如果题目的字符串不可以重复使用，需要在进入dfs前使用标记位记录字符串使用情况，退出dfs以后再把标记恢复。

### 代码

```c
char** g_words;
int* g_lenList;
int g_wordsSize;
int cmp(const void* a, const void* b)
{
    char* aa = *((char**)a);
    char* bb = *((char**)b);
    int lena = strlen(aa);
    int lenb = strlen(bb);
    if (lena == lenb) {
        return strcmp(bb, aa); // 长度相等时按字典序降序
    }
    return (lena - lenb); // 长度升序
}

bool dfs(const char* maxStr, const int maxi)
{
    int len = strlen(maxStr);
    if (len == 0) {
        return true;
    }
    for (int i = maxi - 1; i >= 0; i--) { // 只有排在maxi前面的单词才可能组成它
        if (g_lenList[i] > len) {
            continue;
        }
        if (strncmp(maxStr, g_words[i], g_lenList[i]) != 0) {
            continue;
        }
        if (dfs(maxStr + g_lenList[i], maxi)) {
            return true;
        }
    }
    return false;
}

/* 计算最长单词的下标 */
int calLong(void)
{
    qsort(g_words, g_wordsSize, sizeof(char*), cmp);
    g_lenList = (int*)malloc(g_wordsSize * sizeof(int));
    for (int i = 0; i < g_wordsSize; i++) {
        g_lenList[i] = strlen(g_words[i]);
    }
    int ret;
    for (ret = g_wordsSize - 1; ret > 0; ret--) {
        if (strcmp(g_words[ret], g_words[ret - 1]) == 0) {
            /* ["o","oi","ozzbxoio","o"] 此处情况不算符合，即"o"不能由另一个"o"组成，虽然我觉得有点奇怪 */
            continue;
        }
        if (dfs(g_words[ret], ret)) {
            free(g_lenList);
            return ret;
        }
    }
    free(g_lenList);
    return ret;
}

char* longestWord(char** words, int wordsSize){
    if ((words == NULL) || (wordsSize == 0)) {
        return NULL;
    }
    g_wordsSize = wordsSize;
    g_words = words;
    int longIndex = calLong();
    char* ret;
    if (longIndex <= 0) {
        ret = (char*)malloc(1 * sizeof(char));
        ret[0] = '\0';
        return ret;
    }
    ret = (char*)malloc((strlen(g_words[longIndex]) + 1) * sizeof(char));
    (void)strcpy(ret, g_words[longIndex]);
    return ret;
}
```