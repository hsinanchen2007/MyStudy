```
int g_totalCnt;

void initCnt(){
    g_totalCnt = 0;
}

void dfsGetCnt(char *s, int left, int right, int min, int max){
    int local_left = left;
    int local_right = right;
    while (local_left >= min && local_right <=max) {
        if (s[local_left] == s[local_right]) {
            g_totalCnt++;
            local_left--;
            local_right++;
            continue;
        }
        return;
    }

    return;
}

int countSubstrings(char * s){

    initCnt();
    int str_len = strlen(s);

    g_totalCnt += str_len;

    //printf("1 cnt %d \r\n", g_totalCnt);

    //奇数两边扩散
    for (int i=1; i<str_len-1; i++) {
        dfsGetCnt(s, i-1, i+1, 0, str_len-1);
    }

    //printf("2 cnt %d \r\n", g_totalCnt);

    //偶数两边扩散
    for (int i=0; i<str_len-1; i++) {
        if (s[i] == s[i+1]) {
            dfsGetCnt(s, i, i+1, 0, str_len-1);
        }
    }

    //printf("3 cnt %d \r\n", g_totalCnt);

    return g_totalCnt;
}
```
