**中心扩散**
```
class Solution {
public:
    //中心扩散法
    int n;
    int append_from_center(string s,int l,int r){
        int res=0;
        while(l>=0&&r<n&&s[l]==s[r]){
            res+=2;l--;r++;
        }
        return res;
    }
    string longestPalindrome(string s) {
        n=s.size();
        int start,len=0;
        if(!n)return "";
        for(int i=0;i<n;i++){
            int len1=append_from_center(s,i,i),len2=append_from_center(s,i,i+1);
            int new_len=max(len1-1,len2);
            if(new_len>len){
                len=new_len;
                start=i-(len+1)/2+1;
            }
        }
        return s.substr(start,len);
    }
};
```

**动态规划**

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(!n)return "";
        int start=0,len=1;
        int dp[n][n];memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)dp[i][i]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=n-i;j++){
                if((j+1>j+i-2||dp[j+1][j+i-2])&&s[j]==s[j+i-1]){
                    dp[j][j+i-1]=1;
                    start=j,len=i;
                }
            }
        }
        return s.substr(start,len);
    }
};
```