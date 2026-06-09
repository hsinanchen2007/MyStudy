递归C++
```cpp
class Solution {
private:
    vector<string> res;
public:
    void DFS(int l, int r, string s){   //l剩余左括号，r剩余右括号，l<=r
        if (r == 0){                    //l和r等于0 保存答案返回
            res.push_back(s);
            return;
        }
        if (l < r)                      
            DFS(l, r - 1, s + ")");
        if (l > 0)
            DFS(l - 1, r, s + "(");
    }
    vector<string> generateParenthesis(int n) {
        DFS(n, n, "");
        return res;
    }
};
```
