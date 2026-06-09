### 解题思路
感谢大神[@yuyu-13](/u/yuyu-13/)的思路，这思路真是好极了。

定义dp：dp[i]是到i长度为止的所有有效字符串的列举。所以dp[i]是一个数组。
里面的情况：
0: {""}
1: {"()"}

2: 拼凑出"(" + p + ")" + q的组合，p和q分别取dp[0]和dp[1]里的元素组合，也就是""和"()"、"()"和""。
   所以是{"()()", "(())"}

3: 拼凑出"(" + p + ")" + q的组合，p和q分别取dp[0]和dp[2]中的元素组合、dp[1]和dp[1]中的元素组合、dp[2]和dp[20]的元素组合。即：
dp[0]和dp[2]中的元素组合:
   ( + "" + ) + ()()
   ( + "" + ) + (())
dp[1]和dp[1]中的元素组合:
   ( + () + ) + ()
dp[2]和dp[20]的元素组合:
   ( + ()() + ) + ""
   ( + (()) + ) + ""

以此类推


### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }
        if (n == 1) {
            return {"()"};
        }

        vector<vector<string>> dp(n+1);
        dp[0].push_back("");
        dp[1].push_back("()");

        for(int i = 2; i < n + 1; ++ i) {
            for (int j = 0; j < i; ++ j) {
                for (int p = 0; p < dp[j].size(); ++ p) {
                    for (int q = 0; q < dp[i - j - 1].size(); ++ q) {
                        dp[i].push_back("(" + dp[j][p] + ")" + dp[i-j-1][q]);
                    }
                }
            }
        }
        return dp[n];
    }
};
```

![微信图片_20200112143537.png](https://pic.leetcode-cn.com/c3c15aed4f67bf9c12bba7899872d3decc7aa4b116b0f1d7562f57ad605cfa27-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200112143537.png)
