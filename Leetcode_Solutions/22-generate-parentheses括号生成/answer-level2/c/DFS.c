### 解题思路
深搜

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>t;
        int l = 0,r=0;
        dfs(t,s,l,r,n);
        return t;
    }
    void dfs(vector<string> &t,string s, int l, int r, int &n) {
        if (l < r) return;
        if (l == n && r == n) {
            t.push_back(s);
            return;
        }
        if (l<n) {
            dfs(t,s+'(', l + 1, r, n);
        }
        if(r<n&&l>r){
            dfs(t, s + ')', l , r+1, n);
        }
    }

};
```