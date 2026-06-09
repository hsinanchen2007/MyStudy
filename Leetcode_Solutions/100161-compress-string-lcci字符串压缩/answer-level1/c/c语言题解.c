申请一个buffer,如果当前的字符串和下一个字符串不相等则保存字符和count,注意sprintf的使用
char* compressString(char* S){
    if(S == NULL)
        return "";
    
    int len = strlen(S);
    if(len <= 0)
        return "";
    
    char *p = S;
    int count = 1;
    int j = 0;
    char *pressStr = calloc(len*2 + 1, sizeof(char));
    pressStr[j++] = S[0];

    for(int i = 0;i < len;i++) {
        if(i == len - 1) {
            int n = sprintf(&pressStr[j], "%d", count);
            break;
        } else if(S[i] != S[i + 1]) {
            int n = sprintf(&pressStr[j], "%d", count);
            j += n;
            pressStr[j] = S[i + 1];
            j++; 
            count = 1;
        } else {
            count++;
        }
        
    }

    int lenPress = strlen(pressStr);
    if(lenPress >= len)
        return S;
    return pressStr;
}