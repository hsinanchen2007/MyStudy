### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void dfs(vector<int>& src, int target, vector<vector<int>>& res, vector<int>& tmp, int sum,int index)
    {
        if(sum > target) return;
        if(sum == target) {
            res.push_back(tmp);
            return;
        }

        for(int i=index;i<src.size();i++) {
            sum+=src[i];
            tmp.push_back(src[i]);
            dfs(src,target,res,tmp,sum,i);
            tmp.pop_back();
            sum-=src[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(candidates, target, res, tmp, 0,0);
        return res;
    }
};
```