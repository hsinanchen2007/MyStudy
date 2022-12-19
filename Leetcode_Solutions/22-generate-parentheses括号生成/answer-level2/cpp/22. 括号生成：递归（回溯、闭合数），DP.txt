### 解题思路
>1. 回溯
* 标记剩余左右括号数量
* 字符串从一个左括号(开始，在保证有效性的情况下，可以加左括号或者右括号，则对应剩余数量减1
* 直到左括号数为0，右括号数剩1，则补上)然后加入ans数组中

>2. 闭合数
* 有效括号字符串可以由有效括号子串组成——有点像动态规划中的状态转移
* 一个n个括号对的有效串，可以分解成`'(' + left + ')' + right`
* 其中`left`与`right`是有效子串，且`left.length() + right.length() == n-1`

### 代码

```cpp
class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)  return vector<string>();
        recursive("", n, n);
        return ans;
    }
    void recursive(string parenthesis, int leftn, int rightn) {
        if(leftn == 0 && rightn == 0) {
            ans.push_back(parenthesis);
            return;
        }
        if(leftn > 0)   
            recursive(parenthesis + '(', leftn-1, rightn);
        if(rightn > 0 && leftn < rightn)  
            recursive(parenthesis + ')', leftn, rightn-1);
    }

    // 闭合数
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0)  
            ans.push_back("");
        else {
            for(int i = 0; i < n; ++i) {
                for(string right: generateParenthesis(i)) {
                    for(string left: generateParenthesis(n-i-1)) {
                        ans.push_back('(' + left + ')' + right);
                    }
                }
            }
        }
        return ans;
    }
*/
    // 记录子状态
    vector<string> generateParenthesis(int n) {
        if(n == 0)  return vector<string>();

        vector<string> tmp;
        vector<vector<string>> dp(n+1, tmp);
        dp[0].push_back("");
        dp[1].push_back("()");
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                for(string left: dp[j]) {
                    for(string right: dp[i-j-1]) {
                        dp[i].push_back('('+left+')'+right);
                    }
                }
            }
        }
        return dp[n];
    }
};
```