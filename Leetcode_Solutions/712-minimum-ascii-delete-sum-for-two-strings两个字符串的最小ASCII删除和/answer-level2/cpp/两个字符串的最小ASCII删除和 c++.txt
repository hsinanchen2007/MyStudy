![image.png](https://pic.leetcode-cn.com/c0c3d26c9ee00f821cc9d5849db5b30a1dffb6a548e80086eba58364b44e23f9-image.png)

### 解题思路
可以先做一下leetcode第1143题。
最小ASCII删除和  等价于求 最大ASCII和的公共序列。
思路就类似最长公共子序列。只是这里状态转移方程保存的是s2中以s[n]结尾的最大ASCII和的值
### 代码
```cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int total = 0, l1 = s1.length(), l2 = s2.length();
        for(char c : s1) total += c;
        for(char c : s2) total += c;
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for(int i = 1; i <= l1; ++i){
            for(int j = 1; j <= l2; ++j){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + s2[j - 1];
                }else{
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return total - 2 * dp[l1][l2];
    }
};
```



```cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int total = 0, l1 = s1.length(), l2 = s2.length();
        for(char c : s1) total += c;
        for(char c : s2) total += c;
        vector<int> dp(l2 + 1);
        for(int i = 1; i <= l1; ++i){
            int last = dp[0];
            for(int j = 1; j <= l2; ++j){
                int t = dp[j];
                if(s1[i - 1] == s2[j - 1]){
                    dp[j] = last + s2[j - 1];
                }else{
                    dp[j] = std::max(dp[j], dp[j - 1]);
                }
                last = t;
            }
        }
        return total - 2 * dp[l2];
    }
};
```