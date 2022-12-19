### 解题思路

求排列

### 代码

```cpp
class Solution {
public:
    vector<string> ans;
    string path;
    string s;
    int n;
    vector<bool> st;
    vector<string> permutation(string _s) {
        s = _s;
        n = s.size();
        st = vector<bool>(n);
        sort(s.begin(), s.end());
        dfs(0);
        return ans;
    }

    void dfs(int i){
        if (i == n) {
            ans.push_back(path);
            return ;
        }
        for (int j = 0; j < n; j++){
            if (j > 0 && s[j-1] == s[j] && !st[j-1]) continue;
            if (!st[j]) {
                st[j] = true;
                path.push_back(s[j]);
                dfs(i+1);
                path.pop_back();
                st[j] = false;
            }
        }
    }
};
```