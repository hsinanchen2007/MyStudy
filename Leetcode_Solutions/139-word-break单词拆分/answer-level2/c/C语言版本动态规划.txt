- 状态定义：dp[i] == true 为前i个字符组成的单词在字典中
- 状态转移：使dp[j] == true (j>i)成立的条件是dp[i]为true 且s[i+1,j]在字典中，否则dp[j]为false
- 初始值： dp[0] == true, 即空字符串在字典中


```
bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int len = strlen(s);
    if(len == 0 || wordDictSize == 0) return false;
    bool dp[len+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for(int i=0;i<len;i++)
        for(int j=i+1;j<=len;j++){
            char tempS[j-i+1];
            strncpy(tempS, s+i, j-i);
            tempS[j-i] = '\0';
            for(int k=0;k<wordDictSize;k++){
                if(strcmp(tempS, wordDict[k])==0 && dp[i]){
                    dp[j] = true;
                    break;
                }
            }
        }
    return dp[len];
}

```
