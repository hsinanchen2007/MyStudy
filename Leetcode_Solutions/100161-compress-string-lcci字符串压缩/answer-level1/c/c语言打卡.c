### 解题思路
此处撰写解题思路

### 代码

```c
char* compressString(char* S){
    char n[50000], *result = (char*)calloc(strlen(S), sizeof(char));
    int i = 0, j ,k = 0, num, len = strlen(S) - 1;
    bool flag = 1;
    while(i < strlen(S)){
        memset(n, 0, sizeof(char) * 50000);
        for(j = i + 1, num = 1;S[j] == S[i] && j < strlen(S);num ++, j ++);
        sprintf(n, "%d", num);
        if(k + 1 + strlen(n) > len){
            flag = 0;
            break;
        }
        result[k] = S[i];
        strncat(result, n, strlen(n));
        k += 1 + strlen(n);
        i = j;
    }
    if(flag)
        return result;
    else
        return S;
}
```