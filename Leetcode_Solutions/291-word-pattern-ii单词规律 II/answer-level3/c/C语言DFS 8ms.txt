```
#include <stdbool.h>
#include <assert.h>
#include <string.h>

int lp, ls;
char *p, *s;

static int tune_pattern(char *pattern, int len, int map[26][3]);
static bool dfs(int map[26][3], int n, int pos, int len);
bool wordPatternMatch(char *pattern, char *str)
{
    lp = strlen(pattern);
    ls = strlen(str);
    if (lp == 0 && ls == 0)
        return true;
    if (lp > ls || lp == 0 || ls == 0)
        return false;
    p = pattern;
    s = str;

    int map[26][3] = {0}; // cnt, last, len
    int n = tune_pattern(pattern, lp, map);
    return dfs(map, n, 0, 0);
}

static bool check_pattern(int map[26][3], int start[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (map[j][2] != map[i][2])
                continue;
            if (memcmp(s + start[i], s + start[j], map[i][2]) == 0)
                return false;
        }
    }
    return true;
}

static void build_start(int map[26][3], int start[26], int n)
{
    memset(start, -1, sizeof(int) * 26);
    int pos = 0;
    for (int i = 0; i < lp; i++) {
        if (start[(int)p[i]] < 0)
            start[(int)p[i]] = pos;
        pos += map[(int)p[i]][2];
    }
    assert(pos == ls);
}

static void build_buff(int map[26][3], int start[26], int n, char *buff)
{
    int pos = 0;
    for (int i = 0; i < lp; i++) {
        memcpy(buff + pos, s + start[(int)p[i]], map[(int)p[i]][2]);
        pos += map[(int)p[i]][2];
    }
    buff[pos] = '\0';
    assert(pos == ls);
}

static bool dfs(int map[26][3], int n, int pos, int len)
{
    if (pos == n) {
        if (len != ls)
            return false;
        int start[26];
        build_start(map, start, n);
        if (!check_pattern(map, start, n))
            return false;
        char buff[ls + 1];
        build_buff(map, start, n, buff);
        return strcmp(s, buff) == 0;
    }

    int max_len = ls - len - map[pos][1];
    int curr_len = map[pos][0];
    map[pos][2] = 1;
    while (curr_len <= max_len) {
        if (dfs(map, n, pos + 1, len + curr_len))
            return true;
        map[pos][2]++;
        curr_len += map[pos][0];
    }

    return false;
}

static int tune_pattern(char *pattern, int len, int map[26][3])
{
    for (int i = 0; i < len; i++)
        map[pattern[i] - 'a'][0]++;

    int temp[26];
    memset(temp, -1, sizeof(temp));
    int pos = 0;
    for (int i = 0; i < 26; i++) {
        if (map[i][0] == 0)
            continue;
        temp[i] = pos;
        map[pos++][0] = map[i][0];
    }

    for (int i = 0; i < len; i++)
        pattern[i] = temp[pattern[i] - 'a'];

    map[pos - 1][1] = 0;
    for (int i = pos - 2; i >= 0; i--)
        map[i][1] = map[i + 1][1] + map[i + 1][0];

    return pos;
}
```
