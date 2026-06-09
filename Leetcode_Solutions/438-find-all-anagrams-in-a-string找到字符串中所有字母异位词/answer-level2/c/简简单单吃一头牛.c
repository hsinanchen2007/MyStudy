
![438.png](https://pic.leetcode-cn.com/61fd026dc824b17e4c4b118f739032deeb3307f75dc0a6a44c5671991f4d371a-438.png)


```
int g_target[26] = {0};
int g_temp[26] = {0};

bool EqualString()
{
    for (int i = 0; i < 26; i++) {
        if (g_target[i] != g_temp[i]) {
            return false;
        }
    }
    return true;
}

void InitGlobal()
{
    memset(g_target, 0, sizeof(g_target));
    memset(g_temp, 0, sizeof(g_temp));    
}

void BuildTarget(char *p, int len)
{
    for (int i = 0; i < len; i++) {
        g_target[p[i] - 'a']++;
    }    
}

void BuildTemp(char *p, int len)
{
    for (int i = 0; i < len; i++) {
        g_temp[p[i] - 'a']++;
    }    
}

bool CheckParam(char *s, char *p)
{
    if (!s || !p || strlen(s) < strlen(p)) {
        return false;
    }
    return true;
}

int *findAnagrams(char *s, char *p, int *returnSize)
{
    if (!CheckParam(s, p)) {
        *returnSize = 0;
        return NULL;
    }
    int total = 0;
    int *res = malloc(100 * 1024 * sizeof(int));
    *returnSize = 0;

    InitGlobal();
    BuildTarget(p, strlen(p));

    for (int i = 0; i < strlen(s); i++) {
        memset(g_temp, 0, sizeof(g_temp));
        if (i + strlen(p) <= strlen(s)) {
            BuildTemp(&s[i], strlen(p));
            if (EqualString()) {
                (*returnSize)++;
                res[total++] = i;
            }
        }
    }
    return res;
}
```
