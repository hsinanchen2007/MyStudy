### 解题思路
极其简单

### 代码

```cpp
class Solution {
    void dfs(vector<vector<int>>& result, vector<int>& model, int loc,  int k);
    int n;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> model;
        this->n = n;
        dfs(result, model, 1, k);
        return result;
    }
};

void Solution::dfs(vector<vector<int>>& result, vector<int>& model, int loc, int k)
{
    model.push_back(loc);
    k--;
    loc++;
    if (k > 0 && loc <= n) {
        dfs(result, model, loc, k);
    }
    else if (k == 0) result.push_back(model);
    k++;
    model.pop_back();
    if(loc<=n)dfs(result, model, loc, k);
}

```