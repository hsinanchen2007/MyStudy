### 解题思路
动态转移方程：
dp[i] = (dp[j])dp[i - 1 -j]
dp[i]: i对括号的所有合法形式
(dp[j])dp[i - 1 -j]： 在dp[i-1]基础上加一对括号，相当于在dp[i-1]最左侧加一个左括号，然后在合理的位置选择一个右括号
dp[0] = 0;

### 代码

```cpp
class Solution {
public:
/*void dfs(vector<string>& vec, int n, int left, int right, string path){
    if(left > n || right > n || left < right)
        return;
    
    if(n == left && n == right){
        vec.push_back(path);
        return;
    }
        
    
    dfs(vec, n, left + 1, right, path + "(");
    dfs(vec, n, left, right + 1, path + ")");
}

vector<string> generateParenthesis(int n) {
    vector<string> vec;
    dfs(vec, n, 0, 0, "");
    return vec;
}*/

vector<string> generateParenthesis(int n){
    vector<vector<string> > dp;
    dp.push_back(vector<string>(1, ""));

    for(int i = 1; i <= n; i++){
        vector<string> vec;
        for(int j = 0; j < i; j++){
            for(int k1 = 0; k1 < dp[j].size(); k1++){
                for(int k2 =0;  k2 < dp[i - 1 - j].size(); k2++){
                    vec.push_back("(" + dp[j][k1] + ")" + dp[i - 1 -j][k2]);
                }
            }
        }

        dp.push_back(vec);
    }

    return dp[n];
}

};
```