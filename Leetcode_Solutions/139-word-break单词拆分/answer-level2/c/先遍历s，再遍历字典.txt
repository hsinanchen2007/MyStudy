### 解题思路
此处撰写解题思路

### 代码

```c
bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int i,len=strlen(s),j,k;
    int dp[len+1];
    memset(dp,0,len+1);
    dp[0]=1;
    for(i=1;i<=len;i++){
        for(j=0;j<wordDictSize;j++){
            k=i-strlen(wordDict[j]);
            if(k<0) continue;
            dp[i]=dp[k]&&!strncmp(s+k,wordDict[j],strlen(wordDict[j]));
            if(dp[i]==1) break;
        }
        //printf("%d %d\n",i,dp[i]);
    }
    return dp[len];
}
```