### 解题思路
此处撰写解题思路

### 代码

```c
int g_len = 0;

void Dfs(char *s, int i, int *cnt)
{
    if (s[i] == '0') {
        return;
    }
    if (i >= g_len - 1) {
        *cnt += 1;
        //printf("1.5  %d-- %d\n", i, *cnt);
        return;
    }
    //printf("2.  %d-- %d\n", i, *cnt);
    if (i <= g_len - 2) {
        if (s[i + 1] != '0') {
            Dfs(s, i + 1, cnt);
        }
        if ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6')) {
            Dfs(s, i + 2, cnt);
        }
    }
}

int numDecodings(char * s){
    g_len = strlen(s);
    int cnt = 0;
    Dfs(s, 0, &cnt);
    return cnt;
}
```