```c
bool isSubsequence(char * s, char * t){
    int s_len = strlen(s);
    int t_len = strlen(t);

    if (s_len > t_len) return false;

    int p = 0;

    for (int i = 0; i < t_len; ++i) {
        if (t[i] == s[p]) {
            p++;
        }
    }
    return p == s_len;
}
```
