### 解题思路
此处撰写解题思路

### 代码

```c

char* replaceSpaces(char* S, int length){
    if (length > 500000 || length < 0) {
        
    }
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (S[i] == ' ') {
            count++;
        }
    }
    char *res = (char*)malloc(sizeof(char) * (length+2*count+1));
    memset(res, 0, sizeof(char) * (length+2*count+1));
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (S[i] != ' ') {
            res[j++] = S[i];
        } else {
            res[j++] = '%';
            res[j++] = '2';
            res[j++] = '0';
        }
    }
    return res;
}
```