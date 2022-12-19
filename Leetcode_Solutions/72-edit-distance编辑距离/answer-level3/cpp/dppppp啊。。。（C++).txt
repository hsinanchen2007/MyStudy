菜鸡的第一个正经题解，紧张兮兮^.^

状态定义： 
- `dp[i][j]` 表示 `word1[0:i+1]` 与 `word2[0:j+1]` 的最短编辑距离 ( 左闭右开区间：`[0, i+1)` 与 `[0, j+1)` )
- 注：这里的`dp`数组未开额外的 **1** 个空间，故`word1`和`word2`为空时提前返回
    - `word1`为空，表示`word1`需要执行`len2`次插入操作，即直接返回`len2`
    - `word2`为空，表示`word1`需要执行`len1`次删除操作，即直接返回`len1`

转移方程：
- `word1[i] == word2[j] : dp[i][j] = dp[i-1][j-1]` 
    - `i, j` 匹配，不需要多余操作
- `word1[i] != word2[j] : dp[i][j] = min(dp[i][j-1] + 1, dp[i-1][j] + 1, dp[i-1][j-1] + 1) `
    - `dp[i][j-1] + 1`   : 插入一个字符，使得 `word1[i+1] == word2[j]` (这里的 `i + 1` 为新插入字符)，然后跳过 `i + 1, j`去判断 `i` 和 `j - 1`
    - `dp[i-1][j] + 1`   : 删除一个字符，需要继续判断 `word1[i-1]` 与 `word2[j]` 的关系
    - `dp[i-1][j-1] + 1` : 替换一个字符，直接判断之前的位置

初始化 : 
- `word1[i] == word2[j] ? dp[0][0] = 0 : 1`
- `word1[0] == word2[j] ? dp[0][j] = min(j, dp[0][j-1] + 1) : dp[0][j] = dp[0][j-1] + 1`  
    - `dp[0][j] = j` 表示只删除
    - `dp[0][j] = dp[0][j-1] + 1` 是从状态方程中的min式中选择的合法项(即插入)
- `word1[i] == word2[0] ? dp[i][0] = min(i, dp[i-1][0] + 1)  : dp[i][0] = dp[i-1][0] + 1`
    - `dp[i][0] = i` 表示只插入
    - `dp[i][0] = dp[i-1][0] + 1` 同上(即删除)

结果 : 
- `dp[len1-1][len2-1]`

复杂度分析：
- 时间复杂度：`O(m) + O(n) + O(m * n)`
    - `O(m), O(n)` 分别用于初始化dp数组
- 空间复杂度：`O(m * n)` 用于 `dp` 数组

```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        if (!len1)
            return len2;
        if (!len2)
            return len1;

        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        if (word1[0] != word2[0])
            dp[0][0] = 1;

        for (int j = 1; j < len2; ++j) {
            if (word1[0] == word2[j])
                dp[0][j] = min(j, dp[0][j - 1] + 1);
            else 
                dp[0][j] = dp[0][j - 1] + 1;
        }
            
        for (int i = 1; i < len1; ++i) {
            if (word1[i] == word2[0])
                dp[i][0] = min(i, dp[i - 1][0] + 1);
            else 
                dp[i][0] = dp[i - 1][0] + 1;
        }
        
        for (int i = 1; i < len1; ++i) {
            for (int j = 1; j < len2; ++j) {
                if (word1[i] == word2[j]) 
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
            }
        }

        return dp[len1 - 1][len2 - 1];
    }
};
```