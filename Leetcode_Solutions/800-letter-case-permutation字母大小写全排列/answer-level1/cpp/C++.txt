### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string S) {
        dfs(S,0);
        return res;
    }
    void dfs(string S,int n){
        if(n == S.size()){
            res.push_back(S);
            return ;
        }
        dfs(S,n+1);
        if(S[n] > '9'){
            S[n] ^= 32;
            dfs(S,n+1);
        }
    }
};
```