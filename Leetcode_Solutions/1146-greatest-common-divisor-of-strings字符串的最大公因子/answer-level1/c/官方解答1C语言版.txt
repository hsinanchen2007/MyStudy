### 解题思路
此处撰写解题思路

### 代码

```c
bool Check(char* s, char* t){
    int lent = strlen(t);
    int lens = strlen(s);
    char* res = (char*)calloc(sizeof(char), (lent + 1));
    int len = strlen(t) / strlen(s); 
    for (int i = 1; i <= len; ++i) {
        strcat(res, s);
    }
    res[lent] = '\0';
    return strcmp(res, t) == 0;
}

char * gcdOfStrings(char * str1, char * str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = len1 < len2 ? len1 : len2;
    for (int i = min_len; i > 0; --i) {
        if (len1 % i == 0 && len2 % i == 0) {
            char* res = (char*)malloc(sizeof(char) * (i + 1));
            strncpy(res, str1, i);
            res[i] = '\0';
            if (Check(res, str1) && Check(res, str2)) {
                return res;
            }
        }
    }
    return "";
}
```