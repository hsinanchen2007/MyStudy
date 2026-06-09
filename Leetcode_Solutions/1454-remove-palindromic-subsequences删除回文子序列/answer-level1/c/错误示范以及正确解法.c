没仔细审题...错误的使用DP
```
int isCircle(int i,int j,char * a){
    while(i<j){
        if(a[i++]!=a[j--]) return 0;
    }
    return 1;
}
int removePalindromeSub(char * s){
    int i,j;
    int lenth=strlen(s);
    int dp[1001][1001];
    for(i=0;i<lenth;i++){
        for(j=0;j+i<lenth;j++){
            if(i==0) dp[j][i+j]=1;
            else{
                if(isCircle(j,i+j,s)) dp[j][i+j]=1;
                else{
                    int min=2000,k;
                    for(k=j;k<i+j;k++)
                        if(min>dp[j][k]+dp[k+1][i+j]) min=dp[j][k]+dp[k+1][i+j];
                    dp[j][i+j]=min;
                }
            }
        }
    }
    return dp[0][lenth-1];
}
```
**「子序列」定义：如果一个字符串可以通过删除原字符串某些字符而不改变原字符顺序得到，那么这个字符串就是原字符串的一个子序列。**

- 所以在所有情况下，总可以先删所有a组成的字串，再删去剩下全为b的字串，最小删除次数不超过2.
- 若整个字符串构成回文，则最小删除次数为1.
- 字符串为空，则最小删除次数为0.

以下为正确代码：
```
int removePalindromeSub(char * s){
    int lenth=strlen(s);
    int i=0,j=lenth-1;
    if(!lenth) return 0;
    while(i<j) if(s[i++]!=s[j--]) return 2;
    return 1;
}
```
![截屏2020-01-26下午12.20.58.png](https://pic.leetcode-cn.com/9039080c881fc781aa228c0dfdc08bbacfded027566e15a1ec548777c03ed3d5-%E6%88%AA%E5%B1%8F2020-01-26%E4%B8%8B%E5%8D%8812.20.58.png)
