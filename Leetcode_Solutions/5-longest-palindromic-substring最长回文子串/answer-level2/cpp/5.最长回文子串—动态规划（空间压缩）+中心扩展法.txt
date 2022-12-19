方法一、动态规划
```
class Solution {
public:
    string longestPalindrome(string s) {
        int ssize=s.size();
        if(ssize==0||ssize==1) return s;
        int maxlen=0,st=0;
        int dp[ssize][ssize];
        for(int j=0;j<ssize;j++){
            for(int i=0;i<=j;i++){
                dp[i][j]=(j-i<=2||dp[i+1][j-1]) && s[i]==s[j]; //长度为1，2的情况单独考虑
                if(dp[i][j]&&(j-i+1)>maxlen){
                    st=i;
                    maxlen=j-i+1;
                }
            }
        }
        return s.substr(st,maxlen);
    }
};
```
空间压缩
```
class Solution {
public:
    string longestPalindrome(string s) {
        int ssize=s.size();
        if(ssize==0||ssize==1) return s;
        int maxlen=0,st=0;
        int dp[ssize];
        for(int j=0;j<ssize;j++){
            for(int i=0;i<=j;i++){
                dp[i]=(j-i<=2||dp[i+1]) && s[i]==s[j];
                if(dp[i]&&(j-i+1)>maxlen){
                    st=i;
                    maxlen=j-i+1;
                }
            }
        }
        //for(int i=start;i<=end;i++) result +=s[i];
        return s.substr(st,maxlen);
    }
};
```
方法二、中心扩展法
```
class Solution {
public:   
    string longestPalindrome(string s) {
        int sSize = s.size();
        if (sSize==0||sSize==1) return s;
        string result;
        int start = 0, end = 0, maxLen = 0;
        int len1,len2;
        for(int i=0;i<sSize;i++){
            len1=expandaroundcenter(s,i,i);
            len2=expandaroundcenter(s,i,i+1);
            maxLen=max(max(len1,len2),maxLen);
            if(maxLen>end-start+1){
                start=i-(maxLen-1)/2;
                end=i+maxLen/2;
            }
        }
        //for(int i=start;i<=end;i++) result +=s[i];
        result = s.substr(start, maxLen);
        return result;
    }
private:
    int expandaroundcenter(string s,int left,int right){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
};
```

