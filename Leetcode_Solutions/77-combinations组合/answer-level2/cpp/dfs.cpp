### 解题思路
dfs

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(int s,int n,int k){
        if(k==0){
            res.push_back(temp);
            return;
        }
        if(s>n||k<0)
            return;
        temp.push_back(s);
        dfs(s+1,n,k-1);
        temp.pop_back();
        dfs(s+1,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        if(k==0)
            return res;
        dfs(1,n,k);
        return res;
    }
};
```