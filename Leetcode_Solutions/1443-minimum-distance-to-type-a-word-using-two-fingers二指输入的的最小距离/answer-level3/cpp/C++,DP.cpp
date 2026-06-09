```
int dp[350][27][27];//dp[i][j][k]表示的是在第i个位置上，第一个手指的字符为j,第二个手指的字符为K
int n;
const int maxn=10086;
class Solution {
public:
    //先写一个代价函数，求出相应的代价的.
    int Cost(int a,int b){
        //if(a==26||b==26)return 0;
        return abs(a/6-b/6)+abs(a%6-b%6);
    }
    int minimumDistance(string word) {
        memset(dp,maxn,sizeof(dp));
        n=word.length();
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                dp[0][i][j]=0;//初始化将第0个位置不放元素这个是为了方便之后的操作。。。方便后面dp操作
            }
        }
        for(int i=1;i<=n;i++){
            int m=word[i-1]-'A';//我们都是从阿拉伯数字开始算起的
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if(dp[i-1][j][k]!=maxn){
                        dp[i][m][k]=min(dp[i-1][j][k]+Cost(j,m),dp[i][m][k]);
                        dp[i][j][m]=min(dp[i-1][j][k]+Cost(k,m),dp[i][j][m]);//为什么可能是本身.
                        //因为有可能两个单词字符相同。
                    }
                }
            }
        }
        int min_num=maxn;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(dp[n][i][j]!=maxn){
                    min_num=min(min_num,dp[n][i][j]);
                }
            }
        }
        return min_num;

    }
};
```
