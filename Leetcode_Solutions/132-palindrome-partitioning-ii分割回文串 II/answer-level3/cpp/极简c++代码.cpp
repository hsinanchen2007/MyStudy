动态规划，`dp[i]`表示前i个的最少分割次数，分两种情况：
1. 第i个字符不与前面的字符构成回文串，此时，`dp[i]`=`dp[i-1]+1`，即第i个字符独立是一个回文子串
2. 第i个字符与前面的字符构成回文串，此时，向前遍历，若从第j个字符到第i个字符是回文串，则`dp[i] = dp[j] + 1`，当然还要和原来的`dp[i]`比较大小。

注意：需要将`dp[0]`设置成 `-1`，因为若从第0个字符到第i个字符是回文串，则`dp[i]`应该等于0.
```c++
class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        vector<int> dp(len+1, 0);
        dp[0] = -1;
        for(int i=2; i<=len; i++){
            int min = dp[i-1] + 1;
            for(int j=i-1; j>0; j--){
                if(isHuiwen(s, j-1, i-1)){
                    min = min < dp[j-1]+1 ? min : dp[j-1] + 1; 
                }
            }
            dp[i] = min;
        }
        return dp[len];
    }
    bool isHuiwen(string &s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--])
                return false;
        }
        return true;
    }
};
```
