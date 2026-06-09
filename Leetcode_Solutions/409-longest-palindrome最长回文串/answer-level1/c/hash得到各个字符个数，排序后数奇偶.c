hash判断字母个数，奇数个第二次出现时需减一
```
#define HASHSIZE 128
int comp (const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}
int longestPalindrome(char * s){
    int hashword[HASHSIZE] = { 0 };
    int len = strlen(s);
    int flag = 0; //代表遇到奇数了
    if (s == NULL || len == 0) {
        return 0;
    }
    int longestcnt = 0;
    for (int i = 0; i < len; i++) {
        hashword[s[i]]++;
    }
    qsort(hashword, HASHSIZE, sizeof(int), comp);
    for (int j = 0; j < HASHSIZE; j++) {
        if (hashword[j] == 0) {
            break;
        } else {
            if (hashword[j] % 2 == 0) {
                longestcnt += hashword[j];
            } else {
                if (flag == 0) {
                    longestcnt += hashword[j];
                    flag = 1;
                } else {
                    longestcnt += hashword[j] - 1;
                }
            }
        }
    }
    return longestcnt;
}
```
