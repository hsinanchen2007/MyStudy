### 解题思路
dp[i]保存n=i时的所有可能
- 将i分解成j、k两部分，对dp[j]、dp[k]的内容进行拼接即可得到dp[i]的内容
- 拼接方式为 str[j] + str[k] 及str[k] + str[j]
- 当j==1时允许包围拼接："(" + str[k] + ")"

![image.png](https://pic.leetcode-cn.com/f33b4d202ca86d50ed1e83fddb712ebbd2af295b09b5b8f18edd43170274191d-image.png)

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> dp;
    unordered_set<string> us;
    void combination(int p1, int p2)
    {
        for(int i = 0; i < dp[p1].size(); i ++ )
        {
            for(int j = 0; j < dp[p2].size(); j ++)
            {
                us.insert(dp[p1][i]+dp[p2][j]);
                us.insert(dp[p2][j]+dp[p1][i]);
                if(p1==1) us.insert("("+dp[p2][j]+")");
            }
        }
    }
    vector<string> generateParenthesis(int n) {   
        dp.push_back({""});
        dp.push_back({"()"});
        dp.push_back({"()()","(())"});
        for(int i = 3; i <= n; i++)
        {
            vector<string> tmp;
            for(int j = 1; j <= i/2; j++ )
                combination(j, i-j);
            for(auto it = us.begin(); it != us.end(); it++) tmp.push_back(*it);
            us.clear();
            dp.push_back(tmp);
        } 
        return dp[n];
    }
};
```