```
int countSubstrings(char * s){
    int num=0;
    bool dp[2][1001]={false};
    int len=strlen(s);

    for(int i=0; i<len; i++) {
        dp[1][i]=1;
        num += dp[1][i];
    }
    for(int i=1; i<len; i++){
        dp[0][i] = s[i-1]==s[i]? 1:0;
        num += dp[0][i];
    }
    for(int L=3; L<=len; L++){
        for(int i=0; i+L-1<len; i++){
            int j=i+L-1;
            dp[L%2][L/2+i] = s[i]==s[j]? dp[L%2][L/2+i]:0;
            num += dp[L%2][L/2+i];
        }
    }
    return num;
}
```
