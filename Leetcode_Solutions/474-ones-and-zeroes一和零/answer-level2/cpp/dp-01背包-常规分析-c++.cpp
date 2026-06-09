### 解题思路
其实就是0-1背包问题，可以先把每个字符串的01统计下来，然后去填满m个0和n个1.

状态：0的个数，1的个数，字符串

选择：是否选择当前字符串

dp数组含义：dp\[k]\[i][j]表示前k个字符串中，能被i个0，j个1所表示的最大数量

方程：$dp[k][i][j] = max(dp[k - 1][i][j], dp[k - 1][i - nums[k - 1].num_0][j - nums[k - 1].num_1] + 1)$（选与不选）

base case：$dp[k][0][0] = 0, dp[0][i][j] = 0$

### 代码

```cpp
class Solution {
public:
    struct Node{
        int num_0;
        int num_1;
    };
    void helper(string& str, Node& node){
        node.num_0 = 0;
        node.num_1 = 0;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '0') node.num_0++;
            else node.num_1++;
        }
    }
    //先统计各个字符串01个数
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<Node> nums(size);
        for(int i = 0; i < size; i++) {
            helper(strs[i], nums[i]);
        }
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        //base case
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                dp[0][i][j] = 0;
            }
        }
        for(int i = 1; i <= size; i++){
            dp[i][0][0] = 0;
        }
        //方程
        for(int k = 1; k <= size; k++) {
            for(int i = 0; i <= m; i++) {
                for(int j = 0; j <= n; j++) {
                    if(i - nums[k - 1].num_0 >= 0 && j - nums[k - 1].num_1 >= 0) dp[k][i][j] = max(dp[k - 1][i][j], dp[k - 1][i - nums[k - 1].num_0][j - nums[k - 1].num_1] + 1);
                    else dp[k][i][j] = dp[k - 1][i][j];
                }
            }
        }
        return dp[size][m][n];
    }
};
```