### 解题思路
本题思路和双序列类似，可以用后往前遍历的思想，记住只遍历一半，也可以按照本题解利用递归的方式，只不过需要注意如参加引用，不然会越界。。。

### 代码

```cpp
class Solution {
public:
    int DPGetLongestLength(string& s, vector<vector<int>>& dp, int start, int end)
    {
        if (start == end) {
            dp[start][end] = 1;
        }
        else if(start == end - 1) {
            dp[start][end] = s[start]==s[end] ? 2 : 1;
        } else if (dp[start][end] == -1){
            if (s[start] == s[end]) {
                dp[start][end] = 2 + DPGetLongestLength(s, dp, start + 1, end - 1);
            } else {
                dp[start][end] = max(DPGetLongestLength(s, dp, start + 1, end), 
                                DPGetLongestLength(s, dp, start, end - 1));
            }
        }
        return dp[start][end];

    }
    int longestPalindromeSubseq(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return DPGetLongestLength(s, dp, 0, s.size() - 1);
    }
};
```