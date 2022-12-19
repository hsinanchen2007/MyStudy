### 解题思路
倒序遍历，快慢指针
“除了第一个分组以外，每个分组要包含 K 个字符，第一个分组至少要包含 1 个字符。”这句话明显有歧义，导致"2-4A0r7-4k"这个用例会有两种理解
### 代码

```c


char * licenseKeyFormatting(char * S, int K){
    char *ret = (char *)malloc(sizeof(char) * 100000);
    memset(ret, 0, sizeof(char) * 100000);
    int cur = 0;
    int len = K;
    ret[strlen(S)] = '\0';
    for (int i = strlen(S) - 1; i >= 0;) {
        if (S[i] != '-') {
            if (S[i] >= 'a' && S[i] <= 'z') {
                S[i] = S[i] - 'a' + 'A';
            }
            if (len > 0) {
                ret[cur++] = S[i--];
                len--;
            } else {
                ret[cur++] = '-';
                len = K;
            }
        } else {
            i--;
            continue;
        }
    }

    for (int i = 0; i < cur / 2; i++) {
        char tmp = ret[i];
        ret[i] = ret[cur - i - 1];
        ret[cur - i - 1] = tmp;
    }
    ret[cur] = '\0';
    return ret;
}


```