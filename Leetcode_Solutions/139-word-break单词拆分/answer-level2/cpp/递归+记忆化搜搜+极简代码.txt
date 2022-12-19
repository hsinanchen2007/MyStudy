```
int g_st[1000];

bool check(char *s, int start, char dist[])
{
    int lens = strlen(s), lend = strlen(dist);
    if (lens - start < lend) return false;
    for (int i = 0; i < lend; i++) {
        if (s[start + i] != dist[i]) return false;
    }
    return true;
}

bool dfs(char *s, int start, char ** wordDict, int wordDictSize)
{
    if (start == strlen(s)) return true;
    if (g_st[start] != -1) return g_st[start] == 1 ? true : false;
    for (int i = 0; i < wordDictSize; i++) {
        if (check(s, start, wordDict[i])) {
            bool temp = dfs(s, start + strlen(wordDict[i]), wordDict, wordDictSize);
            g_st[start] = temp == true ? 1 : 0;
            if (temp) return true;
        }
    }
    return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    if (s == NULL) return true;
    if (wordDict == NULL || wordDictSize == 0) return false;
    memset(g_st, -1, sizeof(g_st));
    return dfs(s, 0, wordDict, wordDictSize);
}
```
