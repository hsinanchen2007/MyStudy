### 解题思路
此题我们要保证生成的括号字符串合法。
我们用`l`，`r`分别记录可以插入 `'('` 和 `')'` 的数量。
例如`n = 3`，那么一开始`r = 0`，`l = 3`。
当我们在递归函数中，选择插入 `'('` 时，`l`要 - 1，`r`要 + 1。
    因为你插入你一个'('势必要在接下来插入一个')'。
当我们在递归函数中，选择插入 `')'` 时，`r`只需- 1即可

### 代码

```cpp
class Solution {
public:
    void getAns(string str, int l, int r, vector<string>& ans){
        if(l == 0 && r == 0)
            ans.push_back(str);
        if(l > 0)
            getAns(str + "(", l - 1, r + 1, ans);
        if(r > 0) 
           getAns(str + ")", l, r - 1, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        getAns("", n, 0, ans);
        return ans;
    }
};
```