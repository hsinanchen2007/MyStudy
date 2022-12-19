### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
vector<string> res;
// 深搜（也就是递归方法）
// 递归2n-1层，每层干两件事: 加'(' 或 ')'
// 1、用一个stack记录'('出现的次数，stk不为空时可以加入')'
// 2、每加一个'('，题目所给的n就需要-1，stk+1。
// 把栈简化，我们只需要记录'('出现次数即可。
void dfs(int depth, int n, string s, int stk){
    /**
    depth: 我们需要的字符串的长度  == 2 * n
    n: 剩余可加的'('个数
    s: 当前字符串状态
    stk: 记录单个'('出现次数，如果添加')'，stk-1
    **/
    if(s.length() == depth){  // 回溯条件
        res.push_back(s);
        return;
    }
    if(n>0) dfs(depth, n-1, s+'(', stk+1); // 加'('
    if(stk>0) dfs(depth, n, s+')', stk-1); // 加')'
}
    vector<string> generateParenthesis(int n) {
        string s = "(";
        dfs(n*2, n-1, s, 1);  // 注意此处n需要-1，因为初始string = "("
        return res;
    }
};
```