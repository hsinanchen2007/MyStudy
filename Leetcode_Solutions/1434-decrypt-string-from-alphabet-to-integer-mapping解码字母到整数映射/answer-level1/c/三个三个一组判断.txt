### 解题思路
此处撰写解题思路

### 代码

```c
char * freqAlphabets(char * s){
    int i = 0;
    int lenth = strlen(s);
    int num = 0;
    
    char *res = calloc(lenth, sizeof(char));
    memset(res, 0, lenth);
    int k = 0;

    while(i < lenth) {
        if ((i + 2 < lenth) && (s[i + 2] == '#')) {
            num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            res[k] = (num + 'a' - 1);
            i += 3;
        }
        else {
            res[k] = 'a' - 1 + (s[i] - '0');
            i++;
        }
        k++;
    }

    return res;
}
```