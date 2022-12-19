### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char g_out[1000][20];
int g_len;
int g_cnt;

bool Valid(char *s, int i, int step)
{
    if (i > g_len) {
        return false;
    }    
    if (step == 4) {
        if (i != g_len) {
            return false;
        }
        strcpy(g_out[g_cnt++], s);
        return false;
    }
    return true;
}

bool GetNum(char *s, int i, int key, char *out)
{
    if (s[i] == '0' && key != 1) {
        return false;
    }
    int idx = i + key;
    if (idx > g_len) {
        return false;
    }    
    
    char buf[20] = {};
    strncpy(buf, &s[i], key);
    int a = atoi(buf);
    if (a < 0 || a > 255) {
        return false;
    }
    strncpy(buf, s, idx);
    if (s[idx] != '\0') {
        sprintf(out, "%s.%s", buf, &s[idx]);
        return true;
    }
    strcpy(out, s);
    return true;
}

void Dfs(char *s, int i, int *step)
{
    //printf("0.step %d %s %d\n", *step, s, i);
    if (!Valid(s, i, *step)) {
        return;
    }
    //printf("1.step %d %s %d\n", *step, s, i);
    char s3[20] = {0};
    int step3 = *step + 1;
    if (GetNum(s, i, 3, s3)) {
        Dfs(s3, i + 4, &step3);
    }
    char s2[20] = {0};    
    if (GetNum(s, i, 2, s2)) {
        Dfs(s2, i + 3, &step3);
    }
    char s1[20] = {0};
    if (GetNum(s, i, 1, s1)) {
        Dfs(s1, i + 2, &step3);
    }
}

char ** restoreIpAddresses(char * s, int* returnSize)
{
    *returnSize = 0;
    int len = strlen(s);
    if (len > 12 || len < 4) {
        return NULL;
    }

    memset(g_out, 0, sizeof(g_out));
    g_cnt = 0;
    g_len = len + 4;
    int step = 0;
    Dfs(s, 0, &step);
    
    //printf("5.%d: %s\n", g_cnt, g_out[0]);
    if (g_cnt == 0) {
        return NULL;
    }
    *returnSize = g_cnt;
    char **out = (char **)malloc(g_cnt * sizeof(char *));
    for (char i = 0; i < g_cnt; i++) {
        out[i] = (char *)malloc(sizeof(char) * 20);
        strcpy(out[i], g_out[i]);
    }
    return out;
}
```