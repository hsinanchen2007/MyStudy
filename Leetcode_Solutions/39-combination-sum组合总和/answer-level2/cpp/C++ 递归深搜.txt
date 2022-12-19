### 解题思路
递归深搜

### 代码

```cpp
class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    int siz;

    void dfs(int now, int sum, int tar, vector<int>& num)
    {
        if(sum > tar) return;
        if(sum == tar)
        {
            ans.push_back(tmp);
            return;
        }
        for(int i = now; i < siz; i ++)
        {
            tmp.push_back(num[i]);
            dfs(i, sum + num[i], tar, num);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        siz = candidates.size();
        dfs(0, 0, target, candidates);
        return ans;
    }
};
```