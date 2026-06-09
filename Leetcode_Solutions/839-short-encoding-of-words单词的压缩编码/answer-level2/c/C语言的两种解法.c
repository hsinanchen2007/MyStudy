/* 解法 1 : 字典树 （优化前）*/
1. 一遍遍历，对每个`words[i]`逆序建立字典树。
2. 建树过程中，在每个单词进入字典树后，记录该单词第一个字母（逆序的最后一个字母）是否在树中使用的是新建节点，如果是新建（`nk == 1`）则记录该节点长度加1（加#）：`color[p] = ilen + 1;`。
3. 在每个单词的字母进入字典树的同时，由于较短的单词变为前缀所以需要清除前期该节点上记录的长度（`color[p] = 0;`），这样做到仅记录较长的单词长度。
4. 最后对`color[MAX_NODES]`中里记录的长度累加。
```
int minimumLengthEncoding(char ** words, int wordsSize){
    #define MAX_NODES (2000 * 7 + 10)
    #define MAX_CHARS (26 * 2 + 2)
    int trieP[MAX_NODES][MAX_CHARS] = {0};
    int color[MAX_NODES] = {0};
    int k  = 1;
    for( int i = 0; i < wordsSize; i++ ) {
        int ilen = strlen(words[i]);
        int p  = 0;
        int nk = 0;
        for( int j = ilen - 1; j >= 0; j-- ) {
            int c  = words[i][j] - 'a';
            if( trieP[p][c] == 0 ) {
                trieP[p][c] = k;
                k++;
                nk = 1;
            }
            color[p] = 0;
            p = trieP[p][c];
        }
        if( nk == 1 ) color[p] = ilen + 1;
    }

    int sum = 0;
    for( int i = 1; i < k; i++ ) sum += color[i];
    return sum;
}
```

/* 解法1 优化后一次循环搞定 */

```
int minimumLengthEncoding(char ** words, int wordsSize){
    #define MAX_NODES (2000 * 7 + 10)
    #define MAX_CHARS (26 * 2 + 2)
    int trieP[MAX_NODES][MAX_CHARS] = {0};
    int color[MAX_NODES] = {0};
    int sum = 0;
    int k  = 1;
    for( int i = 0; i < wordsSize; i++ ) {
        int ilen = strlen(words[i]);
        int p  = 0;
        int nk = 0;
        for( int j = ilen - 1; j >= 0; j-- ) {
            int c  = words[i][j] - 'a';
            if( trieP[p][c] == 0 ) {
                trieP[p][c] = k;
                k++;
                nk = 1;
            }
            sum -= color[p];
            color[p] = 0;
            p = trieP[p][c];
        }
        if( nk == 1 ) {
            color[p] = ilen + 1;
            sum += color[p];
        }
    }

    return sum;
}
```

/* 解法 2 排序后暴力 */
1. 先对所有单词按长度进行逆序（从大到小）排序。
2. 按照顺序（从大到小）两两比较，过滤掉所有被较长单词后缀包含的较短的单词。
3. 对未包含的单词长度进行累加。
```
int cmp(const void * a, const void * b) {
    return strlen(*(const char **)b) - strlen(*(const char **)a);
}

int minimumLengthEncoding(char ** words, int wordsSize){
    qsort(words, wordsSize, sizeof(char *), cmp);

    int flag[2000] = {0};
    int total = 0;
    char * find = 0;
    for( int i = 0; i < wordsSize; i++ ) {
        if ( flag[i] == 1 ) {
            continue;
        }
        int ilen = strlen(words[i]);
        total +=  ilen + 1;
        for( int j = i + 1; j < wordsSize; j++ ) {
            int jlen = strlen(words[j]);
            find = strstr(words[i] + ilen - jlen, words[j]);
            if( find != 0 ) {
                flag[j] = 1;
            }
        }
    }

    return total;
}
```
