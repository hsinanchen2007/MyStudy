提交时间 提交结果 执行用时 内存消耗 语言
1 分钟前	通过	0 ms	7.1 MB	C

```
int g_allNumbers[26] = {0}; 
int g_total = 0;
int g_score[16] = {0};
int g_wordNumbers[16][26] = {0};

bool check(int i)
{
    for (int j = 0; j < 26; j++) {
        if (g_wordNumbers[i][j] > g_allNumbers[j]) {
            return false;
        }
    }
    return true;
}
void minus(int i)
{
    for (int j = 0; j < 26; j++) {
        g_allNumbers[j] -= g_wordNumbers[i][j];
    }
}
void add(int i)
{
    for (int j = 0; j < 26; j++) {
        g_allNumbers[j] += g_wordNumbers[i][j];
    }
}

void dfs(int *visited, int* score, char ** words, int wordsSize, int total, int curPos)
{
    if (total > g_total) {
        g_total = total;
    }
    int i = curPos;
    while (i < wordsSize) {
        if (check(i) && visited[i] == 0) {
            minus(i);
            visited[i] = 1;
            // printf("i->%d total->%d cur->%d\n", i, total, g_score[i]);
            dfs(visited, score, words, wordsSize, total + g_score[i], i + 1);
            visited[i] = 0;
            add(i);
        }
        i++;
    }
}

int maxScoreWords(char ** words, int wordsSize, char* letters, int lettersSize, int* score, int scoreSize)
{
    int visited[15] = {0};
    g_total = 0;
    memset(g_score, 0, sizeof(g_score));
    memset(g_allNumbers, 0, sizeof(g_allNumbers));
    memset(g_wordNumbers, 0, sizeof(g_wordNumbers));

    for (int i = 0; i < lettersSize; i++) {
        g_allNumbers[letters[i] - 'a']++;
    }
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            g_score[i] += score[words[i][j] - 'a'];
        }
    }
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            g_wordNumbers[i][words[i][j] - 'a']++;
        }
    }
    dfs(visited, score, words, wordsSize, 0, 0);

    return g_total;
}
```
