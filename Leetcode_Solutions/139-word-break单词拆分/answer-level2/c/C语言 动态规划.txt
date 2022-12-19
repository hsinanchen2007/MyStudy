```
bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    
    int len = strlen(s);
    bool* dp = (bool*)malloc(sizeof(bool)*(len+1));
    for(int i = 0;i <= len;i++) {
        dp[i] = false;
    }
    dp[0] = true;
    
    for(int i = 1;i <= len;i++) {
        //int flag = 0; //减少循环的
        for(int j = 0;j < i;j++) {
            char temp[len + 1];
            temp[i-j] = '\0'; //结尾符，必须加
            strncpy(temp,s+j,i-j); //strncpy()用来复制字符串的前n个字符，其原型为： char * strncpy(char *dest, const char *src, size_t n); 【参数说明】dest 为目标字符串指针，src 为源字符串指针。
            for(int k = 0;k < wordDictSize;k++) {
                if(dp[j] && (strcmp(temp,wordDict[k]) == 0)) {
                    dp[i] = true;
                    //flag = 1;
                    break;
                }
            }
            
        }
        
    }
    bool res = dp[len];
    free(dp);
    return res;
}
```
