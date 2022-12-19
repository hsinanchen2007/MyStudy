```c
#define SIZE 26
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

bool g_vis[SIZE];

bool CanTake(char* str, int len)
{
    int i, j;
    for (i = 0; i < len; ++i) {
        if (g_vis[str[i] - 'a']) {
            for (j = 0; j < i; ++j) {
                g_vis[str[j] - 'a'] = false;
            }
            return false;
        }
        g_vis[str[i] - 'a'] = true;
    }
    return true;
}

void ResetVis(char* str)
{
    while (*str) {
        g_vis[*str - 'a'] = false;
        ++str;
    }
}

int Dfs(char** arr, int arrSize, int index)
{
    int i;
    int len;
    int ret = 0;
    for (i = index; i < arrSize; ++i) {
        len = strlen(arr[i]);
        if (CanTake(arr[i], len)) {
            ret = MAX(ret, len + Dfs(arr, arrSize, i + 1));
            ResetVis(arr[i]);
        }
    }
    return ret;
}

int maxLength(char ** arr, int arrSize){
    if (arr == NULL || arrSize == 0) {
        return 0;
    }
    memset(g_vis, 0, sizeof(g_vis));
    return Dfs(arr, arrSize, 0);
}

```