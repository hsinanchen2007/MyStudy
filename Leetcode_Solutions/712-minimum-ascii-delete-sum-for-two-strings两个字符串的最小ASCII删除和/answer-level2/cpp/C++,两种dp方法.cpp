### 解题思路
1.是官方题解的，dp中直接保存最小ASCII删除和
2.是直接保存不删除的最大ASCII和，这样就和之前的[最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)一样了 ，还有[583. 两个字符串的删除操作](https://leetcode-cn.com/problems/delete-operation-for-two-strings/):

### 方法1：

```cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1=s1.size();
        int len2=s2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1, 0));
        for (int i = 0; i < len1; ++i)
            dp[i+1][0] = dp[i][0]+s1[i];
        for (int j = 0; j < len2; ++j)
            dp[0][j+1] = dp[0][j]+s2[j];
        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                if(s1[i]==s2[j]){
                    dp[i+1][j+1]=dp[i][j];//当前位置的两个字符相同，它们不需要被删除
                }else{
                    dp[i+1][j+1]=min(dp[i+1][j]+s2[j], dp[i][j+1]+s1[i]);//如果 s1[i] != s2[j]，那么我们至少要删除 s1[i] 和 s2[j] 两个字符中的一个，例如选了i+1和j，要删除的就是s2[j];
                }
            }
        }
        return dp[len1][len2];
    }
};
```
### 方法2：
```
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1=s1.size();
        int len2=s2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1, 0));
        vector<vector<int>> cost(len1+1,vector<int>(len2+1, 0));
        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                if(s1[i]==s2[j]){
                    dp[i+1][j+1]=dp[i][j]+s1[i];
                }else{
                    dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        int sum=0;
        for (int i = 0; i < len1; ++i)
            sum += s1[i];
        for (int i = 0; i < len2; ++i)
            sum += s2[i];
        return sum - 2 * dp[len1][len2];
    }
};
```
