### 解题思路：回溯
 - 回溯过程中统计左右括号的个数以及所组合成的括号的情况（中间变量以及结果变量）
 - 递归结束的条件：
右括号的个数大于左括号的个数
左括号或者右括号的个数大于n
左括号和右括号的个数等于n,这种情况顺便保存到结果中
 - 递归过程：要么加上个左括号，要么加上个右括号


### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n < 1)
            return vector<string>();       
        vector<string> res;
        unordered_set<string> temp;//直接用vector保存结果也OK
        dfs(temp, "", 0, 0, n);
        for(auto t : temp)
            res.push_back(t);
        return res;
    }
private:
    void dfs(unordered_set<string>& res, string temp, int l, int r, int n){
        if(r > l || r > n || l > n)
           return;
        if(r + l == 2 * n){
                res.insert(temp);
            return;
        }
        dfs(res, temp + '(', l + 1, r, n);
        dfs(res, temp + ')', l, r + 1, n);
    }
    
};
```
### 解题思路：回溯
 - n个括号的生成结果基于0……n - 1个括号的生成结果
 - res[n][i] = "(" + res[p][j] + ")" + res[q][k] (p + q = n - 1)


### 代码
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //动态规划：基于之前的结果处理
        vector<vector<string>> res(n + 1);
        res[0] = {""};
        res[1] = {"()"};
        for(int i = 2; i <= n; ++i){
            for(int p = 0; p < i; ++p){
                for(auto s : res[p]){
                    int q = i - p - 1;
                    for(auto t : res[q]){
                        res[i].push_back("(" + s + ")" + t);
                    }
                }
            }
        }
        return res[n];
    }
};
```