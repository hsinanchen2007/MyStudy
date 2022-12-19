应掌握四种方法：暴力解法<动态分布<中心扩散<马拉车四种方法

以下为动态分布方法，申请一个二维数组dp，用dp[i][j]表示s[i]到s[j]是否为一个回文子串,
动态分布的dp数组编程时要注意要么初始化都是0，要么在编程中把不是回文子串的添作0，不然可能出bug*/

```
char * longestPalindrome(char * s){
    int n = strlen(s);
    if(n<=1){
        return s;
    }
    int dp[n][n];
    int star=0,len=1;//分别表示答案子串在s中开始下标和答案子串长度
    for(int i=0;i<n-1;i++){
        dp[i][i] = 1;
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            star = i;
            len = 2;
        }else{
            dp[i][i+1] = 0;
        }
    }dp[n-1][n-1] = 1; //初始化长度为1和2的子串的dp
    for(int i=2;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(dp[j+1][j+i-1]==1 && s[j]==s[j+i]){
                dp[j][j+i] = 1;
                star = j;
                len = i+1;
            }else{
                dp[j][j+i] = 0;
            }
        }
    }
    char* result = (char*)malloc(sizeof(char)*(len+1));
    for(int i=0;i<len;i++){
        result[i] = s[star++];
    }
    result[len] = '\0';//字符串最后一个得是0
    return result;
}
```
以下为中心扩散方法
```
char * longestPalindrome(char * s){
    int n = strlen(s);
    if(n<=1){
        return s;
    }
    int len=1,center=0;
    for(int i=0;i<n;i++){
        for(int j=1;i-j>=0 && i+j<n;j++){
            if(s[i-j] != s[i+j]){
                break;
            }else if(1+2*j>len){
                center = i;
                len = 1+2*j;
            }       
        }//以s[i]自身为中心往外扩散，s[i-j]←---s[i]---→s[i+j]
        for(int j=0;i-j>=0 && i+j+1<n;j++){
            if(s[i-j] != s[i+j+1]){
                break;
            }else if(2+2*j>len){
                center = i;
                len = 2+2*j;
            }
        }//以s[i]为中心第一个左边扩散，←---s[i]中心s[i+1]---→
    }
    char* result = (char*)malloc(sizeof(char)*(len+1));
    if(len%2 == 0){
        for(int i=0;i<len;i++){
            result[i] = s[center-len/2+1+i];
        }
    }else{
        for(int i=0;i<len;i++){
            result[i] = s[center-len/2+i];
        }
    }
    result[len] = '\0';
    return result;
}
```
马拉车太难了...kmp还没好好写过一次，先把马拉车放一放吧.....