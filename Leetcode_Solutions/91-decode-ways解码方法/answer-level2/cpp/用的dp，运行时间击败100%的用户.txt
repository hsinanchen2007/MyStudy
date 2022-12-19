### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int dp[n]={0,};
        if(s[0]>'0') {
            dp[0]=1;
        }
        for(int i=1;i<n;i++) {
            string temp={s[i-1],s[i]};
            if(getBool(temp)) {
                if(i-2>=0) {
                    dp[i]+=dp[i-2];
                }else {
                    dp[i]++;
                }
            }
            if(s[i]>'0') {
                dp[i]+=dp[i-1];
            }
        }
        return dp[n-1];
    }

    bool getBool(string s) {
        if(s[0]=='0') {
            return false;
        }
        if(s[0]>'2') {
            return false;
        }else if(s[0]<'2') {
            return true;
        }else if(s[1]<='6') {
            return true;
        }
        return false;
    }
};
```