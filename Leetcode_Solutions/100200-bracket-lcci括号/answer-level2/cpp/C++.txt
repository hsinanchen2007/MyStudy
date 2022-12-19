只有在我们知道序列仍然保持有效时才添加 ‘(‘ or ‘)’。我们可以通过跟踪到目前为止放置的左括号和右括号的数目来做到这一点。

如果我们还剩一个位置，我们可以开始放一个左括号。 如果它不超过左括号的数量，我们可以放一个右括号。
```c++ []
class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        backtrack("",0,0,n);
        return res;
    }
    void backtrack(string temp,int left,int right,int n)
    {
        if(temp.length()==n*2)
        {
            res.push_back(temp);
            return ;
        }
        if(left<n)
            backtrack(temp+'(',left+1,right,n);
        if(right<left)
            backtrack(temp+')',left,right+1,n);
    }
};
```
