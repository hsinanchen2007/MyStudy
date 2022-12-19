利用strtok函数分割字符串，然后嵌套循环解决，目前看这样比较清晰
```
bool wordPattern(char * pattern, char * str){
    int len = strlen(pattern);
    if(len==0) return false;

    char** strList = (char**)malloc(1000*sizeof(char*));
    int head = -1;

    char tmp[strlen(str)+1];
    memcpy(tmp, str, strlen(str)+1);

    char* pChar = strtok(tmp, " ");
    while(true){
        if(!pChar) break;
        strList[++head] = (char*)calloc(50, sizeof(char));
        memcpy(strList[head], pChar, strlen(pChar));
        pChar = strtok(NULL, " ");
    }

    if(len != head+1) return false;

    int flag[len];
    for(int i=0; i<len; i++) {
        flag[i] = 1;
    }

    for (int i=0; i<len; i++) {
        if (!flag[i]) continue;
        flag[i] = 0;
        for (int j=i+1; j<len; j++) {
            if (!flag[j]) continue;
            if (pattern[i] == pattern[j]) {
                flag[j] == 0;
                if (strcmp(strList[i], strList[j])) {
                    return false;
                }
            }
        }
    }
    // 处理这种场景pattern = "abba", str = "dog dog dog dog"
    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len; j++) {
            if (pattern[i] != pattern[j]) {
                if (!strcmp(strList[i], strList[j])) {
                    return false;
                }
            }
        }
    }
    return true;
}
```

