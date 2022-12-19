
和2020.4.8的每日一题一样，看到要输出所有情况了，那么自然而然想到递归遍历的思路。然而这道题肯定还有很多更简单的方法，例如动态规划，但我实力不够
找不到状态转移方程式，而且比较难想，所以还是选择利用了DFS.

解题不是关键，关键在于怎么想到解题的思路的.
既然想到了利用了递归，那么首先还是老样子，需要想递归的return条件，就是我什么时候返回到上一层，因此这里要有if.
根据题目条件，我们能够找到一个对应关系，就是**左括号数量永远等于又括号数量，并且等于n**，此时就可以构成一组解,利用vector.push_back().
然而这只是回答条件，一般还要有个最基础的条件判断，这个基础的条件判断对应的一般是**我什么时候不能再递归下去了**，所以此时也就是左括号数量或右括号数量大于n.
此时我们的基础条件判断也完成了.
```
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {   
        dfs(0, 0, "", n);
        return ans;
    }
    void dfs(int leftBracket, int rightBracket, string arr, int n) {
        if (leftBracket > n || rightBracket > n)
            return;
        if (leftBracket == n && rightBracket == n)
            ans.push_back(arr);
        if (leftBracket >= rightBracket) {
            dfs(leftBracket + 1, rightBracket, arr + "(", n); // Traverse all "(" situation
            dfs(leftBracket, rightBracket + 1, arr + ")", n); // Traverse all ")" situation
        }
    }
};
```
最后，也就是写最关键的dfs()了，我的dfs()括号里面要写什么，才能使递归按我的预计进行下去，那当然是**判断条件中的改变量和需要解题传入的东西了**.
因此  dfs(leftBracket + 1, rightBracket, arr + "(", n);  这条语句对应的就是我压入所有左括号的情况.
dfs(leftBracket, rightBracket + 1, arr + ")", n);  这条语句对应我压入所有右括号的情况.
我们每进行一次改变了左括号和右括号的数量，也就对应的要+1.

**注意：因为是先压入左括号再压入右括号，所以dfs()这两条顺序不能颠倒.**


