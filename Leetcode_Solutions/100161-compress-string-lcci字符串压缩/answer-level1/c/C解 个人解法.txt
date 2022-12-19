### 解题思路
遍历字符串，判断，并与次数拼接后返回。

### 代码

```c
char* compressString(char* S){
    int len = strlen(S);
    char *str = (char *)malloc(sizeof(char) * (2 * len + 1));
    memset(str, 0, sizeof(char)*(2*len+1));
    char tmp = S[0];
    int count = 1;

    for (int i = 0; i < strlen(S); i++) {
        if (S[i + 1] != S[i]) {
            char last_str[8] = "";
            int num = 0;
            num = snprintf(last_str, sizeof(last_str), "%c%d", S[i], count);
            strcat(str, last_str);
            count = 1;
            tmp = S[i + 1];
        } else {
            count++;
        }
    }

    if (strlen(str) >= len) {
        return S;
    }
    return str;
}
```