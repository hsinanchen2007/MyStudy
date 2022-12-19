### 解题思路
此处撰写解题思路

### 代码

```c
/**
 DFS + 剪枝; 超时的原因是剪枝不足.
 第一次执行DFS中used过的元素,下次再DFS时,不需要再遍历;
 因为
 1.如果第一次成功了,则已经ok,可以return了
 2.如果第一次失败了,则再访问这些元素,还是会重复失败的"枝",
 所以 used变量只初始化1次即可.

 使用字符串记录长度,导致栈空间用的太多90M,
 如果用short数组记录数字,会好些 43M
 执行用时 :
356 ms, 在所有 C 提交中击败了44.90%的用户
内存消耗 :
43.8 MB, 在所有 C 提交中击败了100.00%的用户
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 8000
#define WLEN 8
char g_end[WLEN];
short int g_out[MAX];
int g_deep;
int g_size;
bool g_exit;

void Init(char *endWord, int wordListSize)
{
    memset(g_end, 0, sizeof(g_end));
    strcpy(g_end, endWord);

    memset(g_out, 0, sizeof(g_out));
    g_deep = 0;
    g_size = wordListSize;
    g_exit = false;  
}

bool isKey(const char *src, const char *dst)
{
    int cnt = 0;
    const int len1 = strlen(src);
    for (int i = 0; i < len1; i++) {
        if (src[i] != dst[i]) {
            cnt++;
        }
    }
    if (cnt != 1) {
        return false;
    }
    return true;
}

bool isEnd(const char *key, int deep, short int *out)
{
    if (strcmp(key, g_end) != 0) {
        return false;
    }

    g_deep = deep;
    memcpy(g_out, out, MAX);
    g_exit = true;
    return true;
}

bool Valid(char **src, int idx, const char *key, bool *used, int deep)
{
    if (used[idx] || deep >= g_size || g_exit) {
        return false;
    }
    if (!isKey(src[idx], key)) {
        return false;
    }
    return true;
}

void Dfs(char **src, int idx, const char *key, bool *used, int *deep, short int *buf)
{
    //printf("%s %d: src=%s, idx=%d, key=%s, used[%d %d %d], deep=%d, buf=%s\n",
    //    __func__, __LINE__, src[idx], idx, key, used[0], used[1], used[2], *deep, buf);
    if (!Valid(src, idx, key, used, *deep)) {
        return;
    }

    if (isEnd(key, *deep, buf)) {
        return;
    }

    int deep1 = *deep + 1;

    short int buf1[MAX] = {0};
    memcpy(buf1, buf, MAX);
    buf1[deep1] = idx;

    if (isEnd(src[idx], deep1, buf1)) {
        return;
    }

    used[idx] = true;
    //printf("%s %d: src=%s, idx=%d, key=%s, used[%d %d %d], deep1=%d, buf1=%s\n",
    //    __func__, __LINE__, src[idx], idx, src[idx], used[0], used[1], used[2], deep1, buf1);
    for (int j = 0; j < g_size; j++) {
        Dfs(src, j, src[idx], used, &deep1, buf1);
    }
}

char** findLadders(char* beginWord, char* endWord, char** wordList, int wordListSize, int* returnSize)
{
    *returnSize = 0;
    Init(endWord, wordListSize);

    bool used[MAX] = {0};
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(beginWord, wordList[i]) == 0) {
            used[i] = true;
        }
    }

    short int buf[MAX] = {0};
    int deep = 0;

    for (int i = 0; i < wordListSize; i++) {
        //printf("%s %d: idx=%d\n", __func__, __LINE__, i);
        Dfs(wordList, i, beginWord, used, &deep, buf);
    }
    if (g_deep == 0) {
        return NULL;
    }

    //printf("%s %d: deep=%d, out=%s\n", __func__, __LINE__, g_deep, g_out);
    g_deep += 1; // 1: head
    char **out = (char **)malloc(sizeof(char *) * g_deep);
    out[0] = malloc(WLEN);
    memset(out[0], 0, WLEN);
    strcpy(out[0], beginWord);
    const int len = strlen(beginWord);
    for (int j = 1; j < g_deep; j++) {
        out[j] = malloc(WLEN);
        memset(out[j], 0, WLEN);
        strcpy(out[j], wordList[g_out[j]]);
    }
    *returnSize = g_deep;
    return out;
}
```