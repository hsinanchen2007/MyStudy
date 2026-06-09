### 解题思路
dp[i][j]存放的是[i,,,,j]是否是回文区间
dp[i][j]=dp[i+1][j-1]&&(s[i]==s[j])去除两端之间的子串是回文子串，且两端相等
### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        int l=0;  //l用来记录当前最长的回文子串
        if (s.size()==0) return res;
        if(s.size()==1)return s;
        res=s[0];//返回子串初始化为第一个元素
        vector<vector<bool>> dp(n, vector<bool>(n));
          for (int j = 0; j<n; j++) {
            for (int i=j;i>=0;i--){
                if((s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1])){
                    dp[i][j]=true;
                    if(j-i>l){
                        res=s.substr(i,j-i+1);
                        l=j-i;
                    }
                }
            }
        }
        return res;
    }
};
```