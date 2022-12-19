# 构造法生成括号
首先分析：需要构造有效的括号，**数量上，左右括号分别都为n个**。
其次：**左括号的数量需要大于等于右括号的数量**，

由两个前提可写出如下代码，从空串中逐步递归添加左右括号，
`1.如果右括号比左括号多，说明无效则返回`
`2.如果左括号数量超过N，则与题意不符，返回`
`3.如果左右括号都达到了指定数量，则可以将其添加到数组中保存`
`4.如果以上条件都没有满足，则尝试加入新的左括号和右括号`

```
vector<string> ans;int N;
void dfs(int l,int r,string has){
    if(r>l)return;
    if(l > N)return;
    if(l == r&& r == N){
        ans.push_back(has);return;
    }
    dfs(l+1,r,has + "(");
    dfs(l,r+1,has + ")");
}
vector<string> generateParenthesis(int n) {
    N=n;if(!N)return {};
    dfs(0,0,"");
    return ans;
}
```