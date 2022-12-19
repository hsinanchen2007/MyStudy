```
#define N 12

char * toHexspeak(char * num){
    long n;
    sscanf(num, "%ld", &n);

    char *ans = (char *)malloc(N);
    memset(ans, 0, N);
    sprintf(ans, "%lX", n);

    int len = strlen(ans);
    for (int i = 0; i < len; i++) {
        if (ans[i] == '0') {
            ans[i] = 'O';
        }
        if (ans[i] == '1') {
            ans[i] = 'I';
        }
        if (ans[i] >= '2' && ans[i] <= '9') {
            return "ERROR";
        }
    }

    return ans;
}
```
