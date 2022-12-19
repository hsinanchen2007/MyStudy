### 解题思路
此处撰写解题思路

### 代码

```c
int g_max = 0;
int g_cnt = 0;
#define MAX_SIZE 128
void GetCnt()
{
    if (g_max < g_cnt) {
        g_max = g_cnt;
    }
}

bool have(bool *use, char newChar)
{
    for (int j = 0; j < MAX_SIZE; j++) {
        if (j != newChar) {
            continue;
        }

        if (use[j]) {
            GetCnt();
            return true;
        }
        use[j] = true;
        g_cnt++;
        GetCnt();
        return false;
    }
    return false;
}

int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    bool use[MAX_SIZE] = {};
    int pos[MAX_SIZE] = {};
    g_max = 0;
    g_cnt = 0;
    for (int i = 0; i < len; i++) {
        if (!have(use, s[i])) {
            pos[s[i]] = i;
        } else {
            memset(use, 0, sizeof(use));
            g_cnt = 0;
            i = pos[s[i]];
        }
    }
    return g_max;
}














```