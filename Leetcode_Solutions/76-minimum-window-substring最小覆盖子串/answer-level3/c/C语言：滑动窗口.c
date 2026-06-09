```c
void mySubstr(char* s, char* res, int start, int len){
    for (int i = 0; i < len; i++){
        res[i] = s[i + start];
    }
    res[len] = '\0';
}

char * minWindow(char * s, char * t){
    int ls = strlen(s), lt = strlen(t);

    if (ls < lt || ls == 0)
        return "";
    int map[128] = {0};
    for (int i = 0; i < lt; i++){
        map[t[i]]++;
    }
    int left = 0, mlen = INT_MAX, idx = 0;
    int cnt = 0;
    for (int i = 0; i < ls; i++){
        map[s[i]]--;
        if (map[s[i]] >= 0){
            cnt++;
        }
        while (cnt == lt){
            if (mlen > i - left + 1){
                mlen = i - left + 1;
                idx = left;
            }
            map[s[left]]++;
            if (map[s[left]] > 0){
                cnt--;
            }
            left++;
        }
    }
    if (mlen == INT_MAX)
        return "";
    char* res = (char*)malloc(sizeof(char) * (mlen + 1));
    mySubstr(s, res, idx, mlen);
    return res;
}
```