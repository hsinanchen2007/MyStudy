```
char ** findOcurrences(char * text, char * first, char * second, int* returnSize){
    int len = strlen(text);
    char tmp[len+1];
    memcpy(tmp, text, len+1);
    char** ret = (char**)malloc(1000*sizeof(char*));
    int head = -1;

    char* pChar = strtok(tmp, " ");
    while(true) {
        
        if(!pChar) break;
        int flag1 = strcmp(first, pChar);

        pChar = strtok(NULL, " ");
        if(!pChar) break;
        int flag2 = strcmp(second, pChar);

        if(!flag1 && !flag2) {
            pChar = strtok(NULL, " ");
            if(!pChar) break;
            ret[++head] = (char*)calloc(20, sizeof(char));
            memcpy(ret[head], pChar, strlen(pChar));
        }
    }
    *returnSize = head+1;
    return ret;
}
```
