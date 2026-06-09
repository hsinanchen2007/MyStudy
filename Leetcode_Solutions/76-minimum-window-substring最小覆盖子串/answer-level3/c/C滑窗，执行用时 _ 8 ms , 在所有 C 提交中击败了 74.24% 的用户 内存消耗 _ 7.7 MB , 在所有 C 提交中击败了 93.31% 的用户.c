### 解题思路
此处撰写解题思路

### 代码

```c
#define GET_MIN(minLen, minLeft, right, left) \
{ \
    if (minLen > right - left + 1) { \
        minLen = right - left + 1; \
        minLeft = left; \
    } \
} 
#define MAX_HASH_SIZE 58 //('z' - 'A' + 1)
int g_lens = 0;
int g_lent = 0;

int g_sHash[MAX_HASH_SIZE];
int g_tHash[MAX_HASH_SIZE];

void GetMinWindowNextLeft(char *s, int right, int *left)
{
    for (int i = *left; i <= right; i++) {
        if (g_tHash[s[i] - 'A'] == 0) {
            continue;
        }
        if (g_sHash[s[i] - 'A'] == g_tHash[s[i] - 'A']) {
            *left = i;
            break;
        }
        g_sHash[s[i] - 'A']--;
    }
    return;
}

bool GetMinWindowNextRight(char *s, int *left, int *right)
{
    for (int i = *right + 1; i < g_lens; i++) {
        if (s[i] == s[*left]) {
            *right = i;
            (*left)++;
            return true;
        }
        if (g_tHash[s[i] - 'A'] > 0) {
            g_sHash[s[i] - 'A']++;
        }
        
    }
    return false;
}

int GetMinWindowFirst(char *s, char *t, int *right)
{
    if ((g_lens == 0) || (g_lent == 0)) {
        return 0;
    }
    memset(g_sHash, 0, MAX_HASH_SIZE * sizeof(int));
    memset(g_tHash, 0, MAX_HASH_SIZE * sizeof(int));

    for (int i = 0; i < g_lent; i++) {
        g_tHash[t[i] - 'A']++;
    } 

    for (int i = 0; i < g_lens; i ++) {
        bool match = true;
        if (g_tHash[s[i] - 'A'] == 0) {
            continue;
        }
        g_sHash[s[i] - 'A']++;
        if (g_sHash[s[i] - 'A'] > g_tHash[s[i] - 'A']) {
            continue;
        }
        for (int j = 0; j < MAX_HASH_SIZE; j++) {

            if (g_sHash[j] < g_tHash[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            *right = i;
            return i + 1;
        }
    }
    return 0;
}

char *minWindow(char * s, char * t)
{
    int minLen = 0;
    int minLeft = 0;
    int left = 0;
    int right = 0;
    g_lens = strlen(s);
    g_lent = strlen(t);

    /* 获取第一个非最优解的右边界 */
    minLen = GetMinWindowFirst(s, t, &right);
    if (minLen == 0) {
        return "";
    }
    
    /* */
    while (right < g_lens) {
        GetMinWindowNextLeft(s, right, &left); // 基于右边界获取最优解的左边界
        GET_MIN(minLen, minLeft, right, left);
        if (!GetMinWindowNextRight(s, &left, &right)) { // 获取下一个非最优解的右边界
            break;
        }
    }

    s[minLen + minLeft] = '\0';
    return s + minLeft;
}
```