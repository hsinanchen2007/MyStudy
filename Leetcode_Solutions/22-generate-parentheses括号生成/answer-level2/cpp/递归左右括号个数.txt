### 解题思路

递归左右括号个数

### 代码

```cpp
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int nn) {
        res.clear();
        string tmp;
        dfs(tmp,nn,nn);
        return res;
    }
    void dfs(string &s,int a,int b){
        if(b==0){res.push_back(s);return;}
        if(a!=0){
            s.push_back('(');
            dfs(s,a-1,b);
            s.pop_back();
        }
        if(b>a){
            s.push_back(')');
            dfs(s,a,b-1);
            s.pop_back();
        }
    }
};
```