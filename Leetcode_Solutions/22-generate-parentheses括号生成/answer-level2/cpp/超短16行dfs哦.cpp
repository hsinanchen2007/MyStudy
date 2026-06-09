### 解题思路
超短的dfs哦
### 代码

```cpp
class Solution {
public:
    vector<string>ans;
    vector<string> generateParenthesis(int n) {
        dfs(0,0,"",n);
        return ans;
    }
    void dfs(int t, int v, string s, int n){
        if(t==n&&v==0)
            ans.push_back(s);
        if(v!=0)
            dfs(t,v-1,s+')',n);
        if(t<n)
            dfs(t+1,v+1,s+'(',n);
    }
};
```