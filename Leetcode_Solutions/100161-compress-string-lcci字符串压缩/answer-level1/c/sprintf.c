### 解题思路
此处撰写解题思路

### 代码

```c
int ProcessDuplicate(char* str, int a)
{
    char string[50000] = {0};
    sprintf(string, "%d", a);
    int len = strlen(string);
    memcpy(str, string, len);
    return len;
}
char* compressString(char* S){
    if (S == NULL) {
        return S;
    }
    int len = strlen(S);
    if (len <= 2) {
        return S;
    }
    char *ret= (char *)malloc(sizeof(char) * 2 * (len + 1));
    memset(ret, 0,  2 * (len + 1));
    int index = 0;
    int startFlag = 0;
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (startFlag == 0) {
            ret[index] = S[i];
            index++;
            cnt = 1;
            startFlag = 1;
        } else {
            if (S[i] == S[i - 1]) {
                cnt++;
            } else {
                int diff = ProcessDuplicate(ret + index, cnt);
                index += diff;

                ret[index] = S[i];
                index++;
                cnt = 1;
            }
        }
        if (index >= len) {
            return S;
        }
    }
    ProcessDuplicate(ret + index, cnt);
    return ret;
}
```