![image.png](https://pic.leetcode-cn.com/b018cad4673c54ef1ea00ae27830c119ae5b6a4fc88bda82df7527cd507f79c9-image.png)
```
#define MAX_VALUE 2147483647
#define MAX_LEN 200
#define min(a, b) ((a) < (b) ? (a) : (b))
int isstartwith(char* S, char* next) {
    char* res = strstr(S, next);
    if (res == S) {
        return 1;
    }
    return 0;
}
int* splitIntoFibonacci(char* S, int* returnSize)
{
    int len = strlen(S);
    int n = len / 2;
    int i, j, pos;
    long long digit, digit2;
    int* ans = (int*)malloc(sizeof(int) * MAX_LEN);
    memset(ans, 0, sizeof(int) * MAX_LEN);
    for (i = 0, digit = 0; i < min(10, n); i++) {
        if (i > 0 && S[0] == '0') break;            
        digit = S[i] - '0' + digit * 10;
        if (digit >= MAX_VALUE)  break;
        for (j = i + 1, digit2 = 0; j < min(10, len); j++) {
            if (j > i + 1 && S[i + 1] == '0')   break;
            digit2 = S[j] - '0' + digit2 * 10;
            if (digit2 >= MAX_VALUE) break;
            pos = 0;
            ans[pos++] = digit;
            ans[pos++] = digit2;
            int k = j + 1;
            while (k < len) {                
                long long nxt = ans[pos - 1];    // 不能直接将两个数相加赋给net,否则会溢出
                nxt += ans[pos - 2];                
                if (nxt > MAX_VALUE)  break;
                char nxtS[MAX_LEN] = {0};
                sprintf(nxtS, "%d", nxt);
                if (isstartwith(S + k, nxtS)) {
                    k += strlen(nxtS);
                    ans[pos++] = nxt;
                } else {
                    break;
                }
            }
            if (pos >= 3 && k == len) {
                *returnSize = pos;
                return ans;
            }
        }
    }    
    *returnSize = 0;
    return 0;
}
```
