```
char* compressString(char* S){
    if (!S || !strlen(S)) {
        return "";
    }

    int slen = strlen(S);
    char *ans = (char *) calloc(slen + 1, sizeof(char));
    int index = 0;
    int cnt = 1;
    char *p = S;

    // 使用do while可避免使用while还要处理最后一段
    do {
        if (*p == *(p+1)) {
            ++cnt;
        } else {
            ans[index++] = *p;
            /// 这一大块都是为了搞定 cnt > 10的情况，C这点确实挺麻烦的
            int temp = index;
            while (cnt) {
                ans[index++] = '0' + cnt % 10;
                cnt = cnt / 10;
            }
            for (int i = 0; i < (index - temp) / 2; ++i) {
                char ctemp = ans[temp + i];
                ans[temp + i] = ans[index - i - 1];
                ans[index - i - 1] = ctemp;
            }
            /// end
            cnt = 1;

            // 每次判断下是否溢出，溢出就直接return了。
            if (index >= slen) {
                free(ans);
                ans = NULL;
                return S;
            }
        }
        ++p;
    } while (*p != '\0');
    
    return ans;
}
```
