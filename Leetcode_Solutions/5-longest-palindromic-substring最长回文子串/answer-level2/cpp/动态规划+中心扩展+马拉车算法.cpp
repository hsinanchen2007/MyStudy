```
class Solution {
public:
    string longestPalindrome(string &s) {
        int n=s.length(), begin=0, end=0;
        vector<vector<bool> > dp(n,vector<bool> (n,false));
        for(int j=0; j<n; ++j){
            for(int i=0; i<=j; ++i){
                if((j-i<=1 || dp[i+1][j-1]) && s[i]==s[j])
                    dp[i][j]=true;
                if(dp[i][j] && j-i>end-begin)
                    begin=i, end=j;
            }
        }
        return s.substr(begin,end-begin+1);
    }
};
```
```
class Solution {
public:
    string longestPalindrome(string &s) {
        int begin=0, end=0;
        for(int i=0; i<s.length(); ++i){
            int left=i, right=i;
            for(; right+1<s.length() && s[right]==s[right+1]; ++right);
            for(; left>0 && right+1<s.length() && s[left-1]==s[right+1]; --left, ++right);
            if(right-left>end-begin) begin=left, end=right;
        }
        return s.substr(begin,end-begin+1);
    }
};
```
```
class Solution {
public:
    string longestPalindrome(string &s) {
        string str(s.length()*2+2,'#');
        str[0]='$';
        for(int i=s.length(); i--; str[i*2+2]=s[i]);
        vector<int> lens(str.length(),0);
        int center=0, r=0;
        for(int i=1, mx=0, id=0; i<str.length(); ++i){
            lens[i]=mx>i?min(lens[id*2-i],mx-i):1;
            for(; str[i-lens[i]]==str[i+lens[i]]; ++lens[i]);
            if(mx<i+lens[i]){
                mx=i+lens[i];
                id=i;
            }
            if(r<lens[i]){
                r=lens[i];
                center=i;
            }
        }
        return s.substr((center-r)/2,r-1);
    }
};
```


