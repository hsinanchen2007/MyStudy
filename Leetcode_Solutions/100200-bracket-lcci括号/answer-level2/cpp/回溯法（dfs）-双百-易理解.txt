### 解题思路
还是一样，要看做一棵解空间树
左边第一个一定是左括号（根节点），然后往下递归遍历时，记录左括号和右括号数，左括号可以直接加（前提是还能放右括号），
放右括号前提是左括号数大于当前右括号数且还能放右括号。
这里面之所以可以遍历完所有情况是因为在每一个选择时都做了分支（就是所谓的解空间树），叶结点就是所有的结果
### 代码

```cpp
class Solution {
public:
    //给我的理解，左边第一个一定是左括号，
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0) return ans;
        dfs(ans, "(", 1, 0, n);
        return ans;
    }
    //left_num为左括号数，right_num为右括号数
    void dfs(vector<string>& ans, string str, int left_num, int right_num, int n) {
        if(left_num + right_num == n*2) {
            ans.push_back(str);
            return;
        }
        //放括号
        if(left_num < n) dfs(ans, str + "(", left_num + 1, right_num, n);  //放左括号
        if(right_num < n && left_num > right_num) dfs(ans, str + ")", left_num, right_num + 1, n); //放右括号
    }
};
```