```
void backTrack(char* s, int sLen, int flag, int* res) {
    if (flag == sLen) (*res)++;
    else {
        if (s[flag] == '0') return;
        backTrack(s,sLen, flag + 1, res);
        if (flag + 2 > sLen) return;
        if (s[flag] > '2') return;
        if (s[flag] == '2' && s[flag + 1] > '6') return;
        backTrack(s, sLen, flag + 2, res);
    }
}
int numDecodings(char * s){
    int res = 0;
    int sLen = strlen(s);
    if (sLen == 0) return res;
    backTrack(s, sLen, 0, &res);
    return res;
}
```
