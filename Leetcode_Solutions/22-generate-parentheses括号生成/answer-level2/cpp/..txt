### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        int lc=0,rc=0;
        dfs(res,"",n,lc,rc);
        return res;
    }
    void dfs(vector<string>&res,string ss,int n,int lc,int rc)
    {
        if(lc>n||rc>n||rc>lc)return;
        if(lc==rc&&lc==n) 
        {
          res.push_back(ss);
          return ;
        }
        dfs(res,ss+'(',n,lc+1,rc);
        dfs(res,ss+')',n,lc,rc+1);
    }
};
```