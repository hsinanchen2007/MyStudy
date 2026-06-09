### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int g_len = 0;
int g_cnt = 0;
char g_out[100000][10];

bool Valid(int i, char *used)
{
    if (used[i]) {
        return false;
    }

    return true;
}

void Dfs(const char *s, int i, char *used, char *out, int *deep)
{
    if (!Valid(i, used)) {
        return;
    }
    char used1[10] = {0};
    memcpy(used1, used, sizeof(used1));
    used1[i] = true;   

    char out1[10] = {0};
    strcpy(out1, out);
    out1[*deep] = s[i];

    int deep1 = *deep + 1;
    if (deep1 == g_len) {
        strcpy(g_out[g_cnt++], out1);
        return;
    }

    for (int j = 0; j < g_len; j++) {
        Dfs(s, j, used1, out1, &deep1);
    }
}

char** permutation(char* S, int* returnSize){
    *returnSize = 0;
    g_len = strlen(S);
    g_cnt = 0;
    memset(g_out, 0, sizeof(g_out));

    char used[10];
    char out[10];
    for (int i = 0; i < g_len; i++) {
        memset(used, 0, sizeof(used));
        memset(out, 0, sizeof(out));
        int deep = 0;
        Dfs(S, i, used, out, &deep);     
    }
    
    char **out1 = (char **)malloc(sizeof(char *) * g_cnt);
    for (int i = 0; i < g_cnt; i++) {
        out1[i] = malloc(10);
        strcpy(out1[i], g_out[i]);
    }
    *returnSize = g_cnt;
    return out1;
}
```